#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

String mode = "";  // Variable to store the selected mode

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter mode: color_gradient, breathing, strobe, chasing, rainbow, disco, fire_flicker, colors, or temp");
}

void loop() {
  if (Serial.available()) {
    mode = Serial.readStringUntil('\n');
    mode.trim(); // Remove any extra spaces or newline characters

    Serial.print("Selected mode: ");
    Serial.println(mode);

    if (mode == "color_gradient") {
      colorGradient(255, 0, 0, 0, 255, 0, 20);
    } 
    else if (mode == "breathing") {
      breathingEffect(255, 0, 0, 20);  // Red breathing effect
    }
    else if (mode == "strobe") {
      strobeEffect(5, 100);  // White strobe effect
    }
    else if (mode == "chasing") {
      chasingEffect(200);  // Chasing colors
    }
    else if (mode == "rainbow") {
      rainbowEffect(20);  // Rainbow color change
    }
    else if (mode == "disco") {
      discoMode(100);  // Random color changes (disco mode)
    }
    else if (mode == "fire_flicker") {
      fireFlickerEffect(50);  // Fire flicker effect
    }
    else if (mode == "colors") {
      userColor();  // Let user input custom colors
    }
    else if (mode == "temp") {
      temperatureToColor();  // Determine color based on star temperature
    } 
    else {
      Serial.println("Invalid mode, try again.");
    }
  }
}

// Color Gradient Effect
void colorGradient(int r1, int g1, int b1, int r2, int g2, int b2, int steps) {
  for(int i = 0; i < 8; i++) {
    for (int i = 0; i <= steps; i++) {
      int r = r1 + ((r2 - r1) * i) / steps;
      int g = g1 + ((g2 - g1) * i) / steps;
      int b = b1 + ((b2 - b1) * i) / steps;
      setColor(r, g, b);
      delay(50);
    }
  }
}

// Breathing Effect
void breathingEffect(int r, int g, int b, int delayTime) {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i <= 255; i += 3) {
      setColor(r * i / 255, g * i / 255, b * i / 255);
      delay(delayTime);
    }

    for (int i = 255; i >= 0; i--) {
      setColor(r * i / 255, g * i / 255, b * i / 255);
      delay(delayTime);
    }
  }
}

// Strobe Effect
void strobeEffect(int flashes, int delayTime) {
  for (int i = 0; i < flashes; i++) {
    setColor(255, 255, 255);
    delay(delayTime);
    setColor(0, 0, 0);
    delay(delayTime);
  }
}

// Chasing Effect
void chasingEffect(int delayTime) {
  for (int i = 0; i < 8; i++) {
    setColor(255, 0, 0);
    delay(delayTime);
    setColor(0, 255, 0);
    delay(delayTime);
    setColor(0, 0, 255);
    delay(delayTime);
  }
}

// Rainbow Effect
void rainbowEffect(int delayTime) {
  for (int i = 0; i < 256; i += 3) {
    setColor(255, i, 0);
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setColor(i, 255, 0);
    delay(delayTime);
  }
  for (int i = 0; i < 256; i++) {
    setColor(0, 255, i);
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setColor(0, i, 255);
    delay(delayTime);
  }
  for (int i = 0; i < 256; i++) {
    setColor(i, 0, 255);
    delay(delayTime);
  }
  for (int i = 255; i >= 0; i--) {
    setColor(255, 0, i);
    delay(delayTime);
  }
}

// Disco Mode
void discoMode(int delayTime) {
  for (int i = 0; i < 30; i++) {
    int r = random(0, 256);
    int g = random(0, 256);
    int b = random(0, 256);
    setColor(r, g, b);
    delay(delayTime);
  }
}

// Fire Flicker Effect
void fireFlickerEffect(int delayTime) {
  for (int i = 0; i < 30; i++) {
    int r = random(200, 255);
    int g = random(100, 150);
    int b = random(0, 50);
    setColor(r, g, b);
    delay(delayTime);
  }
}

// Star Temperature to Color
void temperatureToColor() {
  Serial.println("Enter surface temperature of the star in Kelvin:");

  while (Serial.available() == 0) {}

  int temp = Serial.parseInt();
  String color = "";

  if (temp >= 30000) {
    color = "Blue (Class O)";
    setColor(0, 0, 255);
  } else if (temp >= 10000) {
    color = "Blue-white (Class B)";
    setColor(135, 206, 235);
  } else if (temp >= 7500) {
    color = "White (Class A)";
    setColor(255, 255, 255);
  } else if (temp >= 6000) {
    color = "Yellow-white (Class F)";
    setColor(255, 255, 224);
  } else if (temp >= 5200) {
    color = "Yellow (Class G)";
    setColor(255, 255, 0);
  } else if (temp >= 3700) {
    color = "Orange (Class K)";
    setColor(255, 165, 0);
  } else if (temp >= 2400) {
    color = "Red (Class M)";
    setColor(255, 0, 0);
  } else {
    color = "Temperature too low or invalid.";
  }

  Serial.print("Star color: ");
  Serial.println(color);
}

// User Color Input
void userColor() {
  Serial.println("Enter a color name: red, green, blue, yellow, cyan, magenta, white, pink, brown, purple, violet, orange");

  while (Serial.available() == 0) {}

  String color = Serial.readStringUntil('\n');
  color.trim();

  if (color == "red") {
    setColor(255, 0, 0);
  } else if (color == "green") {
    setColor(0, 255, 0);
  } else if (color == "blue") {
    setColor(0, 0, 255);
  } else if (color == "yellow") {
    setColor(255, 255, 0);
  } else if (color == "cyan") {
    setColor(0, 255, 255);
  } else if (color == "magenta") {
    setColor(255, 0, 255);
  } else if (color == "white") {
    setColor(255, 255, 255);
  } else if (color == "pink") {
    setColor(255, 192, 203);
  } else if (color == "brown") {
    setColor(139, 69, 19);
  } else if (color == "purple") {
    setColor(128, 0, 128);
  } else if (color == "violet") {
    setColor(238, 130, 238);
  } else if (color == "orange") {
    setColor(255, 165, 0);
  } else {
    Serial.println("Given color is not available, try again.");
  }
}

// Set RGB LED Color for Common Anode
void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}
