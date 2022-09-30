/* 0A41SK_media
    Medida directa dos valores da saída do sensor
*/
#define Sensor A4  //pin conectado o sensor
int ValSensor = 0; //Variable de lectura
int n = 20;        //numero de lecturas
long Media = 0;    //valor a acumular medidas e media

void setup() {
  Serial.begin(9600); //comunicación serie 9600bps
}

void loop() {
  for (int i = 0; i < n; i++) {
    ValSensor = analogRead(Sensor); //lectura do sensor
    Media = Media + ValSensor;      //acumula medidas
    delay(1);                       //pausa para estabilizar
  }
  Media = Media/n;

  Serial.println(Media);          //envío dos datos vía serie
}
