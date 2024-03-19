int potPin = A0;
int outputPin = 3; 
int inputLevel = 0;
int numInputLevels = 1024;
float refVoltage = 5.0; 
float analogVoltage = 0.0;
int numOutputLevels = 256;
int outputLevel = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  inputLevel = analogRead(potPin);
  analogVoltage = float(inputLevel)/float(numInputLevels)*refVoltage;
  outputLevel = analogVoltage/refVoltage*numOutputLevels;
  analogWrite(outputPin, outputLevel);
  Serial.print(" A0 Voltage = ");
  Serial.print(analogVoltage);
  Serial.print(" V, Pin 3 level = "); 
  Serial.println(outputLevel);
  delay(500);
}
