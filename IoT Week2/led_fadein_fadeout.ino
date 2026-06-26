int leds[] = {11, 10, 9, 6, 5};
int numLeds = 5;
void setup() {
  for(int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}
void loop() {
  for(int i = 0; i < numLeds; i++) {
    for(int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(leds[i], brightness);
      delay(5);
    }
    for(int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(leds[i], brightness);
      delay(5);
    }
  }
}
