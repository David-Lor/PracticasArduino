#define LEN_LED 3
int LED_PIN[LEN_LED] = {2,3,4};
const int DELAY = 300;

void setup() {
  for (int i=0; i<LEN_LED; i++) {
    pinMode(LED_PIN[i], OUTPUT);
    digitalWrite(LED_PIN[i], LOW);
  }
}

void loop() {
  for (int i=0; i<LEN_LED; i++) {
    digitalWrite(LED_PIN[i], HIGH);
    delay(DELAY);
    digitalWrite(LED_PIN[i], LOW);
    delay(DELAY);
  }
}
