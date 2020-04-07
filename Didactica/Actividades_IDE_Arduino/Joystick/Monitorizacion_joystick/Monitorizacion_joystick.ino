/*
  Programa para monitorizar el valor del Joystick
  por el monitor serie
  
  A0 eje x Joystick
  A1 eje y Joystick
  
  Noviembre 2017
  JosePujol
*/

const int xjoyPin = A0;    // pin donde va conectado eje x joystick
const int yjoyPin = A1;    // pin donde va conectado eje y joystick
int xjoyValue = 0;  // variable para almacenar los valores del eje x joystick
int yjoyValue = 0;  // variable para almacenar los valores del eje y joystick

void setup() {
  Serial.begin(9600);        // abrimos el puerto serie y configuramos velocidad
}

void loop() {
  xjoyValue = analogRead(xjoyPin);    // lee y almacena el valor del eje x joystick
  yjoyValue = analogRead(yjoyPin);    // lee y almacena el valor del eje y joystick
  Serial.print(xjoyValue);         // Imprime el valor del eje x joystick
  Serial.print("\t");           // Imprime un tabulador
  Serial.println(yjoyValue);       // Imprime el valor del eje y joystick
  delay(1000);                    // Espera 1 segundo
}
