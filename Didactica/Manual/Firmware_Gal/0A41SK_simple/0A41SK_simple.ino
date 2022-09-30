/* 0A41SK_simple
 *  Sharp IR Sensor
 *  Medida directa dos valores da saída do sensor
*/
#define Sensor A4   //pin conectado o sensor

int ValSensor = 0;  //Variable de lectura

void setup() {
  Serial.begin(9600); //cominicación serie 9600bps
}

void loop() {
  int ValSensor = analogRead(Sensor); //lectura do sensor
  Serial.println(ValSensor);          //envio dos datos vía serie
  delay(10);                //pausa para estabilizar
}
