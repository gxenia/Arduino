// SIMON SAYS - 27/04
#include <avr/wdt.h>

int n_led = 0;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
const int buzzer = 8;

// impostazioni di gioco con variabili che gestiscono il tempo tra un bip e l'altro, tra l'accensione di un led e l'altro

const int MIN_SPEED = 500; // durata del distacco massimo tra l'accensione di un led e un altro
const int MAX_SPEED = 1000; // durata del distacco massimo tra l'accensione di un led e un altro

const int LED_DELAY = 500; // quanto sta acceso il led
const int BUZZER_DELAY = 100; // quanto sta acceso il buzzer
const int BUZZER_FREQ = 500; // frequenza a cui suona il buzzer !DA MODIFICARE

const int BUTTON_DELAY = 1000; // per evitare possibili doppie letture 

int sequenza[15];
int seq_len = 0;
int seq_ind = 0;

bool gameover = false;
bool buttonPressed = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  if (gameover) {
    if (seq_len < sizeof(sequenza)) {
      generaSequenza();
      seq_len ++;
    }
    else {
      Serial.println("You won!");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    }
  }
  else (gameover == true) {
    Serial.println("You lost!");
    playDefeatMelody();
    resetFunc();
    
  }
  

  // Accendo i led in base al valore
  for (i = 0; i < seq_len; i++) {
    valore = sequenza[i];
    Accendi_led(valore);
  }
  
  // Aspetto e controllo ciò che invia l'utente
  



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
  int random = 1 + (rand() % 4);
  Serial.println(random);
  sequenza[seq_len] = random;
}

void playDefeatMelody() {
  // Melodia di sconfitta
  int melody[] = {NOTE_C4, NOTE_E3, NOTE_A3, NOTE_G3};

  // Durata delle note corrispondenti alla melodia
  int noteDurations[] = {4, 8, 8, 2};

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BUZZER_PIN, melody[i], noteDuration);
    delay(noteDuration);
    noTone(BUZZER_PIN);
    delay(50);
  }

}

void resetFunc() {
  wdt_enable(WDT_PERIOD_8KCLK_gc); // 8 ms watchdog 
  while(true); // infinite loop without feeding the dog, should reset in 8ms
}
