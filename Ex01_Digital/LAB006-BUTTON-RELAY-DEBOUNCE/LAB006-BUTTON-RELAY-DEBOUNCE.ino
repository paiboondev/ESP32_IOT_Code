/* Debounce */
#define aBtn 0
#define relay01 32

int buttonState = HIGH;               // the current reading from the input pin
int lastButtonState = HIGH;           // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int relayState = 1;

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
  int reading = digitalRead(aBtn);
  
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();        // reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the Relay if the new button state is LOW
      if (buttonState == LOW) {
        relayState = !relayState;
        Serial.println("State relay : " + String(relayState));
      }
    }
  }

  // set the Relay:
  digitalWrite(relay01, relayState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
