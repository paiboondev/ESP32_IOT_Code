#define aBtn 0
#define relay01 32
int state = 1;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial Done!");
  pinMode(aBtn, INPUT);
  pinMode(relay01, OUTPUT);
  digitalWrite(relay01, 1); 
  delay(500);
}

void loop() {
  delay(100); //100/500/1000
  if(digitalRead(aBtn) != 1) {
    state = !state;
    Serial.println("State relay : " + String(state));
    digitalWrite(relay01, state); 
  }
}
