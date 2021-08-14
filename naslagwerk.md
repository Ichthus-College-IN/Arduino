# Arduino essentials 

**Inhoud**

* [Arduino IDE](#arduino-ide)
    * [Verbinden met de Arduino](#verbinden-met-de-arduino)
    * [De seriële monitor](#de-seriële-monitor)
* [De Arduino programmeren](#de-arduino-programmeren)
    * [#include<>](#include)
    * [Variabelen en objecten](#variabelen-en-objecten)
    * [void setup()](#void-setup())
    * [void loop()](#void-loop())
    * [Een compleet script](#een-compleet-script)
* [Een knipperend lampje](#een-knipperend-lampje)
* [Overzicht: operators](#overzicht-operators)
---

Arduino is hét startersplatform om met elektronica aan de gang te gaan. Het is
niet al te moeilijk, er zijn op het internet eindeloos veel voorbeelden te
vinden en ongeveer elke sensor op de markt is aan te sluiten en kost maar een
enkel eurootje in de meeste gevallen. Nadat je in de vorige periode geleerd hebt
wat programmeren is en hoe het werkt, gaan we het deze periode verder gebruiken
om werkende apparatuur te maken. Dit keer alleen niet in de taal Python, maar
in de taal C++. C++ is een stuk ouder (uit 1985, in tegenstelling tot Python uit
2002), en de ++ betekent dat het een verbetering van de nog oudere taal C 
(1972). Elke taal is (heel wat) anders dan de een ander, en dat betekent dat je
deze weken zult moeten wennen aan wat andere dingen. Daarnaast brengt de 
Arduino zelf ook wat specifieke functies met zich mee. Deze beide onderdelen
worden in dit naslagwerk belicht en uitgelegd met een paar voorbeelden.

Waarschuwing: C++ is vervelender om te programmeren: alles moet heel secuur
en precies. In Python kun je soms een beetje beunen, omdat de computer het wel
voor je uitzoekt. Maar in C++ moet je het zelf uitzoeken, zo gezegd. Op een
Arduino ook wel noodzakelijk: deze 'micro'-computer heeft 32 KB opslagruimte,
2 KB RAM en een single-core processor op een spectaculaire snelheid van 16 MHz.
Ter vergelijking: de computer waar je nu op werkt heeft 512 GB opslag, 16 GB
RAM en een hexa-core processor op een snelheid van 4.5 GHz.

## Arduino IDE

Op je computer staat het programma Arduino IDE. Hiermee zullen we de Arduino
programmeren. 

### Verbinden met de Arduino

Op de Arduino zit een USB-poort (type A, vooral gebruikt bij printers). Sluit
de kabel aan op een USB-poort op de computer (aan de zijkant). Kies vervolgens
in de IDE onder Tools > Port de COM waar *Arduino/Genuino Uno* achter staat. Dat
vormt de verbinding met de Arduino. Vervolgens staan linksbovenin een vinkje en een
pijltje: met het vinkje kun je controleren of je *sketch* (het is gebruikelijk om 
een stukje code op de Arduino een sketch te noemen) fouten bevat, en met het pijltje
kun je de sketch uploaden naar de Arduino. Je kunt ook in één keer het pijltje
gebruiken, dan wordt automatisch ook het vinkje uitgevoerd (*compilen* heet dat).

### De seriële monitor

Rechtsbovenin staat een vergrootglas: als je verbonden bent met de Arduino en
hierop klikt, open je de seriële monitor. Dit is de plek waar alle tekst geprint
wordt, net als in Spyder rechtsonderin de tekst geprint werd. Ook bij de Arduino
is het zeker zo handig om tekst te printen.

## De Arduino programmeren

We werken hier van boven naar onderin een standaard script langs, en benoemen
onderweg alle relevante zaken.

### #include<>

Waar je bij Python gewend bent om `import numpy` te gebruiken, gaat zoiets in C++
als volgt:

```cpp
#include<LiquidCrystal_I2C.h>
```

`.h` staat hier voor een *header*-bestand. Daarin staan alle functies die in dit
geval nodig zijn voor het aansturen van een Liquid Crystal Display (LCD).

### Variabelen en objecten

Waar je in Python vrolijk op elk moment een variabele tevoorschijn kunt toveren,
of zelfs eentje meerdere keren voor verschillende dingen kunt gebruiken (ook al
hoort dat niet), moet je in C++ heel erg secuur zijn. Om een variabele met de
waarde 5 te maken, gebruik je hier

```cpp
int freq = 9600;
String lokaal = "B1.01";
```

Hier worden direct meerdere dingen zichtbaar: je moet het *type* specificeren van
je variabele. Bij Python heb je in de Variable Explorer wel eens gezien wat voor
datatype iets was, maar hoefde je daar praktisch niets mee te doen. Hier dus wel;
in DEZE paragraaf staan de mogelijke datatypen om variabelen mee te maken.
Daarnaast moet **aan het einde van elke regel een punt-komma!!!** Dit zul je
waarschijnlijk heel vaak vergeten, maar is noodzakelijk (helaas).

Er bestaan ook objecten; vaak zijn dat de sensoren of actuatoren waarmee je werkt.
Een voorbeeld hiervan is het LCD'tje waarvan we zojuist de library van ingevoegd
hebben. Een object maken van het LCD gaat als volgt:

```cpp
LiquidCrystal_I2C lcd(0x27,16,2);     // een LCD van 16 * 2 karakters
```

De naam `lcd` is hier de naam van het object, van het type `LiquidCrystal_I2C`.
`0x27` is het adres dat nodig is voor de Arduino om ermee te communiceren, en
`16` en `2` zijn het aantal kolommen en rijen van het display. We zien hier ook
hoe je comments maakt in C++: met twee slashes `//` (in tegenstelling tot de `#`
in Python).

### void setup()

Op het moment dat de Arduino stroom krijgt of opnieuw opstart, worden de variabelen
en objecten in het geheugen gezet; die zijn gewoon zoals ze zijn. Maar sommige
dingen 'moeten iets doen', zoals het starten van een verbinding met de computer,
of het starten van de verbinding met een schermpje; of ze hoeven maar één keer te
gebeuren, zoals bijvoorbeeld het weergeven van een welkomsttekst. Daarvoor is
de setup. Een voorbeeld:

```cpp
void setup() {
  lcd.init();                         // start het display
  lcd.backlight();                    // zet de verlichting van het display aan
  Serial.begin(9600);                 // start de verbinding naar de computer
  Serial.print("Verbinding gestart"); // print tekst op de computer
}
```

`void` houdt in dat er gewoon wat gebeurt, voor nu niet zo interessant. De lege
haakjes in `setup()` geeft aan dat er geen variabelen nodig zijn (dat is altijd
zo bij de setup). Vervolgens nog een groot verschil met Python: daar gebruik je
de dubbele punt en een *indent* voor een functie, zoals

```python
def plot():
  plt.plot(x,y)
  plt.title("voorbeeld")
```

In C++ gebruik je accolades `{ }` zoals hierboven te zien is, en ben je vervolgens 
niet verplicht om een indent te gebruiken, maar het maakt het wel echt veel 
duidelijker, dus doe het maar wel.

`Serial.begin(9600)` is een standaard regel om tekst weer te kunnen geven in de
seriële monitor. `Serial.print()` is vervolgens de `print()` functie zoals je
kent vanuit Python. Let op: je kunt beter `Serial.println()` gebruiken, waarbij
de `ln` voor *line new* staat, wat betekent dat alles automatisch op de volgende
regel komt. Zonder `ln` komt alles achter elkaar staan zonder spatie of enter.

### void loop()

De Arduino is een computertje dat de hele tijd iets herhaalt, zoals bijvoorbeeld
het meten van de temperatuur, of weergeven van de tijd, of knipperen van lampjes.
Dit zetten we in de `loop()`. Omdat dit ook een functie is zetten we aan het begin
en einde een accolade. Een voorbeeld van een loop:

```cpp
void loop() {
  long tijd = millis();               // aantal milliseconden sinds opstarten
  Serial.println("Seconden sinds opstarten: ", tijd/1000);  // print tijd op computer
  lcd.clear();                        // gooi alle tekst op het LCD weg
  lcd.setCursor(0,0);                 // zet de cursor op het LCD op kolom 0 rij 0
  lcd.print("Lokaal:");               // print tekst op de eerste rij van het LCD
  lcd.setCursor(0,1);                 // zet cursor op het LCD op kolom 0 rij 1
  lcd.print(lokaal, tijd/1000);       // print variabelen op tweede rij van LCD
  delay(1000);                        // pauzeer voor 1000 milliseconden
}
```

Hier komen een aantal dingen aan bod. Het eerste is een nieuwe variabele: deze
geven we de waarde van het aantal milliseconden sinds het opstarten van de Arduino.
Aangezien dat een groot getal kan worden na een paar uren of dagen geven we die
het type `long` (standaard gebruik). Vervolgens printen we een stukje tekst en
de tijd in seconden op de seriële monitor. Daarna zetten we de tekst ook op het
LCD, al moeten we eerst de bestaande tekst weggooien; het LCD is niet zo slim dat
hij het zelf doet. Je moet hier echt alles 'zelf doen'.

### Een compleet script

De vier bovenstaande onderdelen samen vormen een volledig script waarmee je een
LCD kunt aansturen. In het geheel ziet dat er dus zo uit:

```cpp
#include<LiquidCrystal_I2C.h>

int freq = 9600;
String lokaal = "B1.01";

LiquidCrystal_I2C lcd(0x27,16,2);     // een LCD van 16 * 2 karakters

void setup() {
  lcd.init();                         // start het display
  lcd.backlight();                    // zet de verlichting van het display aan
  Serial.begin(freq);                 // start de verbinding naar de computer
  Serial.print("Verbinding gestart"); // print tekst op de computer
}

void loop() {
  long tijd = millis();               // aantal milliseconden sinds opstarten
  Serial.println("Seconden sinds opstarten: ", tijd/1000);  // print tijd op computer
  lcd.clear();                        // gooi alle tekst op het LCD weg
  lcd.setCursor(0,0);                 // zet de cursor op het LCD op kolom 0 rij 0
  lcd.print("Lokaal:");               // print tekst op de eerste rij van het LCD
  lcd.setCursor(0,1);                 // zet cursor op het LCD op kolom 0 rij 1
  lcd.print(lokaal, tijd/1000);       // print een variabele op tweede rij van LCD
  delay(1000);                        // pauzeer voor 1000 milliseconden
}
```

---

## Een knipperend lampje

```cpp
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
```

Deze sketch laat een lampje knipperen, aangesloten op pin 8. Een pin op de
Arduino kan niet tegelijkertijd als input en output dienen, dus moet in de
setup aangegeven worden dat hier een output gebruikt wordt: er moet stroom
naar het lampje toe. Als je bijvoorbeeld een drukknop gebruikt, wil je meten
wat er binnenkomt, en zul je <kbd>INPUT</kbd> gebruiken in plaats van
<kbd>OUTPUT</kbd>. `digitalWrite` is een manier om *wel* of *geen* stroom
naar het lampje te sturen, in tegenstelling tot `analogWrite`, waarmee je
kunt kiezen voor een getal tussen 0 en 1024, en je dus veel beter kan kiezen
hoeveel stroom er naar het lampje gaat.

---

## Overzicht: operators

| Type   | Beschrijving                           | Voorbeeld                             |
|:-------|:---------------------------------------|:--------------------------------------|
|=       |Nieuwe waarde toewijzen                 |`int a = 4;                           `|
|==      |Waarde vergelijken                      |`a == 5;                // false      `|
|+       |Optellen                                |`int b = a + 4;         // b is 8     `|
|-       |Aftrekken                               |`int c = b – 1;         // c is 7     `|
|/       |Delen                                   |`int d = c / 0.5;       // d is 14    `|
|*       |Vermenigvuldigen                        |`int e = d * 3;         // e is 42    `|
|%       |Rest van een breuk bepalen              |`int rest = e % 20;     // rest is 2  `|
|pow(a,b)|Machtverheffen: a^b                     |`int macht = pow(c, 2); // 7^2 is 49  `|
|sqrt(a) |Worteltrekken (tweedemachts)            |`int wortel = sqrt(a);  // wortel is 2`|
|>, >=   |Groter dan, groter of gelijk aan        |`bool x != true;        // x is false `|
|<, <=   |Kleiner dan, kleiner of gelijk aan      |`if (c >= 0)                          `|
|! (not) |Tegenovergestelde maken                 |`if (d < 0)                           `|
|&& (and)|Beide zijn waar                         |`if (a > 0 && b < 5)                  `|
|&#124;&#124; (or) |Minstens een van beide is waar|<code>if (a > 0 &#124;&#124; b < 5)</code>|
