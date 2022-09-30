/* Piano
 * Seleccionar o modo MkMk
 * Úsanse as entradas A0..A5, D2 e D3 como entradas
 * D1 será a saída de son
 * Sempre que pechemos o circuíto entre o común e a tecla conectada a entrada
 * Emítese un ton con un tempo establecido
 */
 #define Tempo 500 //duración do ton en milisegundos
 #define Buz 10 //Zoador, saída son

void setup() {
 pinMode(A0,INPUT); //modo entradas
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(10,OUTPUT); //modo saída
}

void loop() {
 if (digitalRead (A0)==1){   //leemos a entrada A0
  tone(10,262,Tempo);   //se é = 1 emite un ton
  delay(Tempo);       //pausa
  }
 if (digitalRead (A1)==1){  // “ A1
  tone(Buz,294,Tempo);
  delay(Tempo);
 }
 if (digitalRead(A2)==1){
  tone(Buz,330,Tempo);
  delay(Tempo);
 }
  if (digitalRead (A3)==1){
  tone(Buz,349,Tempo);
  delay(Tempo);
  }
  if (digitalRead (A4)==1){
  tone(Buz,392,Tempo);
  delay(Tempo);
  }
 if (digitalRead(A5)==1){
  tone(Buz,440,Tempo);
  delay(Tempo);
  } 
  if (digitalRead (2)==1){
  tone(Buz,494,Tempo);
  delay(Tempo);
 }
  if (digitalRead (3)==1){
  tone(Buz,523,Tempo);
  delay(Tempo);
 }
}
