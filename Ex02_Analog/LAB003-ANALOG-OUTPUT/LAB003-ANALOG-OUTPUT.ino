#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27

#define LEDC_CHANNEL_0 0
#define LEDC_CHANNEL_1 1
#define LEDC_CHANNEL_2 2

#define LEDC_TIMER_BIT 8

#define LEDC_BASE_FREQ 5000

void setup() {
  //ledcSetup(channel, req, resolution_bits)
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcSetup(LEDC_CHANNEL_1, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
  ledcSetup(LEDC_CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_BIT);

  //ledcAttachPin(pin, channel)
  ledcAttachPin(RED_PIN, LEDC_CHANNEL_0);
  ledcAttachPin(GREEN_PIN, LEDC_CHANNEL_1);
  ledcAttachPin(BLUE_PIN, LEDC_CHANNEL_2);

  //ledcWrite(channel, duty) 
  ledcWrite(LEDC_CHANNEL_0, 255);  
  ledcWrite(LEDC_CHANNEL_1, 255);  
  ledcWrite(LEDC_CHANNEL_2, 255); 
}

void loop() {
  ctrLEDRGB(255, 0, 0); 
  ctrLEDRGB(0, 255, 0); 
  ctrLEDRGB(0, 0, 255); 
  ctrLEDRGB(255, 109, 0); 
  ctrLEDRGB(99, 76, 213); 

}

void ctrLEDRGB(int R, int G, int B) {
  // ledcWrite(channel, duty);
  ledcWrite(LEDC_CHANNEL_0, map(R, 255, 0, 0, 255));  
  ledcWrite(LEDC_CHANNEL_1, map(G, 255, 0, 0, 255));  
  ledcWrite(LEDC_CHANNEL_2, map(B, 255, 0, 0, 255)); 
  delay(1000);
}
