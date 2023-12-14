# Modo OTA

La interfaz OTA (<a href="https://www.analog.com/en/analog-dialogue/articles/over-the-air-ota-updates-in-embedded-microcontroller-applications.html" target="_blank" class="hljs-tag">Over-The-Air</a>) en la tarjeta de desarrollo IoT **AnaBit** se refiere a la capacidad de actualizar su **firmware** o **software** de forma **inalámbrica**, sin necesidad de conexiones físicas como cables o puertos de programación.

Esta funcionalidad resulta especialmente beneficiosa en el contexto de **Internet de las cosas** (IoT), ya que los dispositivos basados en la tarjeta AnaBit pueden estar ubicados en lugares remotos o de difícil acceso. La **interfaz OTA** permite la **actualización** y mejora del firmware de manera conveniente y eficiente.

## **Programación de la Interfaz OTA en AnaBit**

Para habilitar la interfaz OTA en **AnaBit**, es necesario programarla dentro del algoritmo que agregamos al dispositivo. Para ello, debemos agregar las siguientes líneas de código al programa que cargaremos en AnaBit, el archivo base tiene como nombre "[Test_ConfigOTA.ino](https://github.com/N0c7u4/AnaBit_IoT/blob/master/Algoritmos/Test/Test_ConfigOTA/Test_ConfigOTA.ino)". Es importante tener en cuenta que la interfaz OTA **ocupará un espacio de memoria adicional**, por lo que es posible que el proyecto se vea afectado si ya se está utilizando toda la memoria disponible para la programación de AnaBit.

```C title="Test_ConfigOTA.ino"
/**
* @Autor : St3v3n-4n4
* @Modificacion : 20-06-2023
* @Commit : Configuracion de la interfaz de OTA
* @Funcionamiento : Copile el algoritmo en AnaBit y listo
*
*
**/
#include <WiFi.h>
#include <ESPmDNS.h>

#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid    = "miSSID";
const char* password = "miPASSWORD";

void setup() {
  // Velocidad de comunicacion serial con el PC
  Serial.begin(115200);
  Serial.println("Cargando sistema...");
  WiFi.mode(WIFI_STA);
  // Conectandose a la red Wifi
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Error con Wifi, reiniciando...");
    delay(5000);
    ESP.restart();
  }

  // Puerto de programacion, defecto 3232
  ArduinoOTA.setPort(3232);

  // Nombre en Red, defecto esp3232-[MAC]
  ArduinoOTA.setHostname("AnaBit-02");

  // Controaseña, defecto no contraseña
  ArduinoOTA.setPassword("AnaBit001");
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3"); // puede usarce un HASH

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else {  // U_FS
      type = "filesystem";
    }

    Serial.println("Iniciando Programación " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nTerminando");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progreso: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });

  // inicializamos el OTA
  ArduinoOTA.begin();
  // datos de la conexion Wifi
  Serial.println("Listo");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Activamos el OTA
  ArduinoOTA.handle();
}
```

Antes de cargar el código en **AnaBit**, es necesario **modificar** la siguiente línea.

```C
const char* ssid    = "miSSID";
const char* password = "miPASSWORD";
```

La configuración debe incluir la sustitución de "**miSSID**" y "**miPASSWORD**" por el nombre de la red WiFi y la contraseña correspondiente. Esto permitirá que **AnaBit** se conecte a la red WiFi y establezca una conexión con el ordenador para actualizar el código a través de **la interfaz OTA**.

## **Verificacion de activacion de la Interfaz OTA en AnaBit**

Para verificar que la interfaz OTA está activada en AnaBit, nos dirigimos al IDE de Arduino. A continuación, seleccionamos la opción "**Herramientas**" y luego nos dirigimos a "**Puerto**". Allí, podremos observar el puerto de red con la IP de nuestra Tarjeta AnaBit. A continuación, se muestra una imagen de cómo se ve antes de subir el código de configuración de la interfaz OTA y otra imagen después de subir el código.

=== "Antes de la interfaz OTA"
<center><img src="../assets/Imagenes/sin_OTA_IDE_Arduino.jpeg" alt="drawing"/></center>
=== "Después de la interfaz OTA"
<center><img src="../assets/Imagenes/con_OTA_IDE_Arduino.jpeg" alt="drawing"/></center>

Tambien se puede observar de otra forma justo en la seccion superior del **IDE de Arduino** podemos ver los puertos, el cual se puede notar la conexion con la **interfaz USB** o la conexion con la **interfaz OTA**.

<center><img src="../assets/Imagenes/Otra_Forma_OTA_IDE_Arduino.jpeg" alt="drawing" /></center>

Solo queda agregar esta sección de código a nuestros proyectos y cada **AnaBit** implementada podrá actualizar su programación a través de WiFi utilizando la **interfaz OTA**.
