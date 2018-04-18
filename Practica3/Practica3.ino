#define LEN_LED 4
int LED_PIN[LEN_LED] = {2,3,4,5};
const int BUZZER_PIN = 6;
int BUZZER_TONE[LEN_LED] = {200, 300, 400, 500};
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
    tone(BUZZER_PIN, BUZZER_TONE[i]);
    delay(DELAY);
    digitalWrite(LED_PIN[i], LOW);
    notone(BUZZER_PIN);
    delay(DELAY);
  }
}
