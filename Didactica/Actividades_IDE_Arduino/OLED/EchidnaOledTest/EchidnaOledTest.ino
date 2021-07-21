// Xabier Rosas 2020-2021 para Echidna
// Test sensores EchidnaBlack en pantalla OLED SSD1306 128 X 64//

#include <OLED_I2C.h> //Copyright (C)2015-2019 Rinky-Dink Electronics, Henning Karlsen.CC BY-NC-SA 3.0 license.
//En cada Config_ establece os pins de comunicacións I2C OLED

#include "config_B.h" // Definición de todolos recursos de Echidna Shield "S",  White "W" ou Black "B"
// Ollo os recursos de EchidnaShield son menores que os da Black ou White

// Fontes de textos e numeros
extern uint8_t TinyFont[];
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t echidnaLogo[];

int Temperaturas[128];  //Matriz para gardar as temperaturas



//Tempo de captura de temperatura grafica (segundos)
// 1 pixel cada 10 segundos
float const Periodo = 0.1;


//****** Variables ********************
unsigned long TempoAct;
int menu = 0;
int centrX = 64;
int centrY = 32;
int lectura;
float media;
int temperatura;
int temperaturaM; //Temperatura mapeada
float Valor;
int i;
int x;
int n = 17; //Contador dos primeiros 128-17 puntos da grafica de temperatura


void setup() {
  Serial.begin(9600); // Inicializa a comunicación serie

  //***** Establece o funcionamento dos pines *******
  pinMode(SR, INPUT);
  pinMode(SL, INPUT);
  pinMode(Joy_X, INPUT);
  pinMode(Joy_Y, INPUT);
  pinMode(Ace_X, INPUT);
  pinMode(Ace_Y, INPUT);
  pinMode(LDR, INPUT);
  pinMode(LM35, INPUT);
  pinMode(Mic, INPUT);

  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  myOLED.begin(SSD1306_128X64); //inicializa o visualizador OLED 128x64

  //************** Pinta o logo ****************************
  LOGO();
  delay(500);
  //************** Musiqueta ****************************
  c_pacman_c();

  //************** Presenta a mensaxe de inicio ****************************
  myOLED.clrScr();    // Borra todo o que ten na memora do visualizador
  INI();
  myOLED.update();   // Presenta a informacion no visualizador

  //************** Enche a matriz co valor 64 ********************
  while (digitalRead(SR) == 0) {}
  for (i = 0; i < 127; i++) {
    Temperaturas[i] = 64;
  }
}

void loop() {
  //*************** Presenta os textos básicos *****************
  basicos();


  //**************  Comproba si se pulsa ***********************
  if (digitalRead(SR) == 1) {
    menu++; c_pa();   // incermenta o menu, e fai ruido :-)
  }
  if (digitalRead(SL) == 1) {
    menu--; c_pa();   // decermenta o menu, e fai ruido :-)
  }
  //** Se nos pasamos das opcions voltamos o inico "Menu circular" ****
  if (menu > 6 ) menu = 0;
  if (menu < 0 ) menu = 6;

  switch (menu) {
    case 0: INI();
      break;
    case 1: JOY();
      break;
    case 2: TEMP();
      break;
    case 3: LUZ();
      break;
    case 4: Acel();
      break;
    case 5: Micro();
      break;
    case 6: GTemp();
      break;
  }

  myOLED.update();    // Pinta todo o que ten na memora do visualizador
  // delay(10);
  myOLED.clrScr();    // Borra todo o que ten na memora do visualizador
}
//******* Rutinas de cada menu e auxiliares ********************

//******* Textos do menu de nivel 0, inicial
void INI() {
  myOLED.setFont(SmallFont);
  myOLED.print("Pulsa SR para avanzar", CENTER, 20);
  myOLED.print("SL  para retroceder", CENTER, 40);
  myOLED.print("Nivel", 90, 54);
  myOLED.printNumI(menu, RIGHT, 54);
}


