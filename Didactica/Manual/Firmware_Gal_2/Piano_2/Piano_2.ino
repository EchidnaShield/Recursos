/* Piano_2
   Seleccionar o modo MkMk
   Úsanse as entradas A0..A5, D2 e D3 como entradas
   D1 será a saída de son
   Sempre que pechemos o circuíto entre o común e a tecla conectada a entrada
   Emítese un ton con un tempo establecido
*/
int MkMk[] = {A0, A1, A2, A3, A4, A5, 2, 3} ;     //Entradas MkMk
int Ton[] = {262, 294, 330, 392, 440, 494, 523 }; //frecuencias dos tons

#define Tempo 500   //duración do ton en misegundos
#define Buz 10      //Zoador, saída son

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(MkMk[i], INPUT); //Define como entradas as MkMk
  }
  pinMode(Buz, OUTPUT); //modo saída
}

void loop() {

  for (int i = 0; i < 8; i++) {    //Percorremos a matriz

    if (digitalRead (MkMk[i]) == 1) {   //Leemos a entrada MkMk[]
      tone(Buz, Ton[i], Tempo);         //se é = 1 emite un ton
      delay(Tempo);                     //pausa
    }
  }
}
