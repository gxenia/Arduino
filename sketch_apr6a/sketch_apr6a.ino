const int red = 7;
const int blue = 6;
const int green = 5;
const int buzzer = 8;
int melody1[] = {262, 294, 330, 349, 392, 440, 494, 523};
int melody2[] = { 262, 220, 196, 165, 147, 131, 110, 98 };
int melody3[] = { 330, 277, 220, 330, 277, 220, 330, 277 };
int melody[] = { 440, 440, 440, 349, 523, 440, 349, 523, 440, 0, 659, 659, 659, 698, 523, 415, 440, 0, 440, 440, 440, 349, 523, 440, 349, 523, 440, 0, 659, 659, 659, 698, 523, 698, 659, 523 };
int noteDuration[] = { 500, 500, 500, 350, 150, 500, 350, 150, 1000, 500, 500, 500, 350, 150, 500, 350, 150, 1000, 500, 500, 500, 350, 150, 500, 350, 150, 1000, 500, 500, 500, 350, 150, 500, 350, 150, 1000 };

void setup() {
  Serial.begin(9600); // per inizializzare il monitor seriale
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

int range = 10;

void loop() {

  int v = analogRead(A0); // per leggere il pin
  // Serial.println(v);

  if ((v >= 764 - range) && (v <= 764 + range)) {
    Serial.println("Bottone 1");
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    for (int i = 0; i < 8; i++) {
      tone(buzzer, melody1[i], 250);
      delay(250);
    }
    
  }

  else if ((v >= 508 - range) && (v <= 508 + range)) {
    Serial.println("Bottone 2");
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    for (int i = 0; i < 8; i++) {
      tone(buzzer, melody2[i], 300);
      delay(300);
    }
  }

  else if ((v >= 253 - range) && (v <= 253 + range)) {
    Serial.println("Bottone 3");
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    for (int i = 0; i < 35; i++) {
    if (melody[i] == 0) {
      noTone(buzzer);
    } else {
      tone(buzzer, melody[i], noteDuration[i]);
    }
    delay(noteDuration[i] * 1.30);  // aggiungi un piccolo ritardo tra le note per evitare che si sovrappongano
  }
  }

  else {
    Serial.println("Non stai premendo nulla!");
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
  }

}
