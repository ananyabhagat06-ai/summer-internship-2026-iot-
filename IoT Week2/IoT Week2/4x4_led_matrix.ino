int rows[] = {2, 3, 4, 5};
int cols[] = {6, 7, 8, 9};
void setup() {
  for(int i=0; i<4; i++){
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}
void loop() {
  for(int r=0; r<4; r++){
    for(int c=0; c<4; c++){
      for(int i = 0; i < 4; i++){
      digitalWrite(rows[r], HIGH);
      digitalWrite(cols[c], LOW);
      }
      digitalWrite(rows[r], LOW);
      digitalWrite(cols[c], HIGH);
      delay(1000);
    }
  }
}
