//  *************************
//  FILE: Test_EchidnaBlack.
//  X.Rosas,J.Lobo
//  Test sensors / Actuator EchidnaBlack
//  *************************

#include "config_B.h"

void setup() {

  pinMode (L_Red, OUTPUT);
  pinMode (L_Orn, OUTPUT);
  pinMode (L_Gre, OUTPUT);
  pinMode (RGB_R, OUTPUT);
  pinMode (RGB_G, OUTPUT);
  pinMode (RGB_B, OUTPUT);
  pinMode (Buzzer, OUTPUT);

  pinMode (IO1, INPUT);
  pinMode (IO2, INPUT);
  pinMode (IO3, INPUT);
  pinMode (IO3, INPUT);
  pinMode (Joy_X, INPUT);
  pinMode (Joy_Y, INPUT);
  pinMode (Ace_X, INPUT);
  pinMode (Ace_Y, INPUT);
  pinMode (IN4, INPUT);
  pinMode (LDR, INPUT);
  pinMode (Temp, INPUT);
  pinMode (Mic, INPUT);

  pinMode (SR, INPUT);
  pinMode (SL, INPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(L_Gre, HIGH);
  digitalWrite(L_Orn, HIGH);
  digitalWrite(L_Red, HIGH);


  Serial.println("*** TEST PROGRAM EchidnaWite, please SW Select SENS mode ***");
  blanco();
  Serial.println("The led Green is Green, Orange is Orange, Red is Red?, else mark Fail");
  blanco();
  presiona();
  analogWrite(RGB_B, 64);
  Serial.println("The led RGB is Blue?, else mark Fail");
  presiona();
  blanco();
  analogWrite(RGB_B, 0);
  analogWrite(RGB_G, 64);
  Serial.println("The led RGB is Green?, else mark fail");
  presiona();
  blanco();
  analogWrite(RGB_G, 0);
  analogWrite(RGB_R, 64);
  Serial.println("The led RGB is Reed?, else mark fail");
  presiona();
  blanco();
  Serial.println("Please press SL");
  blanco();
  while (digitalRead(SL) == LOW) {}
  Serial.println ("The SR an SL are working");
  blanco();


  int gradosC = analogRead(Temp) * 0.48;
  Serial.print("Temperature ");
  Serial.print(gradosC);
  Serial.println(" C");
  blanco();
  Serial.println(" The Indicated temperature is Temp. ambient aprox.?,  else mark Fail");
  blanco();
  presiona();
  blanco();
  Serial.print("speaking to the microphone ");
  while (analogRead(Mic) < 10) {
    delay(10);
  }
  works();
  blanco();
  Serial.println (" Set the volume potentiometer to the rigth possition ");
  blanco();
  presiona();
  
  tone(Buzzer, 4000, 200);;

  Serial.println("Have you heard a beep?, else mark Fail ");
  blanco();
  delay(200);

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

  while (analogRead(Joy_X) > 200) {
    delay(10);
  }
  works();
  blanco();
  Joystick();
  Serial.print("RIGHT");

  while (analogRead(Joy_X) < 600) {
    delay(10);
  }
  works();
  blanco();

  Joystick();
  Serial.print("DOWN");
  while (analogRead(Joy_Y) > 180) {
    delay(10);
  }
  works();
  blanco();

  Joystick();
  Serial.print("UP");
  while (analogRead(Joy_Y) < 600) {
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
  while (analogRead(LDR) > 400) {
    // Serial.println(analogRead(LDR));
    delay(10);
  }
  works();
  blanco();

  //********************************************
  Serial.print("Touch IN4");
  finger();
  while (analogRead(IN4) < 500) {
    // Serial.println(analogRead(IN4));
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

  Serial.println("*** please SW Select MKMK mode! ***");
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

  Serial.print("Touch A0 ");
  mkmk();
  while (analogRead(A0) < 500) {
    delay(10);
  }
  works();
  blanco();
  Serial.println("***END OF THE TEST ***, Please SW Select SENS mode");
  digitalWrite(L_Gre, 0);
  digitalWrite(L_Orn, 0);
  digitalWrite(L_Red, 0);
  digitalWrite(RGB_R, 0);
  digitalWrite(RGB_G, 0);
  digitalWrite(RGB_B, 0);
  blanco();
  Serial.println("*** for repeat test press Reset ***");
  
  Son();
  while (0 == 0) {
    delay(1000);
  }
}
//*********************************************************************
void presiona() {
  Serial.println("Press SR to continue");
  blanco();
  delay(250);
  while (digitalRead(SR) == LOW) {}
}

void blanco() {
  Serial.println();
}
void mkmk() {
  Serial.print(" the connector and Echidna surface");
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

void Son() {
  c_pacman_c();
  noTone(10);
}

void c_pacman_c()
{
  tone(Buzzer, 493, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 987, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 739, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 622, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 987, 70.75475);
  delay(70.75475);
  tone(Buzzer, 739, 70.75475);
  delay(70.75475);
  delay(141.5095);
  tone(Buzzer, 622, 212.26425);
  delay(212.26425);
  delay(70.75475);
  tone(Buzzer, 523, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 1046, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 783, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 659, 70.75475);
  delay(70.75475);
  delay(70.75475);
  tone(Buzzer, 1046, 70.75475);
  delay(70.75475);
  tone(Buzzer, 783, 70.75475);
  delay(70.75475);
  delay(141.5095);
  tone(Buzzer, 659, 212.26425);
  delay(800);
}
