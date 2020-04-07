/*
 * Programa para controlar la posición de un servo
 * en función de la posición del Joystick X
 *
 * Pin A0 Joystick X
 * Pin 8 Servomotor
 *
 * Diciembre de 2017
 * Jose Pujol
 * Basado en programa Knob IDE Arduino- Michal Rinott
 */

// libreria Servo
#include <Servo.h>  // incluye la libreria Servo
Servo myservo;  // crea el objeto myservo tipo servo

// constantes para conexion pines
const int joyXPin = A0;  // pin de conexion de joystick X
const int servoPin=4;   // pin de conexion de servo 

// variables que cambian
int joyXValue=0;    // almacenar el valor del potenciometro
int angle = 0;     // numero de grados de la posicion del servo

void setup()
{
  myservo.attach(servoPin);   // vincula el servo al pin digital 4
}

void loop()
{
  joyXValue = analogRead(joyXPin);   // lectura del potenciometro 0-1023
  angle = map(joyXValue, 0, 1023, 0, 180);   // convierte el potenciometro a valor angulo 0-180
  myservo.write(angle);   // posiciona el servo al angulo
  delay(15);  // tiempo de espera para que el servo alcance la posicion
}
