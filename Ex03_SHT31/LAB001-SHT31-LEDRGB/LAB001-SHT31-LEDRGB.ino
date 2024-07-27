#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27

#define LEDC_CHANNEL_0 0
#define LEDC_CHANNEL_1 1
#define LEDC_CHANNEL_2 2

#define LEDC_TIMER_BIT 8
#define LEDC_BASE_FREQ 5000

Adafruit_SHT31 sht31 = Adafruit_SHT31();

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

  Serial.begin(115200);
  Serial.println("SHT31 test");

  if (! sht31.begin(0x44)) {    // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
}

void loop() {
  float t = sht31.readTemperature();
  if (isnan(t)) {    // check if 'is not a number'
    Serial.println("Failed to read from SHT31 sensor!");
    return;
  }
  Serial.print("Temp : "); Serial.print(t); Serial.print(" °C ");

  if (t <= 28) {
    ctrLEDRGB(0, 0, 255);
    Serial.println("=> Cold!");
  }
  else if (t > 28 && t <= 29) {
    ctrLEDRGB(255, 109, 0);
    Serial.println("=> Warm!");
  }
  else if (t > 29) {
    ctrLEDRGB(255, 0, 0);
    Serial.println("=> Hot!");
  }
  delay(1000);
}

void ctrLEDRGB(int R, int G, int B) {
  // ledcWrite(channel, duty);
  ledcWrite(LEDC_CHANNEL_0, map(R, 255, 0, 0, 255));
  ledcWrite(LEDC_CHANNEL_1, map(G, 255, 0, 0, 255));
  ledcWrite(LEDC_CHANNEL_2, map(B, 255, 0, 0, 255));
}
