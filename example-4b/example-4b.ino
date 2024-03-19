int xPin = A0;
int yPin = A1;
int redPin = 5;
int greenPin = 6;
int bluePin = 3;
int yellowPin = 9;
int x = 0;
int y = 0;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  x = analogRead(xPin);
  y = analogRead(yPin);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(yellowPin, LOW);
  if (x >= 512 && y >= 512)
    digitalWrite(yellowPin, HIGH);
  else if (x >= 512 && y < 512)
    digitalWrite(greenPin, HIGH);
  else if (x < 512 && y >= 512)
    digitalWrite(redPin, HIGH);
  else 
    digitalWrite(bluePin, HIGH);
  Serial.print("x = ");
  Serial.print(x);
  Serial.print(", y = ");
  Serial.println(y);
  delay(100);
}
