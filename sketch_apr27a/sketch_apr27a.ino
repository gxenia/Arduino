// SIMON SAYS - 27/04

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
  // Scelgo un valore random da 1 a 4
  int random = 1 + (rand() % 4);
  Serial.println(random);

  // Accendo il led in base al valore
  if (random == 1) {
    Serial.println("red");
    digitalWrite(led1, HIGH);

    tone(buzzer, 440);
    delay(20);
    noTone(buzzer);

    delay(1000);
    digitalWrite(led1, LOW);
  }

  else if (random == 2) {
    Serial.println("yellow");
    digitalWrite(led2, HIGH);

    tone(buzzer, 440);
    delay(20);
    noTone(buzzer);

    delay(1000);
    digitalWrite(led2, LOW);
  }

  else if (random == 3) {
    Serial.println("green");
    digitalWrite(led3, HIGH);

    tone(buzzer, 440);
    delay(20);
    noTone(buzzer);

    delay(1000);
    digitalWrite(led3, LOW);
  }

  else if (random == 4) {
    Serial.println("blue");
    digitalWrite(led4, HIGH);

    tone(buzzer, 440);
    delay(20);
    noTone(buzzer);

    delay(1000);
    digitalWrite(led4, LOW);
  }

}
