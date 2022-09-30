/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
   Adaptado a EchidnaBlack
*/

#include <Servo.h> //librería de control do servo

Servo myservo; //creamos o obxecto myservo para controlar o servo

#define Joy_X A0 //pin conectado o eixo X do Joystick
int val; //variable para almacenar o valor de lectura do Joystick

void setup() {
 myservo.attach(4); //conectamos o pin 4 o obxecto myservo
}
void loop() {
 val = analogRead(Joy_X); //leemos o potenciómetro do Joystick (X)
 val = map(val, 0, 1023, 0, 179); //escala os valores de entrada
 myservo.write(val); //envía a posición do Servo
 delay(15); //unha espera para que o servo chegue a posición
}
