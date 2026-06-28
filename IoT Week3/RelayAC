#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22     // Change to DHT11 on real hardware

DHT dht(DHTPIN, DHTTYPE);

const int relayLED = 8;
const int button = 3;
bool relayState = false;
bool manualOverride = false;
bool lastButton = HIGH;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(relayLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);}

void loop() {
  float temp = dht.readTemperature();
  bool currentButton = digitalRead(button);

  if(lastButton==HIGH && currentButton==LOW){
    manualOverride = !manualOverride;
    relayState = !relayState;
    Serial.print("MANUAL OVERRIDE -> Relay ");

    if(relayState)
      Serial.println("ON");
    else
      Serial.println("OFF");
    delay(200);}

  lastButton = currentButton;

  if(!manualOverride)
    if(temp > 32){
      relayState = true;}

    else if(temp < 28){
      relayState = false;}}

  digitalWrite(relayLED, relayState);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C");
  Serial.print(" | Relay: ");

  if(relayState)
    Serial.println("ON");
  else
    Serial.println("OFF");

  delay(2000);}
