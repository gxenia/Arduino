// pin a cui è collegato il buzzer
byte buzzerPin = 4;
int buzzerRitardo = 1000;      

void setup() {
  // inizializzazione pin a cui è collegto il buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  // buzzer ON
  digitalWrite(buzzerPin,HIGH);
  delay(buzzerRitardo);

  // buzzer OFF
  digitalWrite(buzzerPin,LOW);
  delay(buzzerRitardo);
}