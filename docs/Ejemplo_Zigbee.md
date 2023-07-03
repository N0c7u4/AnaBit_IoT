# Comunicación con Zigbee

## **Red Zigbee protocolo Zigbee 3.0**

El protocolo **Zigbee 3.0** es compatible con diferentes topologías de redes, como **malladas**, en **estrella** y comunicación **punto a punto**. En la red mallada de Zigbee 3.0, hay tres tipos de dispositivos de red: el **Coordinador**, el **Router** y el **dispositivo final**.

El **Coordinador** tiene la función de establecer conexiones y enlaces con los Routers y dispositivos finales. Los **Routers** se encargan principalmente de enrutar los paquetes que les llegan y de ampliar la cobertura de la red. Si la comunicación entre el Coordinador y un dispositivo final no puede establecerse debido a distancias largas, los Routers pueden extender la cobertura hasta el dispositivo final, permitiendo así una red con un área de cobertura más amplia. Por último, están los **dispositivos finales**, que se encargan de enviar información de los sensores o recibir acciones para ejecutar en los actuadores.

<center class="image-link2" >
<img src="../assets/Imagenes/Zigbe_red_Topologia_blanco_3.svg" alt="drawing" onclick="showImagePopup(this)" width="60%" height="60%" />
<span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Zigbe_red_Topologia_blanco_3.svg')">&#128269;</span>
</center>


## **Configuración del tipo de dispositivo con AnaBit**

En este ejemplo, crearemos una conexión entre un **Coordinador** y un **dispositivo final** utilizando dos tarjetas **AnaBit**. Esto se puede ampliar a una red mallada completa con 10 o 100 tarjetas AnaBit. La configuración del Router y el dispositivo final es muy similar, la diferencia radica en la selección del tipo de dispositivo en el módulo de radio Zigbee.

Es importante destacar que el módulo de radio Zigbee utilizado en las tarjetas AnaBit tiene la peculiaridad de poder **configurarse como cualquiera de los tres tipos de dispositivos**: ***Coordinador***, ***Router*** o ***dispositivo final***.

Para este ejemplo, configuraremos cada tarjeta AnaBit y enviaremos mensajes tanto entre el **dispositivo final** y el **Coordinador**, como del **Coordinador** al **dispositivo final**.

<center>
<img src="../assets/Imagenes/Ejemplo2.svg" alt="drawing"width="60%" height="60%" />
</center>

Para la configuración, se utiliza un código para programar el ESP32 como intermediario y enviar los comandos AT directamente al módulo de Zigbee. A continuación, se muestra un ejemplo de cómo se puede realizar esta configuración:

~~~C title="ZigbeeConfig.ino"
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
~~~


el codigo ejecuta un proceso de configuración para establecer la comunicación utilizando el protocolo **Zigbee 3.0**, se pueden observar las respuestas en el **monitor serial** de cada Tarjeta **AnaBit**. En este monitor, se muestra el flujo de configuración necesario para lograr la comunicación deseada.

A medida que se lleva a cabo la configuración, se pueden visualizar en el monitor serial las distintas etapas y mensajes que indican el progreso del proceso. Esto incluye la configuración de cada dispositivo como **Coordinador** y **dispositivo final**, así como la asignación de direcciones y la creación de conexiones entre ellos.

El monitor serial permite **verificar** que la configuración se está realizando correctamente y proporciona retroalimentación en tiempo real sobre el estado de cada dispositivo y su participación en la red Zigbee. Al seguir el flujo de configuración en el monitor serial, se pueden identificar posibles errores o problemas y realizar ajustes necesarios para lograr una comunicación exitosa utilizando el protocolo **Zigbee 3.0**.

Los comandos AT a configurar son los siguientes para la "**Tarjeta Coordinador**" y la "**Tarjeta Dispositivo Final**" se muestran a continuacion.

