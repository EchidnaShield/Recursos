/*HALL_Proximidade
 Detectando a proximidade de un campo magnético
 Acendendo un par de LEDes como testemuñas
 Aende o Led verde ca intensidade do campo detectado
*/
#define HALL A4 //Sensor Efevto HALL conectada a A4 
#define L_Red 13 //Led vermello a D13
#define L_Orn 12 //Led laranxa a D12
#define L_Gre 11 //Led verde a D11
int limiarN = 550; //valor activación cara norte
int limiarS = 500; //valor activación cara norte
int ValorHALL;
int ValorMap;
void setup() {
 Serial.begin (9600);
 pinMode (HALL, INPUT); // Definimos como entrada
 pinMode (L_Red, OUTPUT); // Definimos modo saída
 pinMode (L_Orn, OUTPUT); // Definimos modo saída
 pinMode (L_Gre, OUTPUT); // Definimos modo saída
}
void loop() {
  ValorHALL = analogRead(HALL); // Leemos aa entrada 
 
 // comproba si o valor supera o limiarN
 if ( ValorHALL > limiarN) {   
  digitalWrite (L_Red, HIGH); // Acende o LED vermello
  }
  //Se non supera o limiar norte a paga lo LED
  else {                     
  digitalWrite (L_Red, LOW); // Apaga o LED vermello
 }
 // comproba si o valor é inferior  o limiarS
 if ( ValorHALL < limiarS) {
   digitalWrite (L_Orn, HIGH); // Acende o LED laranxa
  }
  //No caso contrario apaga o LED laranxa
  else {
   digitalWrite (L_Orn, LOW); // Apaga o LED
  }
  Serial.println(ValorHALL); //Envía O valor vía serie
  //Escala o valor de entrada o valor de iluminación do led verde
  ValorMap = map (ValorHALL, 0, 1000, 0, 64); 
  analogWrite (L_Gre, ValorMap); // acende o LED verde co valor escalado
  
  // un pequeno retardo para estabilizar as medidas.
  delay(10);
}