//****** Rutina de presentación dos valores do Joystick ******
void JOY() {
  // Cambia a cor do RGB
  analogWrite (RGB_R, 0x00); analogWrite(RGB_G, 0x00); analogWrite(RGB_B, 0xff);

  // Pasa a referencia de voltaxe a 5V
  analogReference(DEFAULT);

  // Le o valor do Joystick eixo X, presenta valores e os escala
  int lecJoy_X = analogRead(Joy_X);
  myOLED.printNumI(lecJoy_X, LEFT, 32);
  lecJoy_X = map(lecJoy_X, 0, 1023, -20 , 20);

  // Le o valor do Joystick eixo X, presenta valores e os escala
  int lecJoy_Y = analogRead(Joy_Y);
  myOLED.printNumI(lecJoy_Y, RIGHT, 32);
  lecJoy_Y = map(lecJoy_Y, 0, 1023, 20 , -20);

  //Debuxa o circulo que representa o Joystick
  myOLED.drawCircle(centrX + 1 + lecJoy_X - 1, centrY + lecJoy_Y, 8);

  // Debuxa o resto das liñas e o circulo
  myOLED.drawLine(34, centrY, 94, centrY);
  myOLED.drawLine(centrX, 2, centrX, 63);
  myOLED.drawCircle(centrX, centrY, 30);
  myOLED.print("Joy X", LEFT, 22);
  myOLED.print("Joy Y", RIGHT, 22);
}

//****** Rutina de presentación dos valores do Joystick ******
// debuxa circulos en funcion da luz recibida

void LUZ() {
  // Apaga o RGB para non interferir na LDR
  analogWrite (RGB_R, 0x00); analogWrite(RGB_G, 0x00); analogWrite(RGB_B, 0x00);

  // Filtra as variacións facendo unha media de 128 valores
  media = 0;
  analogReference(DEFAULT);
  for (i = 0; i < 128 ; i++ ) {
    lectura = analogRead(LDR);
    media = media + lectura;
  }
  lectura = media / 128;

  // Escala a media da lectura dbuxando circulos crecentes
  int lecturam = map(lectura, 0, 1024, 10, 50);
  for (int i = 1; i < lecturam ; i++ ) {
    myOLED.drawCircle(64, 35, i);
  }
  // Presenta O valor da medida da luz
  myOLED.setFont(MediumNumbers);
  myOLED.invertText(true);
  myOLED.printNumI(lectura, CENTER, 28);
  myOLED.setFont(SmallFont);
  myOLED.print("L D R", CENTER, 20);
}


//****** Rutina de presentación da temperatura ******
// debuxa un termometro que se ence + o -

void TEMP() {
  // Cambia a cor do RGB
  analogWrite (RGB_R, 0xFF); analogWrite(RGB_G, 0x00); analogWrite(RGB_B, 0x00);

  // Cambia a referencia do conversor A-D a 1,1V
  // para ter maior resolución na medida
  analogReference(INTERNAL);
  // Lee a tension do LM35 e o pasa a temperatura
  //en º Celsius 10mV * ºC
  lectura = analogRead(LM35);
  int temperatura = (lectura * 1.1 * 100.0) / 1024.0;
  // Presenta o Valor da temperatura
  myOLED.print("Temperatura", CENTER, 15);
  myOLED.print("     O", CENTER, 30);
  myOLED.setFont(MediumNumbers);
  myOLED.printNumI(temperatura, CENTER, 30);

  // Pasa a temperatura a un grafico con forma de termometro
  // Debuxa con circunferencias o bulbo
  for (i = 1; i < 8 ; i++ ) {
    myOLED.drawCircle(10, 50, i);
  }
  // Debuxa o tubo capilar con un rectangulo de bordes redondeados
  myOLED.drawRoundRect(10, 47, 110, 53);

  // Debuxa liñas ata a temperatura para encher o rectangulo
  temperatura = map(temperatura, 0, 60, 10, 110);
  for (i = 47; i < 53 ; i++ ) {
    myOLED.drawLine(10, i, temperatura, i);
  }
}


