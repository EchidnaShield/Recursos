/* Vibracions
Alarma movemento usamos o acelerómetro para activara alarma
zoador e led RGB vermello, cando tentamos mover Echidna
Cando tilila o LED laranxa nos invita a pulsar SR para memorizar a
a posición inicial, e comenzar o xogo. máis info. vía serie
*/
int limiar_X = 5; //Limites de alarma
int limiar_Y = 5;

#define RGB_R 9 //Led RGB vermello
#define Orn 12 //Led laranxa
#define Gre 11 //Led laranxa

#define Buz 10   //Zoador, saída son

#define SR 2  //Entrada pulsador SR 
#define Ace_X A2 //Entrada acelerómetro X
#define Ace_Y A3 //Entrada acelerómetro Y
word Valor_X;   //Variables de lectura do acelerómetro
word Valor_Y;
word mostras = 100; //numero de lecturas consecutivas
word media_X = 0;
word media_Y = 0;

void setup() {
 Serial.begin(9600);
 pinMode(RGB_R, OUTPUT);  //modo saída para RGB vermello
 pinMode(Orn, OUTPUT);  //modo saída para LED laranxa
 pinMode(Gre, OUTPUT);  //modo saída para LED verde
 pinMode(Buz, OUTPUT);  //modo saída para o zoador


 //Definimos como entradas ;-)
 pinMode(Ace_X, INPUT); //acelerómetro X
 pinMode(Ace_Y, INPUT); // " Y
 pinMode(SR, INPUT); //pulsador SR


 Serial.println("");
 Serial.print("Pulsa SR para memorizar a posición");
 
while (digitalRead (SR) == 0 ) {
 digitalWrite (Orn, HIGH);
 delay(10);
 digitalWrite (Orn, LOW);
 delay(50);
 }
 memoriza_XY();
}
void loop() {
 Valor_X = analogRead(Ace_X);
 delay(1);
 Valor_Y = analogRead(Ace_Y);
 Serie(); // Chama a función Serie(), para enviar os valores.

 //Si excedemos os limites inferior ou superior activamos a alarma
 if (Valor_X > (media_X + limiar_X) or Valor_X < (media_X - limiar_X)) {
 alarma();
 }
 if (Valor_Y > (media_Y + limiar_Y) or Valor_Y < (media_Y - limiar_Y)) {
 alarma();
 }
 //Se non temos alarma apaga o LED e zoador
 digitalWrite (RGB_R, LOW);
 noTone(Buz);
}
// función alarma
void alarma() {
 Serial.println("Alarma");
 digitalWrite (RGB_R, HIGH); //activa o LED vermello
 tone(Buz, 2500); //Emite unha frecuencia de 2500Hz
 delay(100); //pausa de 100 mSeg
}
void memoriza_XY() {
 //medidas repetidas para facer unha media
 for (int i = 0; i < mostras; i++) {
 Valor_X = analogRead(Ace_X);
 media_X = media_X + Valor_X;
 delay (1); //atraso para a conversión analóxica dixital
 Valor_Y = analogRead(Ace_Y);
 media_Y = media_Y + Valor_Y;
 delay (1); //atraso para a conversión analoxica dixital
 }
 //calcula a media aritmética
 media_Y = media_Y / mostras;
 media_X = media_X / mostras;
 //Envia os valores memorizados
 Serial.println("");
 Serial.print("media X:");
 Serial.print(media_X);
 Serial.print("\t");
 Serial.print("media Y:");
 Serial.print(media_Y);
 Serial.println("");
 analogWrite(Gre, 8); //Acende o LED verde
 delay(2000); //espera 2 segundos
 analogWrite(Gre, 32);//Acende o LED verde con máis intensidade 
}

//envia os valores memorizados e os actuais
void Serie() {
 Serial.print("media X:");
 Serial.print(media_X);
 Serial.print("\t");
 Serial.print("Valor X:");
 Serial.print(Valor_X);
 Serial.print("\t");
 Serial.print("media Y:");
 Serial.print(media_Y);
 Serial.print("\t");
 Serial.print("Valor Y:");
 Serial.print(Valor_Y);
 Serial.println("");
}
