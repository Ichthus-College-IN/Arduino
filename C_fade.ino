int ledPin = 9;                     // een LED aangesloten op pin 9

void setup() {
  pinMode(ledPin, OUTPUT);          // zet pin 9 als output
}

void loop() {
  // fade in van min tot max in stappen van 5:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue); // waarde naar de LED sturen
    delay(30);                      // 30 milliseconden wachten
  }
  // fade out van max tot min in stappen van 5:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue); // waarde naar de LED sturen
    delay(30);                      // 30 milliseconden wachten
  }
}
