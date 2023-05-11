// Un bottone che accende e spegne un led permanentemente
// Funziona a metà

const int buttonPin = 2;
const int ledPin = 8;
int buttonStatePremuto = LOW;
int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  // digitalWrite(ledPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  // ledState = digitalRead(ledPin);
  // Serial.println(buttonState);

  if (buttonState == HIGH && buttonStatePremuto == LOW){
    Serial.println("Hello");
    ledState = !ledState;
    delay(50);
  }

  digitalWrite(ledPin, ledState);
  buttonStatePremuto = buttonState;

  if (buttonState == HIGH && buttonStatePremuto == HIGH) {
    delay(500);
  }


}
