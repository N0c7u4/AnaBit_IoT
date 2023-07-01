/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Comunicacion Punto a Punto LoRa
* @Funcionamiento : Copile el algoritmo en AnaBit 
*                   Inicie el Monitor Serial con velocidad 115200 Baud
*       
*
**/
#include <AnaBitLoRa.h>



// doble Banda
// 434MHz/470MHz
// 868MHz/915MHz
#define Factor_Propagacion 7
#define Ancho_Banda 125
#define Long_Preanbulo 10
#define Potencia 20

AnaBitLoRa LoRaBit(915,Factor_Propagacion,Ancho_Banda,Long_Preanbulo,Potencia,false);

void setup() 
{
  // inicializa el puerto serial con una velocidad de 115200 Baud
  Serial.begin(115200);
  // incializamos el modulo LoRa de AnaBit
  LoRaBit.start(9600);
  // configuramos el modo del modulo
  // para la comunicacion punto a punto es el modo "Test"
  LoRaBit.Modo("Test");
  // Se configura la recepcion del texto
  LoRaBit.PtPrx();
  // Configuracion terminada
  Serial.println("Recepcion en escucha...");
}

void loop() 
{
  if(LoRaBit.available())
  {
    String datos = LoRaBit.readString();
    datos = LoRaBit.msgRX(datos, "ASCII");
    Serial.println("Resepcion: "+datos);
    LoRaBit.Frecuencia(470);
    Serial.println("Enviando: Entendido");
    LoRaBit.PtPtxSTR("Entendido",2);
    LoRaBit.Frecuencia(915);
    LoRaBit.PtPrx();
  }
}