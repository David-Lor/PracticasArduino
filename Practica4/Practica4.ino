#include <Servo.h>

Servo servo1;
const int SERVO_PIN = 9;

void setup()
{
	servo1.attach(SERVO_PIN) ;
}
void loop()
{
	for(int angulo = 0; angulo <= 180; angulo += 1) { //incrementa angulo 1 grado
		servo1.write(angulo);
		delay(25);
	}
	for(int angulo = 180; angulo >=0; angulo -=1) { //decrementa angulo 1 grado
		servo1.write(angulo);
		delay(25);
	}
}