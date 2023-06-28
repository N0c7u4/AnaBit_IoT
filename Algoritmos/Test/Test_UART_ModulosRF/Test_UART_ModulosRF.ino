/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Test de Comunicacion UART 
*           entre MCU y LoRa,Zigbee,Sigfox 
*           de la Tarjeta de Desarrollo IoT
*           AnaBit. 
* @Funcionamiento : Copile el algoritmo en AnaBit
*                   luego proceda a abrir el monitor serial
*                   y Ejecute los Siguientes Comandos.
*
* @Comandos : Test LoRa     -> retornara un +AT: OK si hay una comunicacion funcionando
*             Test Sigfox   -> retornara un OK si hay una comunicacion funcionando
*             Test Zigbee   -> retornara un OK si hay una comunicacion funcionando
**/

#include <Arduino.h>
#include <SoftwareSerial.h>

// pines de la comunicacion UART virtual para LoRa
SoftwareSerial SLora(32,33);//RX,TX

void setup() 
{
  // configuracion de velocidad del puerto serial hacia el PC
  Serial.begin(9600);
  // configuracion de velocidad del puerto serial del modulo de LoRa
  SLora.begin(9600);
  // configuracion de velocidad del puerto serial del modulo de Sigfox
  Serial1.begin(9600);
  // configuracion de velocidad del puerto serial del modulo de Zigbee
  Serial2.begin(115200);
}

void loop() 
{

  if(SLora.available())
  {
    String DLoRa = SLora.readString();
    Serial.println(DLoRa);
  }

  if(Serial1.available())
  {
    String DSigfox = Serial1.readString();
    Serial.println(DSigfox);
  }

  if(Serial2.available())
  {
    String DZigbee = Serial2.readString();
    Serial.println(DZigbee);
  }

  // lectura de puerto serial con el PC
  if(Serial.available())
  {
    String DataPC = Serial.readString();
    if(DataPC.indexOf("Test")>=0)
    {
      if(DataPC.indexOf("LoRa")>=0)
      {
        Serial.println("Testing a LoRa");
        SLora.println("AT");
      }
      if(DataPC.indexOf("Sigfox")>=0)
      {
        Serial.println("Testing a Sigfox");
        Serial1.println("AT");
      }
      if(DataPC.indexOf("Zigbee")>=0)
      {
        Serial.println("Testing a Zigbee");
        Serial2.print("AT+INFO?");
      }
    }
  }
}