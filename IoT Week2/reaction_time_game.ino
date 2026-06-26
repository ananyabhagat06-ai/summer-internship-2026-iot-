int redLED = 8;
int yellowLED = 9;
int greenLED = 10;
int pushButtonPin = 2;
unsigned long startTime;
unsigned long reactionTime;
void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(pushButtonPin, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop() {
  Serial.println("Get Ready...");
  delay(2000);
  for (int i = 0; i < 10; i++) {
    int leds[] = {redLED, yellowLED, greenLED};
    int randIndex = random(0, 3);
    digitalWrite(leds[randIndex], HIGH);
    delay(random(200, 800));
    digitalWrite(leds[randIndex], LOW);
  }
  delay(random(100,200));
  digitalWrite(greenLED, HIGH);
  startTime = millis();
   while (digitalRead(pushButtonPin) == LOW);
  reactionTime = millis() - startTime;
  digitalWrite(greenLED, LOW);
  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");
  delay(3000);
}