=== "Tarjeta Coordinador"
    ~~~C title="Coordinador Comando AT"
    14:33:17.056 -> comando: +AT
    14:33:18.085 -> AT_MODE
    14:33:18.085 -> 
    14:33:39.945 -> comando: AT+STOP
    14:33:40.940 -> OK
    14:33:40.940 -> 
    14:33:45.893 -> comando: AT+LEAVE
    14:33:46.890 -> OK
    14:33:46.890 -> 
    14:33:48.112 -> BOOT=0
    14:33:48.145 -> VERSION=10
    14:33:48.145 -> AT_MODE
    14:33:48.145 -> 
    14:33:59.727 -> comando: AT+DEVTYPE=0
    14:34:00.724 -> OK
    14:34:00.724 -> 
    14:34:12.622 -> comando: AT+RESET
    14:34:13.618 -> OK
    14:34:13.618 -> 
    14:34:14.778 -> BOOT=0
    14:34:14.778 -> VERSION=10
    14:34:14.778 -> AT_MODE
    14:34:14.778 -> 
    14:34:20.759 -> comando: AT+INFO?
    14:34:21.786 -> VERSION=10
    14:34:21.786 -> DATE:20220928
    14:34:21.786 -> NO NET
    14:34:21.786 -> TYPE=Coordinate
    14:34:21.786 -> MAC=0xB4E3F9FFFE425E3B
    14:34:21.786 -> 
    14:36:02.201 -> comando: AT+JOIN
    14:36:03.198 -> OK
    14:36:03.198 -> 
    14:36:05.577 -> NET:LINK
    14:36:05.577 -> NETOPEN:180-Sec
    14:36:05.577 -> 
    14:36:17.057 -> JOIN:MAC=0xB4E3F9FFFE42611D
    14:36:17.057 -> NODE:MAC=0xB4E3F9FFFE42611D,ADDR=0x8309
    14:36:17.057 -> 
    14:36:39.855 -> comando: AT+INFO?
    14:36:40.885 -> VERSION=10
    14:36:40.885 -> DATE:20220928
    14:36:40.885 -> TYPE=Coordinate
    14:36:40.885 -> MAC=0xB4E3F9FFFE425E3B
    14:36:40.885 -> PANID=0x0946
    14:36:40.885 -> CHANNEL=15
    14:36:40.885 -> ADDR=0x0000
    14:36:40.885 -> 
    14:37:14.329 -> comando: AT+DSTADDR=8309
    14:37:15.326 -> OK
    14:37:15.359 -> 
    14:37:23.784 -> comando: AT+DSTADDR?
    14:37:24.783 -> DSTADDR=0x8309
    14:37:24.783 -> 
    14:38:19.252 -> comando: AT+SEND
    14:38:20.249 -> SEND_MODE
    14:38:20.249 -> 
    14:39:06.102 -> comando: coordinador enviando mensaje a EndDevice con ADDR=8309
    14:39:07.130 -> OK
    14:39:51.094 -> Dispositivo Final enviando respuesta a Coordinador con ADDR=0000
    ~~~   

=== "Tarjeta Dispositivo Final"
    ~~~C title="Dispositivo FInal Comando AT"
    14:34:46.077 -> comando: +AT
    14:34:47.090 -> AT_MODE
    14:34:47.090 -> 
    14:34:55.745 -> comando: AT+STOP
    14:34:56.752 -> OK
    14:34:56.752 -> 
    14:35:04.959 -> comando: AT+LEAVE
    14:35:05.963 -> OK
    14:35:05.963 -> 
    14:35:08.103 -> BOOT=0
    14:35:08.103 -> VERSION=10
    14:35:08.103 -> AT_MODE
    14:35:08.103 -> 
    14:35:23.171 -> comando: AT+DEVTYPE=2
    14:35:24.179 -> OK
    14:35:24.179 -> 
    14:35:31.355 -> comando: AT+RESET
    14:35:32.391 -> OK
    14:35:32.391 -> 
    14:35:33.531 -> BOOT=0
    14:35:33.531 -> VERSION=10
    14:35:33.531 -> AT_MODE
    14:35:33.531 -> 
    14:35:38.976 -> comando: AT+INFO?
    14:35:39.981 -> VERSION=10
    14:35:39.981 -> DATE:20220928
    14:35:39.981 -> NO NET
    14:35:39.981 -> TYPE=EndDevice
    14:35:39.981 -> MAC=0xB4E3F9FFFE42611D
    14:35:39.981 -> 
    14:36:13.818 -> comando: AT+JOIN
    14:36:14.824 -> OK
    14:36:14.824 -> 
    14:36:22.895 -> NET:JOIN
    14:36:22.895 -> 
    14:36:31.048 -> comando: AT+INFO?
    14:36:32.055 -> VERSION=10
    14:36:32.055 -> DATE:20220928
    14:36:32.055 -> TYPE=EndDevice
    14:36:32.087 -> MAC=0xB4E3F9FFFE42611D
    14:36:32.087 -> PANID=0x0946
    14:36:32.087 -> CHANNEL=15
    14:36:32.087 -> ADDR=0x8309
    14:36:32.087 -> 
    14:37:44.893 -> comando: AT+DSTADDR=0000
    14:37:45.895 -> OK
    14:37:45.895 -> 
    14:37:52.012 -> comando: AT+DSTADDR?
    14:37:53.049 -> DSTADDR=0x0000
    14:37:53.049 -> 
    14:38:05.497 -> comando: AT+SEND
    14:38:06.508 -> SEND_MODE
    14:38:06.508 -> 
    14:39:07.094 -> coordinador enviando mensaje a EndDevice con ADDR=8309
    14:39:50.004 -> comando: Dispositivo Final enviando respuesta a Coordinador con ADDR=0000
    14:39:51.040 -> OK
    ~~~

