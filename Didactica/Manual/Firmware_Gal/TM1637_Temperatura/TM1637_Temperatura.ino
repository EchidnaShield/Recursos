/*TM1637_Temperatura
   Usamos o Visualizador de catro díxitos controlado
   por o IC TM1637 da empresa Titan Micro Electronics
   Mediante os os pulsadores SR e SL,subimos ou baixamos o brillo: e o SL para baixalo
*/

#include <TM1637Display.h>

//Conexións do módulo de catro Dixitos
#define CLK 8 //Sinal de reloxo
#define DIO 7 //Sinal de datos

TM1637Display display(CLK, DIO); //pasamos os valores a función

#define SR 2 //Pulsador para subir o brillo
#define SL 3 //Pulsador baixar o brillo
#define LM35Pin A6 //Pin al que conectamos sensor temperatura

uint8_t brillo = 1; //Variable para almacenar o brillo
double temperatura; //Variable para almacenar la temperatura medida float
double enteira; //Parte enteira da medida de temperatura

const uint8_t celsius[] = {   //Matriz para almacenar os caracteres especiais
  SEG_A | SEG_B | SEG_F | SEG_G , //º
  SEG_A | SEG_D | SEG_E | SEG_F   //C
};
void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL); //cambiamos a referencia analóxica a 1.1V (AtMega328)
  display.clear(); //limpamos os datos do visualizador
  delay(100);
}

void loop() {

  int lectura = analogRead(LM35Pin); //Valor entre 0 y 1023
  temperatura = ((lectura * 1.1 * 100.0) / 1024.0); //Temperatura en º Celsius


  if (digitalRead (SR) == 1 ) { //Comprobamos si SR esta pulsado
    brillo = brillo + 1; //Sube o brillo
    delay(200);
    if (brillo > 7) { //Evitamos superar o valor 7 do brillo
      brillo = 7;
    }
  }
  if (digitalRead (SL) == 1 ) { //Comprobamos si SL esta pulsado
    brillo = brillo - 1; //Baixa o brillo
    delay(200);
    if (brillo < 1) { //Evitamos baixar de 0 do brillo
      brillo = 0;
    }
  }
  display.setBrightness(brillo, true); //Enviamos o valor do brillo

  double decimal = modf (temperatura, &enteira);

  //Si a parte decimal supera o 0,5º aumentamos en unha unidade a parte enteira
  if (decimal > 0.5) {
    enteira ++;
  }

  display.showNumberDec(enteira, false, 2, 0); //Envía a parte enteira
  display.setSegments(celsius, 2, 2); //Envía os segmentos almacenados
  delay(500); // retardo de 500 milisegundos
}
