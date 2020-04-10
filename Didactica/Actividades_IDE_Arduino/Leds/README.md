# Leds

Colección de programas donde se usan los LEDs de forma secuencial:

- D6 RGB azul
- D13 led rojo
- D12 led naranja
- D11 led Verde
 
## [1. Semaforo 1](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Leds/semaforo/semaforo.ino)
Semáforo con 3 estados: Verde, rojo, amarillo
- Estado verde: 6s
- Estado naranja 2s
- Estado rojo 4s

## [2. Semáforo 2](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Leds/semaforo2/semaforo2.ino)
Semáforo donde se introducen las repeticiones mediante un bucle for
- Estado verde: 6s
- Estado naranja 2s: 5 repeticiones de 0,4 s en el que se enciende y se apaga el led naranja y el zumbador
- Estado rojo: 4s

## [3. Coche fantástico](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Leds/CocheFantastico/CocheFantastico.ino)
A partir de un contador que cuenta 1, 2, 3, 4, 3, 2, 1 y así sucesivamente se encienden los leds.
Verde=1, naranja=2, rojo=3, azul=4

## [4. Juego de LEDs](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Leds/JuegoLEDs/JuegoLEDs.ino)
A partir del programa del coche fantástico se trata de acertar cuando el led rojo está encendido.  * Juego en los que los leds se iluminan alternativamente y hay que acertar cuando el led esta en el color rojo
- Pulsador Derecha: Acertar led rojo
- Pulsador Izquierda: Enciende y apaga el juego
- Tienes 5 vidas
- Ganas si aciertas 7 veces
