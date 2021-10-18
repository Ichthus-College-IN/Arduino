int ledPin = 8;                       // een LED aangesloten op pin 8

void setup() {
  pinMode(ledPin, OUTPUT);            // zet pin 8 als output
}

void loop() {
  digitalWrite(ledPin, HIGH);         // zet het lampje aan
  delay(1000);                        // pauzeer voor 1000 milliseconden
  digitalWrite(ledPin, LOW);          // zet het lampje uit
  delay(1000);                        // pauzeer voor 1 seconde
}
