# Pulsadores:

Ejemplos sobre como usar el pulsador para accionar un zumbador y como programarlo para que tenga memoria y actúe como un interruptor controlando el encendido de un LED RGB blanco. Dado que el problema del pulsador con memoria, es un problema bastante complejo, realizamos 3 aproximaciones partiendo de la de menor complejidad. Finalmente se integran en un ejemplo los dos pulsadores.

## [1.Pulsador-Zumbador](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsador_Zumbador/Pulsador_Zumbador.ino)
Ejemplo para controlar un zumbador con un pulsador, de forma que solo funciona cuando estamos presionando.
- D2 Pulsador R
- D10 Zumbador (Analógico)

## [2. Pulsador Zumbador con LEDs testigos](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsador_Zumbador2/Pulsador_Zumbador2.ino)
Al ejemplo anterior se añaden dos leds, uno rojo y otro verde como testigos del funcionamiento del zumbador
- D2 Pulsador R
- D10 Zumbador (Analógico)
- D11 LED Verde
- D13 LED Rojo
    
## [3. Pulsador Memoria 1- Delay -LED RGB blanco](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsador_Memoria1/Pulsador_Memoria1.ino)
Primera aproximación a realizar un programa que recuerde el estado del LED y permita cambiarlo presionando el pulsador. El programa funciona correctamente si las pulsaciones son inferiores a 0,2s
- D3 Pulsador L
- D9, D5, D6 LED RGB

## [4. Pulsador Memoria 2- While- LED RGB blanco](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsador_Memoria2/Pulsador_Memoria2.ino)
Segunda aproximación al problema en este caso se introduce un While en el que el programa espera a que se deje de pulsar, aún funcionando mucho mejor que el primer caso su funcionamiento no es perfecto.
- D3 Pulsador L
- D9, D5, D6 LED RGB

## [5. Pulsador Memoria 3- Debounce- LED RGB blanco](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsador_Memoria3/Pulsador_Memoria3.ino)
En esta 3ª aproximación al problema se usa el programa Debounce que tiene en cuenta el tiempo de pulsacion y los rebotes, a costa de usar un código mucho más complejo conseguimos un funcionamiento muy eficiente.
- D3 Pulsador L
- D9, D5, D6 LED RGB

## [6. Pulsadores](https://github.com/EchidnaShield/Recursos/blob/master/Didactica/Actividades_IDE_Arduino/Pulsadores/Pulsadores/Pulsadores.ino)
En este caso hemos integrado los dos códigos: Pulsador Memoria 2- LED RGB blanco y Pulsador Zumbador con leds testigos en uno de forma que con D2 controlamos el Zumbador y con D3 controlamos el LED RGB Blanco
- D2 Pulsador R
- D10 Zumbador (Analógico)
- D11 LED Verde
- D13 LED Rojo
- D3 Pulsador L
- D9, D5, D6 LED RGB
