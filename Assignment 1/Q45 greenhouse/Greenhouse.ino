/*
   Question 45 - Smart Greenhouse Controller
   Summer School Assignment
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define LDR_PIN 34

#define HEATER 18
#define FAN 19
#define LIGHT 23

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN,DHTTYPE);

unsigned long previousMillis = 0;
int screen = 0;

void setup() {

  Serial.begin(115200);

  dht.begin();

  lcd.init();
  lcd.backlight();

  pinMode(HEATER,OUTPUT);
  pinMode(FAN,OUTPUT);
  pinMode(LIGHT,OUTPUT);

}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int lightValue = analogRead(LDR_PIN);

  // Heater control
  if(temp < 18){

    digitalWrite(HEATER,HIGH);

  }

  else{

    digitalWrite(HEATER,LOW);

  }

  // Fan control
  if(temp > 22){

    digitalWrite(FAN,HIGH);

  }

  else{

    digitalWrite(FAN,LOW);

  }

  // Grow light control
  if(lightValue < 1800){

    digitalWrite(LIGHT,HIGH);

  }

  else{

    digitalWrite(LIGHT,LOW);

  }

  // Change LCD screen every 3 seconds
  if(millis()-previousMillis > 3000){

      previousMillis = millis();

      screen++;

      if(screen>2)
      screen=0;

      lcd.clear();

      if(screen==0){

          lcd.print("Temp:");
          lcd.print(temp);
          lcd.print(" C");

      }

      if(screen==1){

          lcd.print("Humidity:");
          lcd.print(hum);
          lcd.print("%");

      }

      if(screen==2){

          lcd.print("Light:");
          lcd.print(lightValue);

      }

  }

}
