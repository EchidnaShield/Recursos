/* Titila_II
   titila cando se pulse SR usando a estrutura While
*/
#define L_Orn 12 //Led laranxa 
#define SR 2 //Pulsador SR

void setup() {
 pinMode (SR, INPUT); // Definimos modo entrada
 pinMode (L_Orn, OUTPUT); // Definimos modo saída
 digitalWrite(L_Orn, LOW); //Apaga o LED
}
void loop() {
 // mentres O pulsador SR valga 1 facemos parpadear
 while (digitalRead(SR)==1) {
 digitalWrite(L_Orn, HIGH);	//Acende o LED
 delay(50);				//Espera 50 misisegundos
 digitalWrite(L_Orn, LOW);	//Apaga o LED
 delay (100);			//espera 100 misisegundos
 }
}