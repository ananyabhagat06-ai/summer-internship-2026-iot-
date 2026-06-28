#include <DHTesp.h>

#define DHT_PIN 15   // You can use GPIO 15

DHTesp dht;

void setup() {
  Serial.begin(115200);
  dht.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  float temp = dht.getTemperature();
  float hum = dht.getHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C  |  Humidity: ");
  Serial.println(hum);

  delay(3000);
}
