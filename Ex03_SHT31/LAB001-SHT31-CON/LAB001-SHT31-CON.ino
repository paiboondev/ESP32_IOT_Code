#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  Serial.println("SHT31 test");
  
  if (! sht31.begin(0x44)) {    
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
  Serial.print("Temp : "); 
  Serial.print(t); 
  Serial.print(" °C ");
  if(t <= 28) {
    Serial.println("=> Cold!"); 
  }
  else if(t > 28 && t <= 29) {
    Serial.println("=> Warm!");  
  }
  else if(t > 29) {
    Serial.println("=> Hot!"); 
  }
  delay(1000);
}
