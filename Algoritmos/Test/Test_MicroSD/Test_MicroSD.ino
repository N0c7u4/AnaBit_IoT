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