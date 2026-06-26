#define LED1 11
#define LED2 12
#define LED3 13
#define dly 500
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int LED = random(11,14);
  digitalWrite(LED, HIGH);
  if (LED == LED1) {
    Serial.println("LED 1 ON");
  }
  else if (LED == LED2) {
    Serial.println("LED 2 ON");
  }
  else {
    Serial.println("LED 3 ON");
  }
  delay(dly);
  digitalWrite(LED, LOW);
  delay(dly);
}
