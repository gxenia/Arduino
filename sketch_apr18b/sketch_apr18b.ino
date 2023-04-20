// Due bottoni che accendono e spengono un led

int const b1 = 10;
int const b2 = 12;
int const pinLed = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(b1) == 1) {
    digitalWrite(pinLed, 0); //ACCENDI IL LED
  }
  if (digitalRead(b2) == 1) {
    digitalWrite(pinLed, 1); //SPEGNI IL LED
  }

}
