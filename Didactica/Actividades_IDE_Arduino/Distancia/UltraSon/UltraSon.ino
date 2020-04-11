/* 
 *  Programa para utilizar un medidor de distancias mediante ultrasonidos HC-SR04
 *  conectado a la entrada/salida IN "A4", como solo tiene un pin,
 *  une los pines Trigger y ECHO del HC-SR04 y conéctalos al IN.
 *  XDeSIG 2020
 */

#include "config_S.h" // Definición de todos los recursos de Echidna Shield "S" o White "W"



const float sonido = 34300.0; // Velocidad del sonido en cm/s

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
  
   // Obtenemos la distancia en cm, hay que convertir el tiempo en segudos ya que está en microsegundos
  // por eso se multiplica por 0.000001
  float distancia = tiempo * 0.000001 * sonido / 2.0;

// enviamos los datos vía serie
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
}
