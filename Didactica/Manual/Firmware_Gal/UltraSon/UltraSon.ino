/* UltraSon
 * Medidor de distancias mediante ultrasóns HC-SR04
 * conectado a entrada/saída IN "A4", como so ten un pin,
 * unimos os pines “Trigger e ECHO” do HC-SR04 e conectalos o IN
*/
#define IN A4 //pin de conexión 
const int Vson = 34300.0; // Velocidade son en cm/s
void setup() {
 Serial.begin(9600); // Inicia a conexión serie
}

void loop() {
 pinMode (IN, OUTPUT); //Define o pin como saída para provocar o   disparo "TRIGGER"
 digitalWrite(IN, LOW); //Trigger en estado baixo e espera 2 ms
 delayMicroseconds(2);
 digitalWrite(IN, HIGH);//Trigger a estado alto e espera 10 ms
 delayMicroseconds(10);
 digitalWrite(IN, LOW); //Trigger en estado baixo.
 pinMode (IN, INPUT);   //Define o pin como entrada "ECHO"
 //A función pulseIn obtén o tempo que tarda en cambiar entre estados, en este caso a HIGH
 unsigned long tempo = pulseIn(IN, HIGH);

 //Para obter a distancia en cm, convite o tempo a segundos xa que está en microsegundos
 //por iso multiplicamos por 0.000001 (podemos axustar este valor por as tolerancias do sensor)
 int distancia = tempo * 0.000001 * Vson / 2.0;
 
 Serial.print(distancia);
 Serial.print("cm");
 Serial.println();
 delay(500);
}