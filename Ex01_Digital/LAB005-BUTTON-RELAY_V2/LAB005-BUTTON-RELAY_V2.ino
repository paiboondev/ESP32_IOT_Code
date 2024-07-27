#define aBtn 0
#define bBtn 4
#define relay01 32
#define relay02 14
int state1 = 1;
int state2 = 1;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial Done!");
  pinMode(aBtn, INPUT);
  pinMode(bBtn, INPUT);
  pinMode(relay01, OUTPUT);
  pinMode(relay02, OUTPUT);
  digitalWrite(relay01, 1); 
  digitalWrite(relay02, 1);
  delay(500);
}

void loop() {
  delay(100); //100/500/1000
  if(digitalRead(aBtn) != 1) {
    state1 = !state1;
    Serial.println("State relay : " + String(state1));
    digitalWrite(relay01, state1); 
  }
  if(digitalRead(bBtn) != 1) {
    state2 = !state2;
    Serial.println("State relay : " + String(state2));
    digitalWrite(relay02, state2); 
  }
}
