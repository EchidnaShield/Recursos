/*
    Teclado para Escornabot con sensores tipo MakeyMakey na placa EchidnaShield
    pódese por calquera obxecto que conduza minimamente a corrente,
    axustando o valor umbral: maior para menos sensibilidade
    *
    Necesitamos 2 módulos Bluetooth, un Mestre e outro Escravo. 
    un HC-05 como Mestre e outro escravo que pode ser HC-05 ou HC-06
    configuración HC-05 como Mestre. 
    Conectaremos o modulo mediante un adaptador USB - RS-232 TTL. Axustes do terminal Baud 38400 ,NL & CR. 
    Comandos AT HC-05 (Pulsar reset durante o acendido, (Parpadeo lento)):
              Envío               -  Resposta
    test:     AT                     OK
    nome:     AT+NAME=<NOME>      -  OK ( preguntar é AT+NAME?, resposta o nome )
    pin       AT+PSWD="<pin>"     -  OK ( AT+PSWD="1234" )
    rol:      AT+ROLE=<rol>       -  OK ( 0=escravo, 1=Mestre (precisa reinicio (pulsar reset mentras se inicia )))
    modo:     AT+CMODE=<mode>     -  OK ( 0=conexión a un enderezo especifico(Bind), 1=conectase o primeiro dispositivo que atopa e se queda ligado a el )
    amarre:   AT+BIND=<enderezo>  -  OK ( Enderezo do escravo no seguinte formato  AT+BIND=98D3, 31, 7028EF )

    +info: https://goo.gl/YTYMmm
    
    XDeSIG 2018 Creative Commons BY-SA4.0.
*/

// A0 Entrada tecla leste (e)
// A1 Entrada tecla norte (n)
// A2 Entrada tecla norte (oeste)
// A3 Entrada tecla sur (n)

// A5 Entrada tecla executa (g)

#define led 9 //led para indicar o funcionamento

int entradas [5] = {A0, A1, A2, A3, A5};      //os pines de entrada
int leds [6] = {13, 6, 11, 12, 5, led};            //Led para indicar a tecla pulsada
char teclas [5] = {'e', 'n', 'w', 's', 'g'};  //cadea a enviar vía serie o escornabot


int umbral = 400;   //Valor a partires do cal se detecta pulsacion ( sensibilidade)
int valor = 0;      //Variable para al macenar o valor da lectura analoxica

int contador = 0;   //Variable do contador

void setup() {
  
  Serial.begin(9600);   //activación da canle serie a 9600bps
  
  
 // configuración dos pines de entrada
  for (contador = 0 ; contador < 5; contador ++) {
    pinMode(entradas[contador], INPUT);
  }

// configuración dos pines de saida ( leds)
for (contador = 0 ; contador < 6; contador ++) {
    pinMode(leds[contador], OUTPUT);
  }
 
 analogWrite(led, 5);  //led de encendido tenue.
  }

  void loop() {

    for (contador = 0 ; contador < 5; contador ++) {
      
      valor = analogRead(entradas[contador]);     //Collemos valor da entrada correspondente
      
      if (valor > umbral) {                       //Comprobamos se o valor supera o umbral de sensibilidade
        
        Serial.print (teclas [contador]);         //Enviamos o comando da tecla seguido do retorno de carro
        Serial.print ("\n");
        
        digitalWrite (leds[contador], HIGH);      //Acendemos o led correspondente a tacla
        delay(200);
        digitalWrite (leds[contador], LOW);
        delay(500);
      }
      delay(1); //Retardo entre lecturas
    }

  }

