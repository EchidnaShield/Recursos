/* 
 *  Medir distancias mediante el módulo ultrasonidos HC-SR04
 *  conectado a la entrada/salida IN "A4", como solo tiene un pin,
 *  une los pines Trigger y ECHO del HC-SR04 y conéctalos al IN.
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
              +   IN   -
 *  XDeSIG 2020
 */

#include "config_S.h" // Definición de todos los recursos de Echidna Shield "S" o White "W"


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
  pinMode (IN, OUTPUT); //Define el pin como salida "Trigger" 
  digitalWrite(IN, LOW); //Trigger en estado bajo y espera 2 ms
  delayMicroseconds(2); 
  digitalWrite(IN, HIGH);//Trigger a estado alto y espera 10 ms
  delayMicroseconds(10);
  digitalWrite(IN, LOW);   //Trigger en estado bajo.

  pinMode (IN, INPUT); //Define el pin como entrada esperando el ECHO
  
  //  La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso LOW a HIGH
  unsigned long tiempo = pulseIn(IN, HIGH);
  
   // Obtenemos la distancia en cm,el tiempo lo tenemos en microsegundos lo pasaremos a segundos (1E-6 = 0.000001)
  
  int distancia = tiempo*1E-6*sonido /2;
  //float distancia = tiempo*1E-6*sonido /2; // si lo queremos con 2 decimales

// enviamos los datos vía serie
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