//****** Rutina de representacion da temperatura no tempo ******
// recolle a temperatura cada "Periodo"
void GTemp() {
  // Cambia a cor do RGB
  analogWrite (RGB_R, 0xff); analogWrite(RGB_G, 0x55); analogWrite(RGB_B, 0x44);

  // Debuxa a infomación da escala
  myOLED.print(" GTemp", CENTER, 0);
  myOLED.print("Temp", LEFT, 10);
  myOLED.print("40", LEFT, 20);
  myOLED.print("30", LEFT, 30);
  myOLED.print("20", LEFT, 40);
  myOLED.print("10", LEFT, 50);
  myOLED.print("0.1s/Px Punt.10Px", CENTER, 55);

  // debuxa os puntos da escala
  for (x = 127; x > 10; x = x - 10) {
    myOLED.setPixel (x, 53);
    myOLED.setPixel (x, 42);
    myOLED.setPixel (x, 32);
    myOLED.setPixel (x, 21);
  }

  // Pasa os os 128 valores almacenados a memoria do OLED
  for (i = 0; i < 127; i++) {
    myOLED.setPixel (i, Temperaturas[i]);
  }

  // cambia a referencia analoxica a 1.1V
  analogReference(INTERNAL);

  //Realiza unha media de 40 valores para eviar cambios bruscos na grafica
  media = 0;
  for (i = 0; i < 40; i++) {
    lectura = analogRead(LM35); // 10mV * ºC
    media = media + lectura;
  }
  lectura = media / 40;

  // pasa a temperatura en º Celsius 10mV * ºC
  temperatura = (lectura * 1.1 * 100.0) / 1024.0;
  // Presenta o valor da temperatura
  myOLED.printNumI(temperatura, CENTER, 10);

  // Mapea a medida
  temperaturaM = map(temperatura, 0, 60, 63, 0 );

  // Le a temperatura cada periodo establecido, almacenando
  // nunha matriz para representalo primeiro de derereita a esquerda
  // e cando encha a pantalla, n=127 de esquerda a dereita.
  if (millis() - TempoAct >= (Periodo * 1000)) {
    TempoAct = millis();
    Temperaturas[n] = temperaturaM;
    Serial.println (temperatura);
    if (n < 127) {
      n = n + 1;
    }
    else  {
      for (i = 0; i < 127; i++) {
        Temperaturas[i] = Temperaturas[i + 1];
      }
    }
  }
}

//****** Rutina de representacion da inclinacion  ******
// recollida polo acelerometro X-Y
void Acel() {
  // Cambia a cor do RGB
  analogWrite (RGB_R, 0x88); analogWrite(RGB_G, 0x00); analogWrite(RGB_B, 0x88);
  // Cambia a referencia de voltaxe do ADC a 5V
  analogReference(DEFAULT);

  // Recolle a lectura do acelerometro X-Y
  int lecAcel_X = analogRead(Ace_X); //288, 436
  int lecAcel_Y = analogRead(Ace_Y); //286, 432


  // Mapea a lectura a -+ 90º de inclinación
  int lecAcel_Xm = map (lecAcel_X, 288, 436, +90, -90);
  int lecAcel_Ym = map (lecAcel_Y, 286, 432, -90, +90);

  // Presenta os datos de inclinación
  myOLED.print("Ac X", LEFT, 22);
  myOLED.printNumI(lecAcel_Xm, LEFT, 32);
  myOLED.print("Ac Y", RIGHT, 22);
  myOLED.printNumI(lecAcel_Ym, RIGHT, 32);

  // Debuxa as duas circunferencias e as liñas X-Y da escala
  myOLED.drawCircle(centrX, centrY, 30);
  myOLED.drawCircle(centrX, centrY, 15);
  myOLED.drawLine(34, centrY, 94, centrY);
  myOLED.drawLine(centrX, 2, centrX, 63);

  // Mapea a lectura a +-30 para debuxala bola na circunfencia
  lecAcel_X = map (lecAcel_X, 288, 436, 30, -30);
  lecAcel_Y = map (lecAcel_Y, 286, 432, -30, +30);

  myOLED.drawCircle(centrX + lecAcel_X, centrY + lecAcel_Y, 2);
}


//****** Rutina de representacion do volume do son  ******

