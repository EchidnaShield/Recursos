/* 
 *  Medida de distancias de 10 a 80cm,  mediante Sharp 0A41SK, la respuesta no es lineal
 *  Tenemos que modelizar la longitud medida usando la librería de Giuseppe Masino "qub1750ul"
 *  https://github.com/qub1750ul/Arduino_SharpIR
 *  conectado a la entrada/salida IN "A4"
 *  XDeSIG 2020
 */

#include "config_B.h" // Definición de todos los recursos de Echidna Shield "S" o Black "B"

#include <SharpIR.h> // Importamos la librería de modelización de medida 

// crea una nueva instancia llamando a la librería y asignando sensor al modelo GP2Y0A41SK0F conectado en la entrada IN
SharpIR sensor( SharpIR::GP2Y0A41SK0F, IN );

void setup() {
  // Comunicación serie a 9600 baudios
  Serial.begin(9600);
  }

void loop() {
  
  int cm=distancia(20); //Llamada a la función de lectura de distancia con 20 interacciones
  
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(1000);
}

// Función de lectura de distancia
float distancia(int n)
{
  int suma=0;                     
  for(int i=0;i<n;i++)
  {
    suma=suma+sensor.getDistance(); //mide la distancia y la acumula "n" veces
  }  
  int media=(suma/n)+2;           // Realiza la media
  return(media);
}
