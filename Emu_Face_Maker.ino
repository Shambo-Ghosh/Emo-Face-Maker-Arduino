#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FluxGarage_RoboEyes.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

RoboEyes<Adafruit_SSD1306> roboEyes(display);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }
  display.clearDisplay();
  
  // Initialize: width, height, radius, space between eyes
  roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100);
  
  // Start with a calm face
  roboEyes.setAutoblinker(ON, 3, 2);
  roboEyes.setIdleMode(ON, 8, 4);   
}

void loop() {
  unsigned long currentMillis = millis();
  int cycle = (currentMillis / 5000) % 4; // Changes emotion every 5 seconds

  switch (cycle) {
    case 0: // NORMAL
      roboEyes.setMood(DEFAULT);
      roboEyes.setVFlicker(OFF); 
      break;

    case 1: // HAPPY / SMILING
      roboEyes.setMood(HAPPY);  
      break;

    case 2: // CRYING / SAD
      roboEyes.setMood(TIRED);  
      // We simulate crying by making the eyes "vibrate" just a little
      roboEyes.setVFlicker(ON, 2);
      break;

    case 3: // HEART EYES / EXCITED
      roboEyes.setMood(ANGRY);  
      roboEyes.setVFlicker(OFF);
      // This makes the eyes look "wide" and intense
      break;
  }

  roboEyes.update();
}