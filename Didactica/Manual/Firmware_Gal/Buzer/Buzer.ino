/*
* Buzzer
  Son co Buzzer
*/
#define Buzzer 10       //Zumbador D10~

void setup() {
  pinMode (Buzzer, OUTPUT);   //Definimos como saída
  son();        //chamamos a función son
}
void loop() {
  //nada non precisamos repetir
  }
void son(){
  tone(Buzzer, 493, 70.7);  // Frecuencia 493Hz durante 70,7mS
  delay(70.7);              // Retardo de 70,7mS 
  delay(70.7);
  tone(Buzzer, 987, 70.7);
  delay(70.7);
  delay(70.7);
  tone(Buzzer, 739, 70.7);
  delay(70.7);
  delay(70.7);
  tone(Buzzer, 622, 70.7);
  delay(70.7);
  delay(70.7);
  tone(Buzzer, 987, 70.7);
  delay(70.7);
  tone(Buzzer, 739, 70.7);
  delay(70.7);
  delay(141.5);
  tone(Buzzer, 622, 212.2);
  noTone(10);           // paramos o son no pin D10
}
