/*Basado en el sketch "Modo Escornabot" para el shield Kiwibot, en www.kiwibot.es, por Alberto Pumar @pumar96.
Modificado por Jorge Lobo @lobo_tic
El movimiento del robot se programará mediante el joystick de la placa, 
contando con los comandos Adelante, Atrás, Derecha e Izquierda, que 
corresponderán con el movimiento del joystick a estas posiciones. Cada posición tiene asociado un LED y un sonido.
Para ejecutar la secuencia de movimientos programada, presionaremos 
el pulsador SL del escudo, y para borrar la secuencia se presionará el pulsador SR.

 */

#define SERVO_GIRO 460
#define SERVO_ALANTE 500
#define SERVO_ATRAS 500

int cuentaDatos=0;

//Variables para sustituir delay
long Tini=0;
long Tfin=0;


//Array con los datos (f-->alante, b-->atras, r-->derecha, l-->izquierda)
char datos[50];
//Variable que acumula el numero de casillas ocupadas en el array
int tamDatos;

const int servoLPin = 4; // Pin Sevomotor Izquierdo
const int servoRPin = 7; // Pin Sevomotor Derecho

//constantes para almacenar los pines de los botones
const int botonD=3;
const int botonI=2;

//variables para almacenar la poicion del joystic
int xVal;
int yVal;

void setup(){
  //inicializacion de las entradas y salidas
  pinMode (servoRPin, OUTPUT);
  pinMode (servoLPin, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(botonD, INPUT);
  pinMode(botonI, INPUT);
  Serial.begin(9600);
}

void loop(){
  //Leer los datos y almacenarlos en un array (se queda en bucle hasta que se pulsa el boton derecho)
  tamDatos = leerDatos();
  mover();
}

void mover(){
  for(int i=0; i< tamDatos; i++){
    //si pulsamos el boton izquierdo salimos de la secuencia y borramos los datos. Boton de borrado de datos
    if(digitalRead(botonI)){
      cuentaDatos=0;
      break;
    }
    //movemos el printbot en la direccion que esta almacenadad en el array y mostramos una flecha en la matriz
    else if(datos[i] == 'f'){
      if(alante() == 1){
        cuentaDatos=0;
        break;
      }
    }
    else if(datos[i] == 'b'){
      if(atras() == 1){
        cuentaDatos=0;
        break;
      }
    }
    else if(datos[i] == 'r'){
      if(derecha() == 1){
        cuentaDatos=0;
        break;
      }
    }
    else if(datos[i] == 'l'){
      if(izquierda() == 1){
        cuentaDatos=0;
        break;
      }
    }
    
  }
}

int leerDatos(){
  //Creamos un bucle que finaliza al presionar el boton derecho. Boton de inicio de la secuencia
  while(!digitalRead(botonD)){
    //Leemos la posicion del joytick
    xVal=analogRead(A0);
    yVal=analogRead(A1);

    //si se pulsa el boton izquierdo se modifica el tamaño del array con lo que se sobreescribiran los datos. Boton de borrado de datos
    if(digitalRead(botonI)){
      cuentaDatos=0;
      digitalWrite(6, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
   
    //mover el joystick hacia alante. Vemos si el valor de la x esta dentr de los margenes
    else if(xVal > 200 && xVal < 800){
      //Vemos si la y esta dentro del margen.
      if(yVal > 800){
        //guardamos un dato: almacenamos el dato en el array y sumamos 1 al numero de datos.
        datos[cuentaDatos]= 'f';
        cuentaDatos++;
        //hasta que el valor no vuelva a estar en otra posicion, no hacemos nada para evitar guardar datos erroneos.
        while(yVal > 600){
          yVal=analogRead(A1);
          //mostramos en la matriz una flecha en direccion hacia donde estamos moviendo el joystick
          flechaAlante();
        }
      }

      else if(yVal < 200){
        datos[cuentaDatos]= 'b';
        cuentaDatos++;
        while(yVal < 400){
          yVal=analogRead(A1);
          flechaAtras();
        }
      }
    }

    if(yVal > 200 && yVal < 800){
      if(xVal > 800){
        datos[cuentaDatos]= 'r';
        cuentaDatos++;
        while(xVal > 600){
          xVal=analogRead(A0);
          flechaDerecha();
        }
      }
      else if(xVal < 200){
        datos[cuentaDatos]= 'l';
        cuentaDatos++;
        while(xVal < 400){
          xVal=analogRead(A0);
          flechaIzquierda();
        }
      }
    }
  }
  pausa();  
  return cuentaDatos;
}
//rutinas para mover los servomotores
int atras(){
  Tini=millis();
  while(Tfin-Tini < SERVO_ATRAS){
    if(digitalRead(botonI)){
      return 1;
    }
    digitalWrite(servoRPin,HIGH);
    digitalWrite(servoLPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(servoRPin,LOW);
    delayMicroseconds(1000);
    digitalWrite(servoLPin,LOW);
    delayMicroseconds(18000);
    Tfin=millis();
    flechaAtras();
  }
  pausa();
  return 0;
}
int alante(){
  Tini=millis();
  while(Tfin-Tini < SERVO_ALANTE){
    if(digitalRead(botonI)){
      return 1;
    }
    digitalWrite(servoRPin,HIGH);
    digitalWrite(servoLPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(servoLPin,LOW);
    delayMicroseconds(1000);
    digitalWrite(servoRPin,LOW);
    delayMicroseconds(18000);
    Tfin=millis();
    flechaAlante();
  }
  pausa();
  return 0;
}
int izquierda(){
  Tini=millis();
  while(Tfin-Tini < SERVO_GIRO){
    if(digitalRead(botonI)){
      return 1;
    }
    digitalWrite(servoRPin,HIGH);
    digitalWrite(servoLPin,HIGH);
    delayMicroseconds(2000);
    digitalWrite(servoRPin,LOW);
    digitalWrite(servoLPin,LOW);
    delayMicroseconds(18000);
    Tfin=millis();
    flechaIzquierda();
  }
  pausa();
  return 0;
}
int derecha(){
  Tini=millis();
  while(Tfin-Tini < SERVO_GIRO){
    if(digitalRead(botonI)){
      return 1;
    }
    digitalWrite(servoRPin,HIGH);
    digitalWrite(servoLPin,HIGH);
    delayMicroseconds(1000);
    digitalWrite(servoRPin,LOW);
    digitalWrite(servoLPin,LOW);
    delayMicroseconds(19000);
    Tfin=millis();
    flechaDerecha();
  }
  pausa();
  return 0;

}

void pausa(){
  Tini=millis();
  while(Tfin-Tini < 1000){
    digitalWrite(servoRPin,LOW);
    digitalWrite(servoLPin,LOW);
    Tfin=millis();
  }
}
//rutinas para mostrar los diodos led B avanza, G retrocede, R derecha, O izquierda
void flechaAlante(){
  for(int i=0; i<6; i++){
    digitalWrite(6, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    tone(10,262,300); // write to buzzer
    
  }
}

void flechaAtras(){
  for(int i=0; i<6; i++){
     digitalWrite(6, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    tone(10,87,300); // write to buzzer
   
  }
}

void flechaDerecha(){
  for(int i=0; i<6; i++){
     digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    tone(10,123,300); // write to buzzer
  }
}

void flechaIzquierda(){
  for(int i=0; i<6; i++){
     digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    tone(10,165,300); // write to buzzer
    }
 }
