# Configuración del IDE de Arduino

Para poder programar AnaBit una de las formas es usando el lenguaje que usa las tarjetas Arduino, por consiguiente, se usa el IDE de Arduino V2 por preferencia, sin embargo es compatible con la version 1. para poder subir un programa a AnaBit con el IDE de Arduino se debe seleccionar el tipo de tarjeta, sin embargo, por defecto no esta instalado, por consiguiente, se realiza la instalacion siguiendo los siguientes pasos:

## **Configuración de la URL de Gestión de Placas**

Nos dirigimos a la pestaña de "**Archivo**" en el IDE de Arduino.

<center><img src="../assets/Imagenes/archivos_IDE_Arduino.jpeg" alt="drawing" /></center>

Luego, seleccionamos la opción "**Preferencias**" y en la parte inferior de la ventana emergente, ubicamos la sección "**URL adicionales de gestor de placas:**". A continuación, agregamos la siguiente URL: 

~~~URL
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
~~~

<center>
    <img src="../assets/Imagenes/preferencia_IDE_Arduino.jpeg" alt="drawing" />
    <img src="../assets/Imagenes/URL_IDE_Arduino.jpeg" alt="drawing" />
</center>

## **Configuración del Gestor de Placas**

Nos dirigimos al gestor de placas que se encuentra en la parte **superior izquierda** del IDE de Arduino.

<center><img src="../assets/Imagenes/Gestor_placas_IDE_Arduino.jpeg" alt="drawing" /></center>

En el gestor de placas, realizamos una búsqueda utilizando el nombre "**esp32**". Localizamos el paquete completo llamado "**ESP32 de Espressif Systems**" y procedemos a instalarlo.

<center>
    <img src="../assets/Imagenes/Busqueda_Placas_IDE_Arduino.jpeg" alt="drawing" />
    <img src="../assets/Imagenes/Instalacion_Paquetes_ESP32_IDE_Arduino.jpeg" alt="drawing" />
</center>

## **Tipo de Placa para la Programación de AnaBit**

Después de completar la instalación en el gestor de placas, conectamos **AnaBit** al ordenador mediante USB. A continuación, seleccionamos el tipo de tarjeta llamada "**DOIT ESP32 DEVKIT V1**" en el IDE de Arduino. Esta selección es apropiada, ya que AnaBit tiene como MCU principal el **ESP32-WROOM-32**.

<center>
    <img src="../assets/Imagenes/Puerto_IDE_Arduino.jpeg" alt="drawing" />
    <img src="../assets/Imagenes/DOIT_ESP32_IDE_Arduino.jpeg" alt="drawing" />
</center>

<h2><span style="font-family: 'Roboto', sans-serif; font-size: 34px;"><strong>¡Y listo! Nuestro IDE de Arduino está configurado para programar a AnaBit.</strong></span></h2>

