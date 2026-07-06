/*
  Question 44 - PIR Based Security System

  Detects motion after working hours
  and activates alarms.
*/

#define PIR_PIN 34
#define POT_PIN 35

#define LED1 18
#define LED2 19
#define LED3 21

#define BUZZER 23

int startHour = 22;
int endHour = 6;

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.println("System Ready");
}

void loop() {

  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {

    Serial.println("Motion Detected");

    // Warning stage
    digitalWrite(LED1, HIGH);
    tone(BUZZER, 800);
    delay(500);

    // Alarm stage
    digitalWrite(LED2, HIGH);
    tone(BUZZER, 1200);
    delay(500);

    // Urgent stage
    digitalWrite(LED3, HIGH);
    tone(BUZZER, 1800);
    delay(500);

    Serial.println("Telegram Alert Sent");

  } else {

    noTone(BUZZER);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

  }

  delay(1000);
}
