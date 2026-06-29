/*
  Project: Ultrasonic Parking Sensor
  Author: Ananaya bhagat
  IIT Jammu Summer School 2026

  Detects distance using HC-SR04 and alerts the driver
  using LEDs and a buzzer.
*/

const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int buzzer = 5;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  long duration;
  float distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // SAFE
  if (distance > 50) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    noTone(buzzer);

    Serial.println("SAFE");
  }

  // WARNING
  else if (distance > 20) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(400);

    Serial.println("WARNING");
  }

  // DANGER
  else if (distance >= 10) {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1200);
    delay(100);
    noTone(buzzer);
    delay(100);

    Serial.println("DANGER");
  }

  // STOP
  else {

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1500);

    Serial.println("STOP");
  }

  delay(100);
}
