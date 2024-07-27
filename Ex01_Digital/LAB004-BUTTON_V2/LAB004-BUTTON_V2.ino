#define aBtn 0
#define bBtn 4

#define LED_R 25
#define LED_G 26
#define LED_B 27

void setup() {
  pinMode(aBtn, INPUT);
  pinMode(bBtn, INPUT);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);

  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial Done!");
  delay(500);
}

void loop() {
  if (digitalRead(aBtn) == 0 and digitalRead(bBtn == 0)) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, LOW);
  }
  else if (digitalRead(aBtn) == 0 and digitalRead(bBtn == 1)) {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  }
  else if (digitalRead(aBtn) == 1 and digitalRead(bBtn == 0)) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, HIGH);
  } else {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_B, HIGH);
  }

  Serial.println("state_aBtn: [" + String(digitalRead(aBtn)) +
                 "], state_bBtn: [" + String(digitalRead(bBtn)) + "]");
  delay(1000);
}
