/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Test de Pines GPIO 
*           pines GPIO habilitados como I/O
*           4,2,15,13,12,14,27,25,26,6,7,8,11,21,22
*           pines GPIO habilitados como I
*           36,39,34,35
*           pines GPIO ocupados en comunicacion UART
*           10,9,32,33,17,16
* @Funcionamiento : Copile el algoritmo en AnaBit
*                   luego proceda a abrir el monitor serial
*                   y Ejecute el pin GPIO I/O para testear su salida digital.
*
**/

#include <Arduino.h>

void setup() 
{
  // configuracion de velocidad del puerto serial hacia el PC
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    int DataPC = Serial.readString().toInt();
    pinMode(DataPC,OUTPUT);
    digitalWrite(DataPC,1);
    delay(100);
    digitalWrite(DataPC,0);
    delay(100);
    digitalWrite(DataPC,1);
    delay(100);
    digitalWrite(DataPC,0);
    delay(100);
    digitalWrite(DataPC,1);
    delay(100);
    digitalWrite(DataPC,0);
    delay(100);
    digitalWrite(DataPC,1);
    delay(100);
    digitalWrite(DataPC,0);
    delay(100);
  }

}