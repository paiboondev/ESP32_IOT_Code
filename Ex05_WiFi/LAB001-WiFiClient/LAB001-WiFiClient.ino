#include <WiFi.h>
#define BLUE_PIN 27
const char* ssid     = "AUTO_2.4GHz";
const char* password = "45556111";

void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  digitalWrite(BLUE_PIN, HIGH); 
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(BLUE_PIN, HIGH); 
    delay(1000);
    digitalWrite(BLUE_PIN, LOW); 
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(BLUE_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}
