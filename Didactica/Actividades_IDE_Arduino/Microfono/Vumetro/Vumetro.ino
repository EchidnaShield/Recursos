/*
    Utiliza el microfóno y los LEDes para simular un VU-Meter
    conectado a la entrada Mic, Usa los Leds L_Gre, L_Orn, L_Red, RGB_R, RGB_G y RGB_B
    como indicadores del nivel.
    XDeSIG 2019
*/

#include "config_B.h" // Definición de todos los recursos de Echidna Shield "S" Black "B" White "W"


int ledPins[] = {255, L_Gre, L_Orn, L_Red, RGB_R, RGB_G, RGB_B} ; // LEDes en una matriz, el 


int V_Max = 20; // valor maximo que queremos medir

void setup()
{
  //Definimos los LEDes como salidas
  for (int i = 0; i < 7; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  //Serial.begin(9600);
  analogReference(INTERNAL); // cambiamos la referencia analógica a 1.1V
}

void loop()
{


  int sinal = analogRead(Mic); //Captura el valor analógico del micrófono
  //Serial.println(sinal);
  // Comprueba que no nos pasamos de V_Max
  if (sinal > V_Max) {
    sinal = V_Max;
  }

  // convierte los valores del MIC a un nº de 0 a 6 (Leds)
  int LED_maior = map(sinal, 0, V_Max, 0, 7); //mapea(valor, Valor inferior de entrada, superior de entrada, a bajo, a alto)

  for (int i = 0; i < LED_maior; i++) //Enciende los LEDes hasta e valor más alto
  {
    if (LED_maior > 0) {
      digitalWrite(ledPins[i], HIGH);
    }
    analogWrite (ledPins[0], 16);
  }

  for (int i = LED_maior + 1; i < 7; i++) //Apaga hasta el LED más alto
  {
    digitalWrite(ledPins[i], LOW);
  }

  delay(1);
}
