char command;

int redLED = 6;
int greenLED = 7;
int blueLED = 8;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Serial.begin(9600);  // HC-05 default baud rate
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {

      case 'R':   // Red ON
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'G':   // Green ON
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        break;

      case 'B':   // Blue ON
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        break;

      case 'X':   // All OFF
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        break;

      case 'F':   // Flash all LEDs 5 times
        for (int i = 0; i < 5; i++) {
          digitalWrite(redLED, HIGH);
          digitalWrite(greenLED, HIGH);
          digitalWrite(blueLED, HIGH);
          delay(300);

          digitalWrite(redLED, LOW);
          digitalWrite(greenLED, LOW);
          digitalWrite(blueLED, LOW);
          delay(300);
        }
        break;
    }
  }
}
