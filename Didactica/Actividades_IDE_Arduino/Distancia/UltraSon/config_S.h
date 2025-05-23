﻿/*
 * Configuracion de entadas salidas para EhidnaShield
 * config_S.h xdesig 2020
 */

//*** Salidas ***
#define L_Red 13     //Led rojo
#define L_Orn 12     //Led naranja
#define L_Gre 11     //Led verde

#define RGB_R 9      //Led RGB rojo
#define RGB_G 5      //Led RGB verde
#define RGB_B 6      //Led RGB azul

#define Buzzer 10    //Zumbador, salida sonido



//*** Entradas ***
#define IN A4      //Entrada analógica, salida digital

#define IO1 4       //Entrada/salida digital 1
#define IO2 7      //Entrada/salida digital 2
#define IO3 8      //Entrada/salida digital 3


#define Joy_X A0     //Entrada analógica conectada al joystick X
#define Joy_Y A1     //Entrada analógica conectada al joystick Y
#define Sj 2         //Entrada digital conectada al pulsador del joystick = SR

#define Ace_X A2   //Entrada analógica conectada al acelerómetro X
#define Ace_Y A3   //Entrada analógica conectada al acelerómetro X

#define LDR A5     //Entrada analógica conectada a la LDR

#define SR 2       //Entrada digital conectada al pulsador SR
#define SL 3       //Entrada digital conectada al pulsador SL
