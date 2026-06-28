#include <WiFi.h>
#include <WebServer.h>
#include <DHTesp.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WebServer server(80);

#define DHT_PIN 15
DHTesp dht;

#define LED_PIN 2
bool ledState = false;

unsigned long startTime;

void handleRoot() {
  float temp = dht.getTemperature();
  float hum = dht.getHumidity();
  unsigned long uptime = (millis() - startTime) / 1000;

  String html = "<!DOCTYPE html><html>";
  html += "<head><meta http-equiv='refresh' content='10'></head><body>";

  html += "<h2>Wi-Fi Temperature Monitor</h2>";
  html += "<p>Temperature: " + String(temp) + " °C</p>";
  html += "<p>Humidity: " + String(hum) + " %</p>";
  html += "<p>Uptime: " + String(uptime) + " seconds</p>";

  html += "<form action='/toggle'>";
  html += "<button type='submit'>Toggle LED</button>";
  html += "</form>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleToggle() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.setup(DHT_PIN, DHTesp::DHT11);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  startTime = millis();

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);

  server.begin();
}

void loop() {
  server.handleClient();
}
