/*
  Programa para monitorizar el valor del acelerómetro
  por el serial plotter

  A2 eje X acelerómetro
  A3 eje Y acelerómetro
  
  Noviembre 2017
  JosePujol
*/

// variables constantes
const int xPin = A2;    // pin al que va conectado eje X acelerómetro
const int yPin = A3;    // pin al que va conectado eje Y acelerómetro
// variables que cambian
int xValue = 0;  // variable para almacenar los valores X acelerómetro
int yValue = 0;  // variable para almacenar los valores Y acelerómetro

void setup() {
  Serial.begin(9600);        // abrimos el puerto serie y configuramos velocidad
}

void loop() {
  xValue = analogRead(xPin);    // lee y almacena el valor del eje X acelerometro 
  yValue = analogRead(yPin);    // lee y almacena el valor del eje Y acelerometro 
  Serial.print(xValue);         // Imprime el valor del eje X acelerometro
  Serial.print("\t");           // Imprime un tabulador
  Serial.println(yValue);       // Imprime el valor del eje Y acelerometro
  delay(100);                    // Espera 0.1 segundo
}
