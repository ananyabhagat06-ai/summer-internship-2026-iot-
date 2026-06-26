#define LED1 11
#define LED2 12
#define LED3 13
#define dly 500
void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}
void loop() {
int LED = random(11,14);
digitalWrite(LED,HIGH);
delay(dly);
digitalWrite(LED, LOW);
delay(dly);
}
