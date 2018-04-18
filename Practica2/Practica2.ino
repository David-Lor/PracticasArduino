#define LEN_LED 3
int LED_PIN[3] = {2,3,4};
const int DELAY = 300;

void setup() {
  for (int i=0; i<LEN_LED; i++) {
    pinMode(LED_PIN[i], OUTPUT);
    digitalWrite(LED_PIN[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i=0; i<LEN_LED; i++) {
    digitalWrite(LED_PIN[i], HIGH);
    Serial.print("Enciendo ");
    Serial.println(LED_PIN[i]);
    delay(DELAY);
    digitalWrite(LED_PIN[i], LOW);
    Serial.print("Apago ");
    Serial.println(LED_PIN[i]);
    delay(DELAY);
  }
}
