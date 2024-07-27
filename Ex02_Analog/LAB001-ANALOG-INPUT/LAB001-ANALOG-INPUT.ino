#define pinLDR 36

void setup() {
  Serial.begin(115200);
  delay(500);
  // analogReadResolution(10);
}

void loop() {
  int sensorValue = analogRead(pinLDR);
  Serial.print("ADC 12 bit = ");
  // Serial.print("ADC 10 bit = ");
  Serial.print(sensorValue);

  int percent = map(sensorValue,0,4095,-100,100);
  Serial.print(", Percent = "); 
  Serial.print(percent); 
  Serial.print(" %");
  
  float volts = 3.30 * (sensorValue / 4095.00); 
  // float volts = 3.30 * (sensorValue / 1023.00);
  Serial.print(", Voltage = "); 
  Serial.print(volts, 2); 
  Serial.println(" V");
  delay(500);
}
