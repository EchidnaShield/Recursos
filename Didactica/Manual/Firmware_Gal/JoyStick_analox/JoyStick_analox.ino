/* Joystick_analox
 * Lectura analóxica dos eixos X,Y do Joystick
*/
#define Joy_X A0 // Eixo x conectado -> A0 
#define Joy_Y A1 // Eixo x conectado -> A0

void setup() {
  // Inicia comunicación serie a 9600 Bps 
  Serial.begin(9600);

  // Non é preciso configurar os pines como entrada,
  // pero é unha boa practica para lembrar o rol de cada un.
  pinMode (Joy_X, INPUT); // Definimos como entrada
  pinMode (Joy_Y, INPUT); // "
}
void loop() {
  // Leemos as entradas
  int Valor_X = analogRead(Joy_X);
  int Valor_Y = analogRead(Joy_Y);
  // envía os valores vía serie
  Serial.print(Valor_X);
  Serial.print("\t");    // Envía un tabulador para separar os valores
  Serial.println(Valor_Y);
  // un pequeno retardo para estabilizar as medidas.
 delay(1); 
}