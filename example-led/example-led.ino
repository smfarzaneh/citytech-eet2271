int inputPin = 4;
int ledPin = 8;
int inputValue = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, HIGH); 
}

void loop() {
  inputValue = digitalRead(inputPin);
  if (inputValue == LOW) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
  Serial.println(inputValue);
  delay(100);
}
