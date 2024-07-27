#define aBtn 0
#define bBtn 4

void setup() {
  pinMode(aBtn, INPUT);
  pinMode(bBtn, INPUT);
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Serial Done!");
  delay(500);
}

void loop() {
  /*
  Serial.print("state_aBtn: [");
  Serial.print(digitalRead(aBtn));
  Serial.print("], state_bBtn: [");
  Serial.print(digitalRead(bBtn));
  Serial.println("]");
  */
                 
  Serial.println("state_aBtn: ["+String(digitalRead(aBtn))+
                 "], state_bBtn: ["+String(digitalRead(bBtn))+"]");
  delay(1000);
}
