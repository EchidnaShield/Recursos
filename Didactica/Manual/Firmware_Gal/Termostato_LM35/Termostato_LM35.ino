/*/ Termostato LM35
  Comparación da temperatura con unha dada como Consigna
  para acender un led (activar unha saída)
*/
#define L_Gre 11 // pin do LED verde -> D11
#define Temp A6  // Pin do LM35 -> A6

int Consigna = 27; //Temperatura elixida ºC
//diferencia en grados sobre activación e desactivación
int Diferencia = 2;
int Histerese = (Diferencia /2);
int T_1 = Consigna + Histerese; //temperatura de activación
int T_2 = Consigna - Histerese; //temperatura de desactivación
int temperatura; //temperatura medida
char *Estado = "Desactivado"; //cadea de texto do estado
void setup() {
  analogReference(INTERNAL); //referencia analóxica a 1.1V
  Serial.begin(9600); //config. porto serie
  pinMode (Temp, INPUT); //pin LM35 como entrada
  pinMode (L_Gre, OUTPUT); //saída para LED
  digitalWrite (L_Gre, LOW); //apaga o LED, estado inicial
}
void loop() {
  int lectura = analogRead(Temp); //devolta un valor entre 0 y 1023

  //temperatura en º Celsius
  temperatura = (lectura * 1.1 * 100.0) / 1024.0;
  if (temperatura > T_1 ) {  //si supera o valor
    digitalWrite (L_Gre, HIGH); //acende o LED
    Estado = "Activado";
  }
  if (temperatura < T_2) {   //si baixa do valor
    digitalWrite (L_Gre, LOW); //apaga o LED
    Estado = "Desactivado";
  }
  // envia as mensaxes vía serie
  Serial.print("Temp Actual: ");
  Serial.print(temperatura);
  Serial.print("ºC ");
  Serial.print("\t");
  Serial.print(" Consigna: ");
  Serial.print(Consigna);
  Serial.print("ºC");
  Serial.print("\t");
  Serial.print("Histérese: ");
  Serial.print(Histerese);
  Serial.print("ºC");
  Serial.print("\t");
  Serial.print("Estado: ");
  Serial.println(Estado);

  delay(1000); //tempo de espera de 1s
}
