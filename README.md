# 🤖 Interactive EMO-Style Social Robot Face

An advanced, highly reactive robot face project designed for a **0.96" SSD1306 I2C OLED** screen. This project moves away from static emojis to create a "living" companion using **Procedural Animation** and **Mathematical Sound Synthesis**.

## 🌟 Key Features
* **Procedural Eye Animations:** Eyes are drawn dynamically, allowing for smooth "squash and stretch" during blinks and emotional shifts.
* **Mathematical Voice Engine:** Uses Sine-Wave Frequency Modulation to create a smooth, continuous "human-robot" voice that never stutters.
* **Non-Blocking Performance:** 100% delay-free code ensures 60FPS animations and real-time audio processing without system lag.
* **Autonomous Personality:** The robot features an "Idle Mode" where it looks around and blinks naturally without user input.

---

## 🛠 Hardware Configuration



### Wiring Table
| Component | Pin Label | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **OLED** | VCC | 3.3V | Ensures screen longevity. |
| **OLED** | GND | GND | Common ground. |
| **OLED** | SCL | A5 | I2C Clock (Uno/Nano). |
| **OLED** | SDA | A4 | I2C Data (Uno/Nano). |
| **Buzzer** | Long (+) | D3 | PWM Pin for audio synthesis. |
| **Buzzer** | Short (-) | GND | Ground connection. |

---

## 🎭 Emotional States & Vocalizations

The robot cycles through four main moods, each with a unique "vocal vibration" generated in real-time:

1.  **Normal:** A calm, slow-breathing hum ($~1800Hz$).
2.  **Happy:** A fast, high-pitched excited warble ($~2500Hz$ to $3100Hz$).
3.  **Sad/Crying:** A low, heavy "sobbing" vibration with a slight vertical eye flicker ($~450Hz$ to $550Hz$).
4.  **Excited:** Rapid, chaotic digital "data processing" sounds ($~3000Hz$ to $4500Hz$).

---

## 🚀 Getting Started

### 1. Requirements
Install the following libraries via the Arduino Library Manager:
* **Adafruit SSD1306** & **Adafruit GFX**
* **FluxGarage_RoboEyes**

### 2. Installation
1.  Clone this repository.
2.  Open the `.ino` file in your Arduino IDE.
3.  Ensure your board is set to **Arduino Nano** or **Uno**.
4.  Upload and watch your robot come to life!

### 3. Pro-Tip for "Cute" Sound
Small buzzers can be sharp. For the best "Companion" sound, place a small piece of **electrical tape** over the buzzer's hole to muffle harsh frequencies and create a smoother tone.

---

---
*Inspired by social robots like EMO and Cozmo.*
