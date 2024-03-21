// Example 2
// The user enters a number in the Serial Monitor
// The program checks if the number is even or odd.

int delta = 500; 
int userNumber = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() == 0) {
    // while the user has not entered any numbers 
    // do nothing 
  } 

  userNumber = Serial.parseInt(); // read user input as an integer 
  Serial.print(userNumber);
  if (userNumber%2 == 0) {
    Serial.println(" is even.");
  }
  else {
    Serial.println(" is odd.");
  }
  delay(delta);
}
