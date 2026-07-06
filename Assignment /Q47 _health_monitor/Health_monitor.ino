/*
   Question 47 - Heart Rate & SpO2 Monitor
   Summer School IoT Assignment
*/

#define LDR_PIN 34
#define ALERT_LED 18

int samples[5];
int sampleIndex = 0;

// Rolling average function
int getAverage(int value){

  samples[sampleIndex] = value;

  sampleIndex++;

  if(sampleIndex >= 5)
    sampleIndex = 0;

  long total = 0;

  for(int i=0;i<5;i++)
    total += samples[i];

  return total / 5;

}

void setup(){

  Serial.begin(115200);

  pinMode(ALERT_LED,OUTPUT);

  // Initialize sample array
  for(int i=0;i<5;i++)
    samples[i]=2000;

  Serial.println("Heart Rate & SpO2 Monitor Started");
  Serial.println("HR,SpO2");

}

void loop(){

  int raw = analogRead(LDR_PIN);

  int average = getAverage(raw);

  // Simulated values
  int heartRate = map(average,0,4095,45,130);

  int spo2 = map(average,0,4095,90,100);

  Serial.print("Heart Rate : ");
  Serial.print(heartRate);
  Serial.println(" bpm");

  Serial.print("SpO2 : ");
  Serial.print(spo2);
  Serial.println("%");

  if(heartRate < 50 || heartRate > 120 || spo2 < 94){

      digitalWrite(ALERT_LED,HIGH);

      Serial.println("ALERT : Abnormal Reading");

  }

  else{

      digitalWrite(ALERT_LED,LOW);

      Serial.println("Patient Stable");

  }

  Serial.println("---------------------");

  delay(2000);

}
