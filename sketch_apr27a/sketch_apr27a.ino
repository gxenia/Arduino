// SIMON SAYS - 27/04
#include <avr/wdt.h>

int n_led = 0;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
const int buzzer = 8;

const int b1 = 9;
const int b2 = 10;
const int b3 = 11;
const int b4 = 12;

// impostazioni di gioco con variabili che gestiscono il tempo tra un bip e l'altro, tra l'accensione di un led e l'altro

const int MIN_SPEED = 500;   // durata del distacco massimo tra l'accensione di un led e un altro
const int MAX_SPEED = 1000;  // durata del distacco massimo tra l'accensione di un led e un altro

const int LED_DELAY = 500;     // quanto sta acceso il led
const int BUZZER_DELAY = 100;  // quanto sta acceso il buzzer
const int BUZZER_FREQ = 500;   // frequenza a cui suona il buzzer !DA MODIFICARE

const int BUTTON_DELAY = 1000;  // per evitare possibili doppie letture

int sequenza[15];
int seq_len = 0;
int seq_ind = 0;

bool gameover = false;
bool buttonPressed = false;
int pressed[15];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println(sizeof(sequenza));
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  playStartMelody();
}

void loop() {

  if (gameover == false) {
    Serial.println(seq_len);
    if (seq_len < sizeof(sequenza)) {
      generaSequenza();
      seq_len++;
    } else {
      Serial.println("You won!");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
  } else if (gameover == true) {
    Serial.println("You lost!");
    playDefeatMelody();
    resetFunc();
  }

  // Accendo i led in base al valore
  for (int i = 0; i < seq_len; i++) {
    Accendi_led(sequenza[i]);
  }

  seq_ind = 0;
  // Aspetto e controllo ciò che invia l'utente
  for (int i = 0; i < seq_len; i++) {
    buttonPressed = false;
    while (!isButtonPressed()) {;}
    Accendi_led(pressed[i]);
    if (pressed[i] != sequenza[i]) {
      gameover = true;
      break;
    }
    delay(500);
  }
}


void Accendi_led(int element) {
  if (element == 1) {
    Serial.println("red");
    digitalWrite(led1, HIGH);
    tone(buzzer, 440, 20);
    delay(1000);
    digitalWrite(led1, LOW);
  }

  else if (element == 2) {
    Serial.println("yellow");
    digitalWrite(led2, HIGH);
    tone(buzzer, 540, 20);
    delay(1000);
    digitalWrite(led2, LOW);
  }

  else if (element == 3) {
    Serial.println("green");
    digitalWrite(led3, HIGH);
    tone(buzzer, 640, 20);
    delay(1000);
    digitalWrite(led3, LOW);
  }

  else if (element == 4) {
    Serial.println("blue");
    digitalWrite(led4, HIGH);
    tone(buzzer, 740, 20);
    delay(1000);
    digitalWrite(led4, LOW);
  }
}


void generaSequenza() {
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  int r = random(1, 5);
  sequenza[seq_len] = r;
}

bool isButtonPressed() {

  if (digitalRead(b1) == LOW) {
    buttonPressed = true;
    pressed[seq_ind] = 1;
    seq_ind++;
  }

  else if (digitalRead(b2) == LOW) {
    buttonPressed = true;
    pressed[seq_ind] = 2;
    seq_ind++;
  }

  else if (digitalRead(b3) == LOW) {
    buttonPressed = true;
    pressed[seq_ind] = 3;
    seq_ind++;
  }

  else if (digitalRead(b4) == LOW) {
    buttonPressed = true;
    pressed[seq_ind] = 4;
    seq_ind++;
  }

  return buttonPressed;
}

void playStartMelody() {
  // Frequenze delle note musicali in Hz. Si possono trovare altri valori cercando "Frequencies of Musical Notes"
  int note_C4 = 262;
  int note_D4 = 294;
  int note_E4 = 330;
  int note_G4 = 392;

  // Melodia di avvio (C, D, E, G, E, D, C)
  int melody[] = {note_C4, note_D4, note_E4, note_G4, note_E4, note_D4, note_C4};

  // Durata delle note in millisecondi (quanto a lungo suona ogni nota)
  int noteDurations[] = {500, 500, 500, 500, 500, 500, 500};

  // Suona la melodia
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    tone(buzzer, melody[i], noteDurations[i]);
    delay(noteDurations[i] + 50); // Aspetta la durata della nota più un piccolo ritardo prima di passare alla prossima nota
    noTone(buzzer); // Ferma il suono del buzzer
  }
}

void playDefeatMelody() {
  // Melodia di sconfitta
  int melody[] = {262, 165, 220, 196};

  // Durata delle note corrispondenti alla melodia
  int noteDurations[] = {4, 8, 8, 2};

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(buzzer, melody[i], noteDuration);
    delay(noteDuration);
    noTone(buzzer);
    delay(50);
  }

}

void resetFunc() {
  wdt_enable(WDTO_2S);
  while(true);
}


