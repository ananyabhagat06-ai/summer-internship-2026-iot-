#define LDR_PIN A0
#define PIR_PIN 2
#define LED_PIN 9
int ldrThreshold = 500;

unsigned long motionStart = 0;
bool motionActive = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  int motion = digitalRead(PIR_PIN);

  unsigned long currentTime = millis();

  int seconds = currentTime / 1000;
  int minutes = seconds / 60;
  int hours = minutes / 60;

  seconds %= 60;
  minutes %= 60;

  // DAYTIME
  if (ldrValue > ldrThreshold) {
    analogWrite(LED_PIN, 0);

    Serial.print("[");
    printTime(hours, minutes, seconds);
    Serial.println("] EVENT: Daytime - Light OFF");

    delay(1000); // Tinkercad needs small delay
    return;
  }

  // NIGHT + MOTION
  if (motion == HIGH) {
    motionActive = true;
    motionStart = currentTime;

    analogWrite(LED_PIN, 255);

    Serial.print("[");
    printTime(hours, minutes, seconds);
    Serial.println("] EVENT: Motion detected - Full brightness");
  }

  // AFTER MOTION
  if (motionActive) {
    if (currentTime - motionStart <= 30000) {
      analogWrite(LED_PIN, 255);
    } else {
      analogWrite(LED_PIN, 51);

      Serial.print("[");
      printTime(hours, minutes, seconds);
      Serial.println("] EVENT: No motion - Dim light");

      motionActive = false;
    }
  }

  delay(200);
}

void printTime(int h, int m, int s) {
  if (h < 10) Serial.print("0");
  Serial.print(h); Serial.print(":");

  if (m < 10) Serial.print("0");
  Serial.print(m); Serial.print(":");

  if (s < 10) Serial.print("0");
  Serial.print(s);
}