void Micro() {
  // Cambia a cor do RGB
  analogWrite (RGB_R, 0xff); analogWrite(RGB_G, 0x55); analogWrite(RGB_B, 0x44);
  // Presenta a palabra "Microf"
  myOLED.setFont(SmallFont);
  myOLED.print("  Microf", CENTER, 0);

  // cambiamos a referencia analoxica a 1.1V
  analogReference(INTERNAL);

  //  Realiza 110 medidas do microfono
  for (int x = 0; x <  110; x++) {
    int lecMic = (analogRead(Mic)) * 2; //
    if (lecMic == 0) {
      lecMic = 1;
    }
    //    Presenta o volume do son como liñas verticais
    myOLED.drawLine(x, 60, x, 60 - lecMic);

    myOLED.setFont(MediumNumbers);
    myOLED.printNumI(lecMic - 1, RIGHT, 28);
  }
}


//******* Presenta os textos comuns a todolos menus ******
void basicos() {
  myOLED.setFont(SmallFont);
  myOLED.print("ECHIDNA ", LEFT, 0);
  myOLED.print("STEAM", RIGHT, 0);
  //myOLED.printNumI(menu, RIGHT, 54);
}




//******* presenta o logo de Echidna ********************

void LOGO() {
  myOLED.clrScr();
  myOLED.drawBitmap(8, 0, echidnaLogo, 114, 64);
  myOLED.update();
}

// Musiqueta inicial, que vai cambiando o led RGB entre notas

void c_pacman_c()
{
  tone(Buzzer, 493, 70.75475);
  analogWrite (RGB_R, 0x1B); analogWrite(RGB_G, 0xBB); analogWrite(RGB_B, 0x08);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 987, 70.75475);
  analogWrite (RGB_R, 0xB0); analogWrite(RGB_G, 0x0B); analogWrite(RGB_B, 0xA8);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 739, 70.75475);
  analogWrite (RGB_R, 0x1B); analogWrite(RGB_G, 0xBB); analogWrite(RGB_B, 0x08);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 622, 70.75475);
  analogWrite (RGB_R, 0xAA); analogWrite(RGB_G, 0x8A); analogWrite(RGB_B, 0xAA);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 987, 70.75475);
  analogWrite (RGB_R, 0xF0); analogWrite(RGB_G, 0xF0); analogWrite(RGB_B, 0x0F);
  delay(70.75475);
  tone(Buzzer, 739, 70.75475);
  analogWrite (RGB_R, 0xF0); analogWrite(RGB_G, 0x20); analogWrite(RGB_B, 0x98);
  delay(70.75475);
  delay(141.5095);
  tone(Buzzer, 622, 212.26425);
  analogWrite (RGB_R, 0xFA); analogWrite(RGB_G, 0xAB); analogWrite(RGB_B, 0x10);
  delay(212.26425);
  delay(70.75475);
  tone(Buzzer, 523, 70.75475);
  analogWrite (RGB_R, 0x00); analogWrite(RGB_G, 0xFF); analogWrite(RGB_B, 0xFF);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 1046, 70.75475);
  analogWrite (RGB_R, 0x80); analogWrite(RGB_G, 0x80); analogWrite(RGB_B, 0x08);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 783, 70.75475);
  analogWrite (RGB_R, 0x0F); analogWrite(RGB_G, 0x18); analogWrite(RGB_B, 0x80);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 659, 70.75475);
  analogWrite (RGB_R, 0x10); analogWrite(RGB_G, 0x1F); analogWrite(RGB_B, 0x1F);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 1046, 70.75475);
  analogWrite (RGB_R, 0x11); analogWrite(RGB_G, 0x11); analogWrite(RGB_B, 0x11);
  delay(70.75475);
  tone(Buzzer, 783, 70.75475);
  delay(70.75475);
  delay(141.5095);
  tone(Buzzer, 659, 212.26425);
  analogWrite (RGB_R, 0xFF); analogWrite(RGB_G, 0xFF); analogWrite(RGB_B, 0x1F);
  delay(100);
}


// Sonido bitonal o cambiar de menu.

void c_pa()
{
  tone(Buzzer, 493, 70.75475);
  analogWrite (RGB_R, 0xFF); analogWrite(RGB_G, 0xFF); analogWrite(RGB_B, 0x1F);
  delay(70.75475);
  tone(Buzzer, 987, 70.75475);
  analogWrite (RGB_R, 0x02); analogWrite(RGB_G, 0x02); analogWrite(RGB_B, 0x02);
  delay(70.75475);
}
