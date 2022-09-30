/*TheremLDR
 Un pequeno programa, ca LDR manexamos o zoador e un par de LEDes
*/
//Entradas / saídas
#define LDR A5
#define Buz 10
#define RGB_R 9
#define RGB_G 5
int Valor_LDR; //Variables 
int Frecuencia;
int BrilloR;
int BrilloG;
void setup() {
pinMode (LDR ,INPUT); //Axuste do modo 
pinMode (Buz ,OUTPUT);
pinMode (RGB_R ,OUTPUT);
}
void loop() {
 Valor_LDR = analogRead(A5); //leemos a LDR
//escala o Valor da LDR a frecuencia
 Frecuencia = map(Valor_LDR, 0, 1023, 400, 2500); 
 BrilloR = map(Valor_LDR, 0, 1023, 0, 128); //escala Valor_LDR o brillo do LED
 BrilloG = map(Valor_LDR, 0, 1023,16, 64); //escala para colorear 
//si se escurece apaga o zoador
 if (Valor_LDR<50){ Frecuencia= 0;} 
 tone(Buz, Frecuencia, 10); //emite a frecuencia dependente da LDR
 analogWrite(RGB_R, BrilloR); //luz Vermella
 analogWrite(RGB_G, BrilloG); //luz Verde
 delay(1); //unha espera para estabilizar a conversión AD
}
