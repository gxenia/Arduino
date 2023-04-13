const int d_pin = 13;
const int a_pin = 1;
int pot_value = 0;
int led_delay = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(d_pin, OUTPUT);
  pinMode(a_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_value = analogRead(a_pin);
  led_delay = map(pot_value, 0, 1024, 0, 2000);
  Serial.print(led_delay);

  digitalWrite(d_pin, HIGH);
  delay(led_delay);
  digitalWrite(d_pin, LOW);
  delay(led_delay);


}
