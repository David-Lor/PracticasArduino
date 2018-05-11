
#define TIEMPO_CLAP 1500 //Tiempo que debe pasar para procesar las palmadas detectadas (1.5seg)

//Pinout
const int pinMicro = 6;
const int pinLed[4] = {2, 3, 4, 5};

//Variables globales
bool led[4] = {false, false, false, false}; //estados de los LEDs
unsigned int contador = 0; //contador de palmadas
unsigned long lastClap = 0; //instante de la última palmada

void setup() {
  Serial.begin(9600); //debug
  pinMode(pinMicro,INPUT); //inicializar micro input
  for (int i=0; i<4; i++) { //iterar todos los LED
    pinMode(pinLed[i], OUTPUT); //inicializar cada LED output
  }
}

void actuarLED() {
  if (contador > 1 && contador < 7) {
    if (contador == 6) { //6 palmadas: reiniciar todos los LED
      for (int i=0; i<4; i++) {
        digitalWrite(pinLed[i], LOW);
        led[i] = false;
      }
    } else { //2~5 palmadas: cambiar estado de un sólo LED
      int ledIndex = contador - 2;
      bool ledNow = !led[ledIndex];
      digitalWrite(pinLed[ledIndex], ledNow);
      led[ledIndex] = ledNow;
      Serial.print("LED #"); //debug
      Serial.print(ledIndex); //debug
      Serial.print(" -> "); //debug
      Serial.println(ledNow); //debug
    }
  }
  contador = 0; //reiniciar contador
}

void loop() {

  unsigned long currentMillis = millis();
  
  if (digitalRead(pinMicro)) { //palmada detectada
    lastClap = currentMillis; //guardar tiempo última palmada
    contador++; //actualizar contador
    Serial.print("Contador: "); //debug
    Serial.println(contador); //debug
    delay(200);
  }

  if (currentMillis - lastClap >= TIEMPO_CLAP) {
    actuarLED();
  }

}
