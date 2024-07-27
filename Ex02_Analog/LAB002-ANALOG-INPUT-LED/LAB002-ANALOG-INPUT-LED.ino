#define pinLDR 36
#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27

void setup() {
  Serial.begin(115200);
  delay(500);
  // analogReadResolution(10);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  ctrLEDRGB(HIGH, HIGH, HIGH);
}

void loop() {
  int sensorValue = analogRead(pinLDR);
  int value100 = map(sensorValue, 0, 4095, 0, 100);
  delay(100);
  Serial.println("sensorValue: " + String(sensorValue) + 
                 ", value100: " + String(value100));
  if(value100 >= 0 && value100 < 35) {
    ctrLEDRGB(LOW, HIGH, HIGH);
  }
  else if(value100 >= 35 && value100 < 70) {
    ctrLEDRGB(HIGH, LOW, HIGH);
  }
  else {
    ctrLEDRGB(HIGH, HIGH, LOW);
  } 
}

void ctrLEDRGB(int R, int G, int B) {
  digitalWrite(RED_PIN, R);
  digitalWrite(GREEN_PIN, G);
  digitalWrite(BLUE_PIN, B);
}
