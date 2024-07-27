#define relay01 32
#define relay02 14

void setup() {
  pinMode(relay01, OUTPUT);
  pinMode(relay02, OUTPUT);
  
  digitalWrite(relay01, HIGH);  // Turn OFF
  digitalWrite(relay02, HIGH);  // Turn OFF
  delay(1000);
}

void loop() {
  digitalWrite(relay01, LOW);  // Turn ON
  digitalWrite(relay02, HIGH); // Turn OFF
  delay(2000);
  
  digitalWrite(relay01, HIGH); // Turn OFF
  digitalWrite(relay02, LOW);  // Turn ON
  delay(2000);

  digitalWrite(relay01, LOW);  // Turn ON
  digitalWrite(relay02, LOW);  // Turn ON
  delay(2000);

  digitalWrite(relay01, HIGH);  // Turn OFF
  digitalWrite(relay02, HIGH);  // Turn OFF
  delay(2000);
  
}
