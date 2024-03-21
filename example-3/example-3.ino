// Example 3
// This program reads the analog voltage on A0 input pin
// For testing: connect the A0 pin directly to the 3.3 V power supply pin

int delta = 500; 
float refVoltage = 5.0; // maximum voltage in analog/digital conversion 
int numLevels = 1024; // 1024 levels for a 10-bit analog/digital converter
int inputLevel = 0; // 0 corresponds to 0 V and 1023 corresponds to 5.0 V
float inputVoltage = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() { 
  inputLevel = analogRead(A0);
  inputVoltage = float(inputLevel)/float(numLevels)*refVoltage; // calculate the actual voltage 
  Serial.print("Vin = ");
  Serial.print(inputVoltage);
  Serial.println(" V"); // always mention physical units 
  delay(delta);
}
