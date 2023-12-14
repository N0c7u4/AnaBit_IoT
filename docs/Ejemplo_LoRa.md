# Comunicación con LoRa

## **Red LoRa Punto a Punto con AnaBit**

Para el ejemplo de comunicación, se crea una red punto a punto con dos tarjetas **AnaBit**. Se utilizarán dos códigos, uno para cada tarjeta. Para fines didácticos, llamaremos a una de las tarjetas AnaBit "**Tarjeta A**" y a la otra "**Tarjeta B**".

<center class="image-link2" >
<img src="../assets/Imagenes/Ejemplo_LoRa.png" alt="drawing" onclick="showImagePopup(this)" />
<span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Ejemplo_LoRa.png')">&#128269;</span>
</center>

para el codigo de la "**Tarjeta A**" consiste en recibir un texto por el ordenador usando la comunicacion serial, el cual este texto se envia por medio de la red de loRa hacia la "**Tarjeta B**", esta ultima recibira el texto y dara una respuesta, por el cual se enviara a la "**Tarjeta A**", la cual lo reenviara por comunicacion serial hacia el ordenador y se observara el texto en el monitor serial del **IDE de Arduino**.

=== "Tarjeta A"
~~~C title="LoRa_PtP_A.ino"
/**
_ @Autor : St3v3n-4n4
_ @Modificacion : 20-06-2023
_ @Commit : Comunicacion Punto a Punto LoRa
_ @Funcionamiento : Copile el algoritmo en AnaBit
_ Inicie el Monitor Serial con velocidad 115200 Baud
_  
 \*
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
        Serial.println("Esperando Mensaje en Consola...");
    }

    void loop()
    {
        if (Serial.available())
        {
            // Se recive el texto del ordenador
            String DataA = Serial.readString();
            Serial.println("Enviando: "+DataA);
            // cambio la frecuencia de transmision
            LoRaBit.Frecuencia(915);
            // Se envia el texto hacia la Tarjeta B
            LoRaBit.PtPtxSTR(DataA,1);
            // cambio la frecuencia de recepcion
            LoRaBit.Frecuencia(470);
            // Se configura la recepcion del texto
            LoRaBit.PtPrx();
        }
        // Se deja en escucha a la espera de la respuesta de la Tarjeta B
        if(LoRaBit.available())
        {
            String datos = LoRaBit.readString();
            datos = LoRaBit.msgRX(datos, "ASCII");
            Serial.println("Resepcion: "+datos);
        }
    }
    ~~~

=== "Tarjeta B"
~~~C title="LoRa_PtP_B.ino"
/**
_ @Autor : St3v3n-4n4
_ @Modificacion : 20-06-2023
_ @Commit : Comunicacion Punto a Punto LoRa
_ @Funcionamiento : Copile el algoritmo en AnaBit
_ Inicie el Monitor Serial con velocidad 115200 Baud
_  
 \*
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
    ~~~

Se puede observar la librería implementada llamada **AnaBitLoRa.h**, la cual está específicamente diseñada para el módulo RF RHF76-052DM de LoRa incorporado en la tarjeta AnaBit. Esta librería ha sido creada por mí y puede encontrarse en el siguiente repositorio ([N0c7u4/AnaBitLoRa](https://github.com/N0c7u4/AnaBitLoRa)). Con esta librería, es posible establecer una comunicación punto a punto utilizando el módulo LoRa incorporado en **AnaBit** con tan solo unas pocas líneas de código.

Además, la librería permite configurar el modo **depurador**, lo cual implica que las respuestas de cada **comando AT** enviado al módulo RF se recibirán a través del monitor serial. Esto facilita la depuración y el seguimiento de la comunicación entre las tarjetas AnaBit, y permite verificar el correcto funcionamiento del módulo LoRa, como se muestra en las siguientes imágenes de los monitores seriales de la **tarjeta A** y la **tarjeta B**.

=== "Tarjeta A"
<center class="image-link" >
<img src="../assets/Imagenes/Ejemplo_LoRa_PtP_TarjetaA.jpeg" alt="drawing" onclick="showImagePopup(this)" />
<span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Ejemplo_LoRa_PtP_TarjetaA.jpeg')">&#128269;</span>
</center>

=== "Tarjeta B"
<center class="image-link">
<img src="../assets/Imagenes/Ejemplo_LoRa_PtP_TarjetaB.png" alt="drawing" onclick="showImagePopup(this)" />
<span class="zoom-icon" onclick="showImagePopup(this.parentElement.querySelector('img'), '../assets/Imagenes/Ejemplo_LoRa_PtP_TarjetaA.jpeg')">&#128269;</span>
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

Es importante destacar que, para la **tarjeta A**, se **_transmite_** el mensaje a **915MHz** y se **_recibe_** la respuesta de la tarjeta B a **470MHz**. En sentido contrario, para la **tarjeta B**, se **_transmite_** a **470MHz** y se **_reciben_** los mensajes de la tarjeta A a **915MHz**. Esto aprovecha el uso de ambas antenas incorporadas en **AnaBit** para establecer una comunicación punto a punto efectiva.
