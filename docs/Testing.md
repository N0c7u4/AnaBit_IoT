# Testing

Podemos realizar pruebas para verificar el funcionamiento de cada componente de la tarjeta **AnaBit**. Esto incluye pruebas de **los pines GPIO**, **la comunicación UART con los módulos RF** y **la lectura del almacenamiento externo MicroSD**.

## **Test de Pines GPIO**

Para realizar la prueba de los pines **GPIO**, es necesario probar uno por uno. Por lo tanto, debemos realizar la siguiente conexión para cada pin a probar:

- Conecta el pin GPIO que deseas probar en AnaBit a un **LED** o cualquier otro componente que pueda indicar su estado.
- Conecta una **resistencia** apropiada en serie con el LED para limitar la corriente.
- Conecta el otro extremo de la resistencia al pin **GND** (tierra) de **AnaBit**.

<center><img src="../assets/Imagenes/Conexion_TestGPIO.png" alt="drawing" /></center>

Asegúrate de repetir este proceso de conexión para cada pin GPIO que desees probar en AnaBit. Esto te permitirá observar el estado del pin a través del LED u otro componente conectado.

Puedes utilizar el siguiente código, llamado "[Test_GPIO_OUTPUT.ino](https://github.com/N0c7u4/AnaBit_IoT/blob/master/Algoritmos/Test/Test_GPIO_OUTPUT/Test_GPIO_OUTPUT.ino)", que se muestra a continuación. Este código prueba los pines GPIO en modo de salida digital. Después de cargar el código en **AnaBit**, simplemente abre el **monitor serial** y escribe el número del pin GPIO que deseas probar.

```C title="Test_UART_ModulosRF.ino"
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
```

## **Test de Comunicación UART con los Módulos RF**

Para verificar una correcta comunicación con los módulos RF, puedes utilizar el siguiente código llamado "[Test_UART_ModulosRF.ino](https://github.com/N0c7u4/AnaBit_IoT/blob/master/Algoritmos/Test/Test_UART_ModulosRF/Test_UART_ModulosRF.ino)".

```C title="Test_UART_ModulosRF.ino"
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
```

Una vez cargado el código mencionado, se procede a abrir el monitor serial y escribir los siguientes comandos:

=== "LoRa"
~~~Bash title="comando"
Test LoRa
~~~

    <div class="result" markdown>

    ~~~bash  title="retorna"
    +AT: OK
    ~~~

    </div>

=== "Sigfox"
~~~Bash title="comando"
Test Sigfox
~~~

    <div class="result" markdown>

    ~~~bash  title="retorna"
    OK
    ~~~

    </div>

=== "Zigbee"
~~~Bash title="comando"
Test Zigbee
~~~

    <div class="result" markdown>

    ~~~bash  title="retorna"
    OK
    ~~~

    </div>

## **Test de Almacenamiento Externo con MicroSD**

La tarjeta AnaBit cuenta con un slot para microSD con el fin de poder almacenar datos recopilados en nuestro proyecto. Esto nos permite visualizar esos datos tanto en los códigos programados en AnaBit como en un ordenador al insertar la tarjeta microSD en este. A continuación se muestra el siguiente código llamado "[Test_MicroSD.ino](https://github.com/N0c7u4/AnaBit_IoT/blob/master/Algoritmos/Test/Test_MicroSD/Test_MicroSD.ino)".

```C title="Test_MicroSD.ino"
/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Test Almacenamiento Externo MicroSD
* @Funcionamiento : Copile el algoritmo en AnaBit y listo
*
*
**/
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;
const int CS = 5; // pin usado para AnaBit

void WriteFile(const char * path, const char * message){
  // abrirmos el archivo
  myFile = SD.open(path, FILE_WRITE);
  // escribimos en el archivo
  if (myFile) {
    Serial.printf("Writing to %s ", path);
    myFile.println(message);
    myFile.close();
    Serial.println("completed.");
  }
  // error al escribir el archivo
  else {
    Serial.println("error opening file ");
    Serial.println(path);
  }
}


void ReadFile(const char * path){
  // abrirmos el archivo
  myFile = SD.open(path);
  if (myFile) {
     Serial.printf("Reading file from %s\n", path);
     // leemos el archivo
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  }
  else {
    // error al abrir el archivo
    Serial.println("error opening test.txt");
  }
}

void setup() {
  Serial.begin(9600);
  delay(500);
  while (!Serial) { ; }
  Serial.println("Initializing SD card...");
  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  WriteFile("/test.txt", "Prueba Completada!!! ");
  ReadFile("/test.txt");
}

void loop() {

}
```

Después de ejecutar el código mencionado, podemos proceder a abrir el monitor serial y reiniciar la tarjeta **AnaBit** utilizando el botón de reset. Esto reiniciará la ejecución del código y mostrará en el monitor serial la frase "**Prueba Completada!!!**" que se ha agregado al archivo "**test.txt**".

<center><img src="../assets/Imagenes/MonitorSerial_Test_MicroSD.jpeg" alt="drawing" /></center>

Luego, para visualizar y verificar la creación de dicho archivo y el texto contenido en él, se inserta la tarjeta microSD en el ordenador y se monta la memoria. Al hacerlo, se podrá visualizar el archivo "**test.txt**" y al abrirlo se podrá observar el texto escrito, que es "**Prueba Completada!!!**".

=== "test.txt"
<center><img src="../assets/Imagenes/Archivo_Test_MicroSD.png" alt="drawing" /></center>
=== "Prueba Completada!!!"
<center><img src="../assets/Imagenes/Texto_Test_MicroSD.png" alt="drawing" /></center>
