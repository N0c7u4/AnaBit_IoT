# Comunicación con LoRa


## **Red LoRa Punto a Punto con AnaBit**

Para el ejemplo de comunicación, se crea una red punto a punto con dos tarjetas **AnaBit**. Se utilizarán dos códigos, uno para cada tarjeta. Para fines didácticos, llamaremos a una de las tarjetas AnaBit "**Tarjeta A**" y a la otra "**Tarjeta B**".

![](assets/Imagenes/Ejemplo_LoRa.png)

para el codigo de la "**Tarjeta A**" consiste en recibir un texto por el ordenador usando la comunicacion serial, el cual este texto se envia por medio de la red de loRa hacia la "**Tarjeta B**", esta ultima recibira el texto y lo modificara, por el cual se enviara a la "**Tarjeta A**", la cual lo reenviara por comunicacion serial hacia el ordenador y se observara el texto en el monitor serial del **IDE de Arduino**.

=== "Tarjeta A"
    ~~~C title="LoRa_PtP_A.ino"
    ~~~

    

=== "Tarjeta B"
    ~~~C title="LoRa_PtP_B.ino"
    ~~~



## **Red LoRa Mallada con AnaBit**