const int BUZZER_PIN = 33;
const int PWM_CHANNEL = 0; 

void setup() {
  ledcAttachPin(BUZZER_PIN, PWM_CHANNEL);
}

void loop() {
  for(int i=0; i<5; i++){
    ledcWriteNote(PWM_CHANNEL, NOTE_C, 4);
    delay(500);
    ledcWriteTone(PWM_CHANNEL, 800);
    delay(500);
  }

  ledcDetachPin(BUZZER_PIN);
  delay(1000);
  ledcAttachPin(BUZZER_PIN, PWM_CHANNEL);
 
  ledcWriteNote(PWM_CHANNEL, NOTE_C, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_D, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_E, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_F, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_G, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_A, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_B, 4);
  delay(500);
  ledcWriteNote(PWM_CHANNEL, NOTE_C, 5);
  delay(500);
}
