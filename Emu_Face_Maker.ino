#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUZZER_PIN 3 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
RoboEyes<Adafruit_SSD1306> roboEyes(display);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 80); 
  roboEyes.setAutoblinker(ON, 3, 2);
  roboEyes.setIdleMode(ON, 5, 2);   
}

void loop() {
  unsigned long currentMillis = millis();
  int cycle = (currentMillis / 6000) % 4; 

  // --- PROCEDURAL VOICE SYNTHESIS ---
  // We use math to create a "smooth" frequency that never stops
  float modulation;
  int finalFrequency;

  switch (cycle) {
    case 0: // NORMAL: Slow, calm breathing hum
      roboEyes.setMood(DEFAULT);
      modulation = sin(currentMillis * 0.003); // Slow wave
      finalFrequency = 1800 + (modulation * 150); // Small smooth slide
      break;

    case 1: // HAPPY: Fast, excited "warble"
      roboEyes.setMood(HAPPY);
      modulation = sin(currentMillis * 0.015); // Fast wave
      finalFrequency = 2500 + (modulation * 600); // Big smooth slide
      break;

    case 2: // SAD: Low, heavy "sobbing" vibration
      roboEyes.setMood(TIRED);
      modulation = sin(currentMillis * 0.002); 
      finalFrequency = 500 + (modulation * 50); // Low and heavy
      break;

    case 3: // EXCITED: Chaotic digital "processing"
      roboEyes.setMood(ANGRY);
      // Rapidly jumping but smooth transitions
      finalFrequency = 3000 + (random(-500, 500));
      break;
  }

  // Continuous sound output (Zero delays = No lagging)
  tone(BUZZER_PIN, finalFrequency);

  // Update animations
  roboEyes.update();
}