/* Nivel_Y 
 Nivel no eixo Y, indicadores LEDes
*/
#define Red 13 //Led vermello
#define Orn 12 //Led laranxa
#define Gre 11 //Led laranxa
#define Ace_Y A3 //Entrada acelerómetro Y
word Valor_Y; //Variables de lectura do acelerómetro
//Estos valores poden cambiar dependendo de cada EchidanBlack
word Repouso_Y = 359; //Valor de repouso, A nivel

void setup() {
 Serial.begin(9600);
 pinMode(Red, OUTPUT); //modo saída para RGB vermello
 pinMode(Orn, OUTPUT); //modo saída para LED laranxa
 pinMode(Gre, OUTPUT); //modo saída para LED verde
 //Definimos entradas ;-)
 pinMode(Ace_Y, INPUT); //acelerómetro Y
}

void loop() {
 Valor_Y = analogRead(Ace_Y);
 Serie();
 //si o valor Y supera o repouso + 2
 if (Valor_Y >(Repouso_Y+2)) { 
  digitalWrite (Red, 1);		//acendemos o LED vermello
  digitalWrite (Orn, 0);		//apagamos o resto
  digitalWrite (Gre, 0);
 }
 //si o valor Y esta a nivel
 if (Valor_Y <(Repouso_Y+2) and Valor_Y >(Repouso_Y-2)) {
  digitalWrite (Red, 0);
  digitalWrite (Orn, 1); //acendemos o LED Laranxa
  digitalWrite (Gre, 0);//apagamos o resto
 }
  if (Valor_Y <(Repouso_Y-2)) {
  digitalWrite (Red, 0);
  digitalWrite (Orn, 0);
  analogWrite (Gre, 32); //acendemos o LED verde apagamos o resto
  }
}

void Serie() {
  Serial.print("Valor_Y:"); //envía os datos vía serie
  Serial.print(Valor_Y);
  Serial.println("");
}
