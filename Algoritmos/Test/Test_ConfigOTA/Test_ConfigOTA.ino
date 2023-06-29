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