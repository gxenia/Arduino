#include <toneAC.h>

const int red = 7;
const int blue = 6;
const int green = 5;
const int buzz = 4;

void setup() {
  Serial.begin(9600); // per inizializzare il monitor seriale
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzz, OUTPUT);
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
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    // toneAC(buzz, 400, 100); //pin - frequenza - durata
  }

  else if ((v >= 508 - range) && (v <= 508 + range)) {
    Serial.println("Bottone 2");
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
  }

  else if ((v >= 253 - range) && (v <= 253 + range)) {
    Serial.println("Bottone 3");
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
  }

  else {
    Serial.println("Non stai premendo nulla!");
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
  }

}
