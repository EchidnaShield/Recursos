/* 
 *  Medir distancias mediante el módulo ultrasonidos HC-SR04
 *  conectado a la entrada/salida IO1 "D4", como solo tiene un pin,
 *  une los pines Trigger y ECHO del HC-SR04 y conéctalos al IO1.
 *+--------------------------------+
  |     _.-.,            _.-.,     |
  |    /     \          /     \    |
  |   |       |        |       |   |
  |   |       |  T  E  |       |   |
  |    \     /   r  c   \     /    |
  |     `'-'` +  g  h  - `'-'`     |
  |           |  |  |  |           |
  +-----------|--|--|--|-----------+
              |  |  |  |
              |  |  |  |
              |  ----  |
              |   |    |
              + UsPin  -
 *  XDeSIG 2020
 */

#include "config_B.h" // Definición de todos los recursos de Echidna Shield "config_S.h" Balck "config_B.h"o White "config_W.h"

#define UsPin IO1     // Ultrasonido <->  IO1 = D4

/* Velocidad del sonido en cm/s
 * Este valor depende de la presión atmosferica, 
 * Temperatura y humedad.
 * 34320 cm/s a 1Atm a 20ºC y 50%RH
 */
const float sonido = 34320.0; 

void setup() {
  // Inicia el monitor serie
  Serial.begin(9600);
}

void loop() {
  pinMode (UsPin, OUTPUT); //Define el pin como salida "Trigger" 
  digitalWrite(UsPin, LOW); //Trigger en estado bajo y espera 2 ms
  delayMicroseconds(2); 
  digitalWrite(UsPin, HIGH);//Trigger a estado alto y espera 10 ms
  delayMicroseconds(10);
  digitalWrite(UsPin, LOW);   //Trigger en estado bajo.

  pinMode (UsPin, INPUT); //Define el pin como entrada esperando el ECHO
  
  //  La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso LOW a HIGH
  unsigned long tiempo = pulseIn(UsPin, HIGH,170000);
  
   // Obtenemos la distancia en cm,el tiempo lo tenemos en microsegundos lo pasaremos a segundos (1E-6 = 0.000001)
  
  int distancia = tiempo*1E-6*sonido /2;
  //float distancia = tiempo*1E-6*sonido /2; // si lo queremos con 2 decimales

// enviamos los datos vía serie
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
