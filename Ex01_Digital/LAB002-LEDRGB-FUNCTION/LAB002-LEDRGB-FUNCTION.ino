#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  ctrLEDRGB(HIGH, HIGH, HIGH);
  delay(500);
}

void loop() {
  ctrLEDRGB(LOW, HIGH, HIGH);
  ctrLEDRGB(HIGH, LOW, HIGH);
  ctrLEDRGB(HIGH, HIGH, LOW);
}

void ctrLEDRGB(int R, int G, int B) {
  digitalWrite(RED_PIN, R);
  digitalWrite(GREEN_PIN, G);
  digitalWrite(BLUE_PIN, B);
  delay(1000);
}
