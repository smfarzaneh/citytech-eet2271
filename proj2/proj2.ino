#include "SevSeg.h"
SevSeg sevseg;

unsigned long timer = 0; 
const long interval = 1000;
bool is_temp_shown = false; 

int temperature = 32;
int humidity = 60;


void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis > timer + interval) {
    if (is_temp_shown) {
      sevseg.setNumber(humidity * 10, 0);
      sevseg.setSegmentsDigit(3, 0b01110110);
      is_temp_shown = false;
      timer = millis();
    }
    else {
      sevseg.setNumber(temperature * 10, 0);
      sevseg.setSegmentsDigit(3, 0b01110001);
      is_temp_shown = true; 
      timer = millis();
    }
  }
  sevseg.refreshDisplay();
}
