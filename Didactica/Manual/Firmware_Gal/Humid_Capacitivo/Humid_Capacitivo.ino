/* Humid_Capacitivo
 * Lectura da humidade do can
 * Memoriza dous puntos un seco é outro humido
*/

#define Sensor A4 // Entrada analóxica para conectar o sensor
#define SR 2 // Entrada Pulsador SR para memorizar valores (calibrar)
#define L_Red 13 // LED vermello (Seco)
#define L_Org 12 // LED laranxa (Normal)
#define L_Gre 11 // LED verde (Humido)
#define RGB_B 6 // LED azul (bomba funcionando)
#define Rele 4 // Saída I/O 4 relé para a bomba
#define Buz 10 // Buzer (Zoador)

int ValSensor; // Variable para Valor de lecrura do sensor
int VSeco = 510; // Valor inicial para seco
int VHumi = 300; // Valor inicial para humido
double Media; // Valor medio das mostras do sensor
int n = 512; // Numero de lecturas para o valor medio
void setup() {
  Serial.begin(9600); // Inicializa as comunicacións
  pinMode (Sensor, INPUT); // Configura as entradas/saídas
  pinMode (SR, INPUT);
  pinMode (L_Red, OUTPUT);
  pinMode (L_Org, OUTPUT);
  pinMode (L_Gre, OUTPUT);
  pinMode (RGB_B, OUTPUT);
  pinMode (Rele, OUTPUT);
  pinMode (Buz, OUTPUT);
}


void loop() {

//realiza a media aritmética das medidas de humidade
 media(); 
  Serial.println(Media);
  if (Media >= VSeco) {    // O valor indica humidade moi baixa
   Vermello();      // Acende o LED vermello
   Rele_On();     // Activa O relé e o LED azul
  }
  if (Media > VHumi and Media < VSeco) { // Valor de humidade correcto
   Laranxa();     // Acende o LED laranxa
  }
 if (Media <= VHumi) {    // Valor de humidade alta   
  Verde();        // Acende o LED Verde
  Rele_Off();     // Apaga o relé e o LED azul
 }
 // Lectura do pulsador SR para entrar no menú de memorizar valores
 if (digitalRead (SR) == 1) {
  tone (Buz, 4000, 200); //Beep
  memoriza(); //Chama a función memoriza
  }
}



// Función para actualizar os valores de seco e húmido
void memoriza() {
  Rele_Off(); //apaga o rele mentras se calibra
 // Memoriza o valor da terra seca
  Serial.println ("Pincha o sensor en terra seca");
  Serial.println ("Cando este listo pulsa SR");
  delay(500);
  while (digitalRead (SR) == 0) { //Mentres non se pulse SR
 digitalWrite (L_Red, !digitalRead(L_Red)); //Parpadeo do LED vermello
  delay(50);
  }
  tone (Buz, 2300, 200); //Beep, pulsouse SR
  media();    // Calcula a media de n medidas
  VSeco = Media; // Asigna o valor actual como terra seca   
  digitalWrite (L_Red, 0);
  visu(); //Mostra os valores memorizados ata o momento
  
 // Memoriza o valor da terra húmida
  Serial.println();
  Serial.println ("Pincha o sensor en terra humida");
  Serial.println ("Cando este listo pulsa SR");
  delay(500);
  while (digitalRead (SR) == 0) {     //Mentres non se pulse SR
   digitalWrite (L_Gre, !digitalRead(L_Gre)); //Parpadeo do LED verde
   delay(50);
  }

  tone (Buz, 2300, 200); // Beep
  media();
  VHumi = Media;    // Asigna o valor actual como terra húmida  
  while (digitalRead (SR) == 1 ) {} // Espera que solte o pulsador SR
  digitalWrite (L_Gre, 0);     // Apaga o LED Verde

  // Si os valores memorizados están mal, volvemos a lectura dos valores
  if (VHumi >= VSeco) {
   tone (Buz, 200, 1000); //Beep erro
   Serial.println ("Erro");
   Serial.println ("Volve a calibrar o sensor!");
  memoriza(); //volvemos a función memoriza (non fálelo moito)
  }
}

// calculo da media da medida do sensor
void media() {
 for (int i = 0; i < n; i++) { //Bucle de n medidas
  ValSensor = analogRead(Sensor); //lectura do sensor
  Media = Media + ValSensor; //acumula as medidas
  delay(1);
  }
  Media =(int)(Media / n); // Fai a media das n medidas e elimina os decimais
}


//Acende o Relé e o LED azul
void Rele_On() {
  digitalWrite(Rele, 1);
  digitalWrite(RGB_B, 1);
}


//Apaga o Relé e o LED azul
void Rele_Off() {
  digitalWrite(Rele, 0);
  digitalWrite(RGB_B, 0);
}
//Acende o LED vermello apaga os outros
void Vermello() {
  digitalWrite (L_Red, 1);
  digitalWrite (L_Org, 0);
  digitalWrite (L_Gre, 0);
}
//Acende o LED laranxa apaga os outros
void Laranxa() {
  digitalWrite (L_Red, 0);
  digitalWrite (L_Org, 1);
  digitalWrite (L_Gre, 0);
}
//Acende o LED verde apaga os outros
void Verde() {
  digitalWrite (L_Red, 0);
  digitalWrite (L_Org, 0);
  digitalWrite (L_Gre, 1);
}

//Mostra os valores memorizados ata o momento.
void visu() {
  Serial.print("VSeco = ");
  Serial.print(VSeco);
  Serial.print("  VHumi = ");
  Serial.print(VHumi);
  Serial.println();
}
