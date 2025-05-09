/*
    Utiliza el microfóno y los LEDes rojO "L_Red", naranja "L_orn" y verde "L_Gre"
    para simular un semaforo que indique tres niveles de ruido en la entrada Mic,
    Usa una media de las medidas a modo de filtro
    La respuesta se puede mejorar aplicando filtro paso bajos, por ejemplo filtro EMA
    float EMA_ALPHA = 0,6;
    int EMA_PB = 0;
    
    int EMAPasoBajo(int sinal)
    {
   EMA_PB = EMA_ALPHA * sinal + (1 - EMA_ALPHA) * EMA_LP;
   return EMA_PB;
   }

    XDeSIG 2019
*/

#include "config_B.h" // Definición de todos los recursos de Echidna Shield "S",  White "W" o Black "B"


int V_Max = 20; // Valor máximo a comparar
int V_Min = 2; // Valor mínimo a comparar

int muestras = 128; // Numero de valores para hacer la media

int media = 0;    // inicia la media a cero

void setup()
{
  // LEDes como salidas
  pinMode (L_Red, OUTPUT);
  pinMode (L_Orn, OUTPUT);
  pinMode (L_Gre, OUTPUT);
  analogReference(INTERNAL); // cambiamos la referencia analógica a 1.1V
}

void loop()
{
  //Captura el valor de Mic y lo acumula
 
  for (int i = 0; i < muestras; i++) {
    int sinal = analogRead(Mic);
    media = media + sinal;
  }

  //Realiza la media de los valores
  media = media / muestras;

  //Si la media de valores supera el valor máximo
  if (media > V_Max) {
    digitalWrite(L_Red, 1); //Enciende el LED rojo, apagamos el Resto
    digitalWrite(L_Orn, 0);
    digitalWrite(L_Gre, 0);
  }

  //Si la media de valores está entre los valores Máx y Min.
  else if (media > V_Min) {
    digitalWrite(L_Red, 0);
    digitalWrite(L_Orn, 1); //Enciende el LED naranja, apagamos el Resto
    digitalWrite(L_Gre, 0);
  }

  //Si la media de valores en menor que el valor mínimo
  else {
    digitalWrite(L_Red, 0);
    digitalWrite(L_Orn, 0);
    digitalWrite(L_Gre, 1); //Enciende el LED verde, apagamos el Resto
  }
}