## **Ejemplo de proyecto con AnaBit**

Una vez que los módulos están configurados, es posible crear algoritmos para implementar proyectos. A continuación, se muestra un ejemplo de comunicación entre un dispositivo final y el coordinador. En este caso, el dispositivo final envía al coordinador el valor del campo magnético obtenido por el sensor Hall integrado en el ESP32. El coordinador guarda esta información en una tarjeta microSD en un formato adecuado para ser visualizado en una tabla de Excel. Para lograr esto, se han creado dos códigos, uno para cada tarjeta AnaBit, que se presentan a continuación:

=== "Tarjeta Coordinador"
    ~~~C title="Coordinador Comando AT"
    /**
    * @Autor : St3v3n-4n4
    * @Modificacion : 20-06-2023
    * @Commit : Zigbee Coordinate
    * @Funcionamiento : Copile el algoritmo en AnaBit 
    *                   Inicie el Monitor Serial con velocidad 115200 Baud
    *       
    *
    **/
    #include <SPI.h>
    #include <SD.h>
    #include <ESP32Time.h>
    #include <WiFi.h>

    ESP32Time rtc;

    File myFile;
    const int CS = 5; // pin usado para AnaBit

    // credenciales del Wifi
    const char* ssid = "Teslacreiste";
    const char* password = "60300832sS";

    const char* ntpServer = "pool.ntp.org";
    const long gmtOffset_sec = -5*3600; // GTM-5 Colombia 

    void initWiFi() {
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, password);
        Serial.print("Connecting to WiFi ..");
        while (WiFi.status() != WL_CONNECTED) {
            Serial.print('.');
            delay(1000);
        }
        Serial.println(WiFi.localIP());
    }

    void appendFile(const char * path, String message){
        // abrirmos el archivo
        myFile = SD.open(path, FILE_APPEND);
        // escribimos en el archivo
        if (myFile) {
            myFile.println(message);
            myFile.close(); 
        } 
        // error al escribir el archivo
        else {
            Serial.println("error opening file ");
            Serial.println(path);
        } 
    }   


    void writeFile(const char * path, String message){
        // abrirmos el archivo
        myFile = SD.open(path, FILE_WRITE);
        // escribimos en el archivo
        if (myFile) {
            myFile.println(message);
            myFile.close(); 
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

    void delimitar(String inputString, String delimiter, String Vstr[], int maxSize) {
        String substring;
        int delimiterIndex;
        int count = 0;  // Contador para el vector de Strings

        // Dividir la cadena en subcadenas utilizando el delimitador
        while (inputString.length() > 0 && count < maxSize) {
            delimiterIndex = inputString.indexOf(delimiter);

            if (delimiterIndex >= 0) {
            substring = inputString.substring(0, delimiterIndex);
            inputString = inputString.substring(delimiterIndex + delimiter.length());
            } else {
            substring = inputString;
            inputString = "";
            }

            Vstr[count] = substring;
            count++;
        }
    
        // Si se alcanza el tamaño máximo del vector, imprimir un mensaje de advertencia
        if (count >= maxSize) {
            Serial.println("Se alcanzó el tamaño máximo del vector.");
        }
    }   

    void setup() 
    {
        // configuracion de velocidad del puerto serial hacia el PC
        Serial.begin(115200);
        // configuracion de velocidad del puerto serial del modulo de Zigbee
        Serial2.begin(115200);

        initWiFi();
        configTime(gmtOffset_sec, 0,ntpServer);
        struct tm timeinfo;
        if(getLocalTime(&timeinfo))
        {
            rtc.setTimeStruct(timeinfo);
        }


        // iniciando SDCARD
        Serial.println("Initializing SD card...");
        if (!SD.begin(CS)) {
            Serial.println("initialization failed!");
            return;
        }
        Serial.println("initialization done.");

        writeFile("/BaseDeDatos.txt", "Fecha; ADDR; Valor Sensor Hall");
    
    }

    void loop()
    {
  
        if(Serial2.available())
        {
            String DZigbee = Serial2.readString();
            Serial.println("Mensaje Obtenido = "+DZigbee);

            if(DZigbee.indexOf("ADDR")>=0 && DZigbee.indexOf("Hall")>=0)
            {
                String V_DZigbee[10];
                delimitar(DZigbee, " ", V_DZigbee, 10);
                String ADDR = V_DZigbee[1];
                String HALL = V_DZigbee[3];
                appendFile("/BaseDeDatos.txt", rtc.getTime("%d/%m/%Y %H:%M:%S")+";"+ADDR+";"+HALL);
                ReadFile("/BaseDeDatos.txt");
            }
        }
    }
    ~~~   

=== "Tarjeta Dispositivo Final"
    ~~~C title="Dispositivo FInal Comando AT"
    /**
    * @Autor : St3v3n-4n4
    * @Modificacion : 20-06-2023
    * @Commit : Zigbee Dipositivo final
    * @Funcionamiento : Copile el algoritmo en AnaBit 
    *                   Inicie el Monitor Serial con velocidad 115200 Baud
    *       
    *
    **/
    void setup() {
        // configuracion de velocidad del puerto serial hacia el PC
        Serial.begin(115200);
        // configuracion de velocidad del puerto serial del modulo de Zigbee
        Serial2.begin(115200);
    }

    void loop() {
 
        int medida = 0;

        medida = hallRead();
    
        Serial.println("Hall: "+String(medida));
        Serial2.print("Hall: "+String(medida)+"\n");
 
        delay(3000);
    }
    ~~~


La vista del monitor serial de cada tarjeta AnaBit para este ejemplo de proyecto se muestra a continuación:


=== "Tarjeta Coordinador"
    <center class="image-link" >
    <img src="../assets/Imagenes/Zigbee_Coordinador_MonitorSerial.png" alt="drawing" onclick="showImagePopup(this)" />
    <span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Zigbee_Coordinador_MonitorSerial.png')">&#128269;</span>
    </center>
    

=== "Tarjeta Dispositivo Final"
    <center class="image-link">
    <img src="../assets/Imagenes/Zigbee_DispositivoFinal_MonitorSerial.jpeg" alt="drawing" onclick="showImagePopup(this)" />
    <span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Zigbee_DispositivoFinal_MonitorSerial.jpeg')">&#128269;</span>
    </center>

Podemos observar el archivo en un ordenador, en una hoja de cálculo, como se muestra a continuación.

=== "Importando BaseDeDatos.txt"
    <center class="image-link" >
    <img src="../assets/Imagenes/WPS_Hoja_de_calculo.png" alt="drawing" onclick="showImagePopup(this)" />
    <span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Zigbee_Coordinador_MonitorSerial.png')">&#128269;</span>
    </center>
    

=== "Visualizacion de Datos"
    <center class="image-link">
    <img src="../assets/Imagenes/WPS_Importado.png" alt="drawing" onclick="showImagePopup(this)" />
    <span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Zigbee_DispositivoFinal_MonitorSerial.jpeg')">&#128269;</span>
    </center>

<!-- Ventana emergente -->
<div id="imagePopup" class="popup-container" onclick="hideImagePopup()">
    <img id="popupImage" class="popup-image" src="" alt="popup-image" />
</div>
<script>
    function showImagePopup(img) {
    var popup = document.getElementById("imagePopup");
    var popupImage = document.getElementById("popupImage");
    popupImage.src = img.src;
    popup.style.display = "block";
    }
    function hideImagePopup() {
    var popup = document.getElementById("imagePopup");
    popup.style.display = "none";
    }
</script>

