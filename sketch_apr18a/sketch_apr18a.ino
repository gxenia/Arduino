// Un bottone che accende e spegne un led permanentemente
// Funziona a metà

const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  ledState = digitalRead(ledPin);
  Serial.println(buttonState);

  if (buttonState == 1){ 
    if (ledState == 1) {
      digitalWrite(ledPin, 0); }
    else if (ledState == 0) {
      digitalWrite(ledPin, 1);n}
  }
}
