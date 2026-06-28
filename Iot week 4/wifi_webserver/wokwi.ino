#include <DHTesp.h>

#define DHT_PIN 15
#define LED_PIN 2

DHTesp dht;
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  float temp = dht.getTemperature();
  float hum = dht.getHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C | Humidity: ");
  Serial.println(hum);

  // Simulate LED toggle every 5 sec
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);

  delay(3000);
}
