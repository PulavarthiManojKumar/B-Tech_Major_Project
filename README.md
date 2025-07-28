# Creating Multi-Colored Light Using Arduino UNO

This project uses an Arduino UNO and a Common Anode RGB LED to produce a variety of lighting effects through PWM control. The program simulates real-world lighting scenarios including color fading, breathing lights, rainbow transitions, and interactive user input via the Serial Monitor.

---

## 📌 Features

- Color Gradient Effect (Smooth transitions across spectrum)
- Breathing Effect (Slow pulse-like fading)
- Strobe Light Effect (Quick on/off flashes)
- Chasing RGB Effect (R-G-B loop effect)
- Rainbow Color Loop
- Disco Mode (Rapid color changes)
- Fire Flicker Simulation
- User-defined RGB color entry via Serial

---

## 🧰 Components Used

- Arduino UNO
- Common Anode RGB LED
- Resistors (220 ohm)
- Breadboard & Jumper Wires
- USB Cable (for Arduino)

---

## 🔧 How to Use

1. Connect the Common Anode RGB LED as per schematic:
   - RED → PWM Pin (e.g., 9)
   - GREEN → PWM Pin (e.g., 10)
   - BLUE → PWM Pin (e.g., 11)
   - Common Anode → 5V

2. Upload the sketch: `sketch_apr8a.ino` using Arduino IDE

3. Open **Serial Monitor** (9600 baud) and enter numbers to switch between effects:
1 → Color Gradient
2 → Breathing
3 → Strobe
4 → Chasing RGB
5 → Rainbow
6 → Disco
7 → Fire Flicker
8 → Enter Custom Color (R G B)

4. For Custom Mode, input 3 values between 0–255 separated by space.
Example: 255 100 50

---

## 🧠 Learning Outcomes

- Understanding of RGB LED control with PWM
- Practical Arduino C++ coding
- Working with Serial Communication
- Visualizing physical color blending and scientific color models

---

## 📷 Screenshots / Demo

*(Include photos or short videos of LED effects if available)*

---

## 📃 Project Info

**Team**:  
- Pulavarthi Manoj Kumar  
- Pothuganti Yugeshwar  
- Nalla Abhinav  

**Institution**: MRCET – Department of CSE  
**Guide**: Ms. R. Sujatha (Assistant Professor)

---

## 📖 License

This project is for educational use. Contact authors for reuse in commercial applications.
