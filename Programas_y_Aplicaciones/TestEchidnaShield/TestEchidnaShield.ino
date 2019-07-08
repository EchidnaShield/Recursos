//  *************************
//    FILE: Echidna_Test_int.
//    X Rosas.JLobo
//  Test sensores / actuadores placa EchidnaShield 000
//  *************************

//*** Outputs ***
const int L_Red = 13;
const int L_Orange = 12;
const int L_Green = 11;

const int RGB_R = 9;
const int RGB_G = 5;
const int RGB_B = 6;
const int Buzzer = 10;

//*** Inputs ***

const int IO1 = 4;
const int IO2 = 7;
const int IO3 = 8;

const int J_X = A0;
const int J_Y = A1;
const int Ace_X = A2;
const int Ace_Y = A3;
const int IN = A4;
const int LDR = A5;

const int SR = 2;
const int SL = 3;

void setup() {

  Serial.begin(9600);
  Serial.println("*** TEST PROGRAM EchidnaShield, please SW Select in SENS mode ***");
  blanco();
  Serial.println (" Set the volume potentiometer to the rigth possition ");//Añadido
  blanco();

  pinMode (L_Red, OUTPUT);
  pinMode (L_Orange, OUTPUT);
  pinMode (L_Green, OUTPUT);
  pinMode (Buzzer, OUTPUT);
  pinMode (SR, INPUT);
  pinMode (SL, INPUT);
  pinMode (IO1, INPUT);
  pinMode (IO2, INPUT);
  pinMode (IO3, INPUT);

  test();
}

void loop() {
}

void test () {
  presiona();

  Serial.println("Please press SL");
  blanco();

  while (digitalRead(SL) == LOW) {}
  Serial.println ("The SR an SL are working");
  blanco();

  digitalWrite(L_Green, HIGH);
  digitalWrite(L_Orange, HIGH);
  digitalWrite(L_Red, HIGH);
  Serial.println("The led Gre is Green, Orn In Orange, Red is Red?, else mark Fail");
  blanco();
  analogWrite(RGB_B, 64);
  Serial.println("The led RGB is Blue?, else mark Fail");
  presiona();
  analogWrite(RGB_B, 0);
  analogWrite(RGB_G, 64);
  Serial.println("The led RGB is Green?, else markfail");
  presiona();
  analogWrite(RGB_G, 0);
  analogWrite(RGB_R, 64);
  Serial.println("The led RGB is Red?, else mark fail");
  presiona();

  blanco();

  tone(Buzzer, 4000, 200);

  Serial.println("Have you heard a beep?, else mark Fail ");
  blanco();
  delay(500);

  //************************************************************
  Serial.print("Please press Joystick button");

  while (digitalRead(SR) == LOW) {}
  while (digitalRead(SR) == HIGH) {
    works();
    delay(500);
  }
  blanco();
  Joystick();
  Serial.print("LEFT");

  while (analogRead(J_X) > 200) {
    delay(10);
  }
  works();
  blanco();
  Joystick();
  Serial.print("RIGHT");

  while (analogRead(J_X) < 1000) {
    delay(10);
  }
  works();
  blanco();

  Joystick();
  Serial.print("DOWN");
  while (analogRead(J_Y) > 180) {
    delay(10);
  }
  works();
  blanco();

  Joystick();
  Serial.print("UP");
  while (analogRead(J_Y) < 1000) {
    delay(10);
  }
  works();
  blanco();

  //*****************************************

  Serial.print("Raise the PCB rigth side ");
  while (analogRead(Ace_X) > 290) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Raise the PCB left side ");
  while (analogRead(Ace_X) < 400) {

    delay(10);
  }
  works();
  blanco();

  Serial.print("Raise the PCB front side");

  while (analogRead(Ace_Y) > 290) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Raise the PCB back side ");

  while (analogRead(Ace_Y) < 400) {
    delay(10);
  }
  works();
  blanco();

  //********************************************
  Serial.print("Cover the LDR ");
  while (analogRead(LDR) > 200) {
    // Serial.println(analogRead(LDR));
    delay(10);
  }
  works();
  blanco();

  //********************************************
  Serial.print("Touch IN");
  finger();
  while (analogRead(IN) < 500) {
    // Serial.println(analogRead(IN));
    delay(10);
  }
  works();
  blanco();

  //********************************************
  Serial.print("Touch IO1");
  finger();
  while (digitalRead(IO1) == 0) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch IO2");
  finger();
  while (digitalRead(IO2) == 0) {
    delay(10);
  }
  works();
  blanco();
  Serial.print("Touch IO3");
  finger();
  while (digitalRead(IO3) == 0) {
    delay(10);
  }
  works();
  blanco();

  Serial.println("*** please SW Selecte in MKMK mode! ***");
  blanco();


  delay(2000);

  Serial.print("Touch D3");
  mkmk();

  while (digitalRead(3) == 0) {
    delay(10);
  }
  works();
  blanco();


  Serial.print("Touch  D2");
  mkmk();


  while (digitalRead(2) == 0 ) {
    delay(10);
  }
  works();
  blanco();


  Serial.print("Touch A5");
  mkmk();

  while (analogRead(A5) < 500) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch A4");
  mkmk();
  while (analogRead(A4) < 500) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch A3");
  mkmk();
  while (analogRead(A3) < 500) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch A2");
  mkmk();
  while (analogRead(A2) < 500) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch A1");
  mkmk();
  while (analogRead(A1) < 500) {
    delay(10);
  }
  works();
  blanco();

  Serial.print("Touch A0");
  mkmk();
  while (analogRead(A0) < 500) {
    delay(10);
  }
  works();
  blanco();
  Serial.println("***END OF THE TEST ***");

}

void presiona() {
  Serial.println("Press SR to continue");
  blanco();
  delay(500);
  while (digitalRead(SR) == LOW) {}
}

void blanco() {
  Serial.println();
}
void mkmk() {
  Serial.print(" the connector and MKMK connector");
}
void finger() {
  Serial.print (" and the +V with the finger ");
}
void Joystick() {
  Serial.print ("Move Joystick to ");
}
void works() {
  Serial.print("\t");
  Serial.println (" This works");
}

