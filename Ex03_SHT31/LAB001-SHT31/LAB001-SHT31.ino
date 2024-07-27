#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  Serial.println("SHT31 test");
  
  if (! sht31.begin(0x44)) { // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
}

void loop() {
  float t = sht31.readTemperature();
  float h = sht31.readHumidity();
  if (isnan(t)) {    // check if 'is not a number'
    Serial.println("Failed to read from SHT31 sensor!");
    return;
  } 
  Serial.print("Temperature : "); 
  Serial.print(t); 
  Serial.print(" °C ,");
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.println(" %");
  delay(1000);
}
