const int buttonPin = 2;      // een button aangesloten op pin 2 (constant)
const int ledPin =  13;       // een led aangesloten op pin 13 (constant)

int buttonState = 0;          // variabele om de status van de knop in op te slaan (wisselend)
int ledState = 0;             // variabele om de status van het lampje in op te slaan (wisselend)

void setup() {
  pinMode(ledPin, OUTPUT);    // zet pin 13 als output
  pinMode(buttonPin, INPUT);  // en pin 2 als input
}

void loop() {
  buttonState = digitalRead(buttonPin); // status van de knop uitlezen

  if (buttonState == HIGH) {            // wachten tot de knop wordt ingedrukt
    ledState != ledState;               // status van het lampje switchen (is ongelijk aan)
    digitalWrite(ledPin, ledState);     // status van het lampje schrijven
    
    while (buttonState == HIGH) {       // en wachten tot de knop wordt losgelaten
      buttonState = digitalRead(buttonPin);
    }
    delay(200);                         // tijd geven om stroom weg te laten lopen zodra de knop losgelaten wordt
  } 
}
