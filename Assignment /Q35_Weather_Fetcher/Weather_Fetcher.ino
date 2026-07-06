#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

// DHT11 is connected to GPIO 4
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);

  // Starting the DHT sensor
  dht.begin();

  // Connecting ESP32 to WiFi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected Successfully!");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    // Building the weather API URL
    String url =
    "http://api.openweathermap.org/data/2.5/weather?q=" +
    city + "," + country +
    "&appid=" + apiKey +
    "&units=metric";

    http.begin(url);

    int httpCode = http.GET();

    if (httpCode == 200) {

      // Reading the JSON response
      String payload = http.getString();

      DynamicJsonDocument doc(2048);

      deserializeJson(doc, payload);

      String cityName = doc["name"];

      float apiTemp = doc["main"]["temp"];

      int apiHumidity = doc["main"]["humidity"];

      String weather = doc["weather"][0]["description"];

      // Taking local sensor readings
      float localTemp = dht.readTemperature();
      float localHumidity = dht.readHumidity();

      Serial.println("------------------------");

      Serial.print("City : ");
      Serial.println(cityName);

      Serial.print("Weather : ");
      Serial.println(weather);

      Serial.print("API Temp : ");
      Serial.print(apiTemp);
      Serial.println(" C");

      Serial.print("Local Temp : ");
      Serial.print(localTemp);
      Serial.println(" C");

      Serial.print("API Humidity : ");
      Serial.print(apiHumidity);
      Serial.println("%");

      Serial.print("Local Humidity : ");
      Serial.print(localHumidity);
      Serial.println("%");

      // Difference between outdoor and indoor temperature
      Serial.print("Difference : ");
      Serial.print(abs(apiTemp - localTemp));
      Serial.println(" C");

      Serial.println("------------------------");

    } else {

      Serial.println("Couldn't fetch weather data.");

    }

    http.end();
  }

  // Updating every 10 seconds
  delay(10000);
}
