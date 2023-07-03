/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Zigbee Config
* @Funcionamiento : Copile el algoritmo en AnaBit 
*                   Inicie el Monitor Serial con velocidad 115200 Baud
*       
*
**/


void setup() 
{
  // configuracion de velocidad del puerto serial hacia el PC
  Serial.begin(115200);
  // configuracion de velocidad del puerto serial del modulo de Zigbee
  Serial2.begin(115200);

}

void loop()
{
  
  if(Serial2.available())
  {
    String DZigbee = Serial2.readString();
    Serial.println(DZigbee);
  }

  // lectura de puerto serial con el PC
  if(Serial.available())
  {
    String DataPC = Serial.readString();
    Serial.println("comando: "+DataPC);
    Serial2.print(DataPC);
  }
}
