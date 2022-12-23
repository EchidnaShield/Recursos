/* Vumetro
  Usa los LEDes L_Gre, L_Orn, L_Red, RGB_R, RGB_G y RGB_B
  como indicadores del nivel.
*/
#define RGB_B 6   //Led RGB azul
#define RGB_G 5   //Led RGB verde
#define RGB_R 9   //Led RGB vermello
#define L_Red 13  //Led vermello
#define L_Orn 12  //Led laranxa
#define L_Gre 11  //Led verde
#define Mic A7    //Micrófono
//LEDes nunha matriz para simplificar o manexo
int ledPins[] = { 255, L_Gre, L_Orn, L_Red, RGB_R, RGB_G, RGB_B };
int V_Max = 20;  //valor máximo que queremos medir
void setup() {
  //Definimos os LEDes como saídas
  for (int i = 0; i < 7; i++) {
    pinMode(ledPins[i], OUTPUT);  //percorremos a matriz
  }                               //e definimos cada led como saída
  pinMode(Mic, INPUT);
  // cambiamos a referencia analóxica a 1.1V
  analogReference(INTERNAL);
}
void loop() {
  //Captura o valor analóxico do micrófono
  int sinal = analogRead(Mic);
  // Comproba que non nos pasamos de V_Max56
  if (sinal > V_Max) {
    sinal = V_Max;
  }
  // converte os valores do MIC a un nº de 0 a 7 (LEDes)
  int LED_maior = map(sinal, 0, V_Max, 0, 7);
  //Acende os LEDes ata o valor máis alto
  for (int i = 0; i < LED_maior; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  //Apaga ata o LED máis baixo
  for (int i = 7; i > LED_maior; i--) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(1);
}