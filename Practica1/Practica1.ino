const int LED_PIN = 13;
const int DELAY = 300;

void setup() {
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY);
}
