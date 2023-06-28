# Conexiones y Arquitectura

## Diagrama Pinout

El diagrama pinout de **AnaBit** muestra claramente los pines numerados y sus respectivas funciones. Por ejemplo, puede incluir pines de alimentación que suministran energía a la tarjeta, pines de entrada/salida que permiten la comunicación con otros dispositivos, pines de conexión para sensores, actuadores u otros periféricos, pines de tierra para establecer una referencia común, entre otros.

![](assets/Imagenes/PinI-O_AnaBitRef.png)

## Tabla GPIO

|<center>Funsion</center>                       |<center>N° GPIO</center>|<center>N° Pin</center> |<center>N° Pin</center> |<center>N° GPIO</center>|<center>Funcion</center>             |
|-----------------------------------------------|------------------------|------------------------|------------------------|------------------------|-------------------------------------|
|<center>Alimenatación</center>                 |<center>3V3</center>    |<center>1</center>      |<center>2</center>      |<center>GND</center>    |<center>Tierra Comun</center>        |
|<center>ADC1_0/Pin_I</center>                  |<center>36</center>     |<center>3</center>      |<center>4</center>      |<center>39</center>     |<center>ADC1_3/Pin_I</center>        | 
|<center>ADC1_6/Pin_I</center>                  |<center>34</center>     |<center>5</center>      |<center>6</center>      |<center>35</center>     |<center>ADC1_7/Pin_I</center>       |    
|<center>ADC2_0/Pin_IO/touch0</center>          |<center>4</center>      |<center>7</center>      |<center>8</center>      |<center>2</center>      |<center>ADC2_2/Pin_IO/touch2</center>| 
|<center>ADC2_3/Pin_IO/HSPI_CS/touch3</center>  |<center>15</center>     |<center>9</center>      |<center>10</center>     |<center>13</center>     |<center>ADC2_4/Pin_IO/HSPI_MOSI/touch4</center>| 
|<center>ADC2_5/Pin_IO/HSPI_MISO/touch5</center>|<center>12</center>     |<center>11</center>     |<center>12</center>     |<center>14</center>     |<center>ADC2_6/Pin_IO/HSPI_CLK/touch6</center>| 
|<center>ADC2_7/Pin_IO/touch7</center>          |<center>27</center>     |<center>13</center>     |<center>14</center>     |<center>25</center>     |<center>ADC2_8/Pin_IO/DAC1</center>| 
|<center>ADC2_9/Pin_IO/DAC2</center>            |<center>26</center>     |<center>15</center>     |<center>16</center>     |<center>GND</center>    |<center>Tierra Comun</center>|   
|<center>Alimenatación</center>                 |<center>3V3</center>    |<center>17</center>     |<center>18</center>     |<center>GND</center>    |<center>Tierra Comun</center>| 
|<center>Pin_IO</center>                        |<center>6</center>      |<center>19</center>     |<center>20</center>     |<center>7</center>      |<center>Pin_IO</center>| 
|<center>Pin_IO</center>                        |<center>8</center>      |<center>21</center>     |<center>22</center>     |<center>11</center>     |<center>Pin_IO</center>| 
|<center>I2C_SDA/Pin_IO</center>                |<center>21</center>     |<center>23</center>     |<center>24</center>     |<center>22</center>     |<center>I2C_SCL/Pin_IO</center>| 
|<center>Alimentacion Input</center>            |<center>VIN</center>    |<center>25</center>     |<center>26</center>     |<center>GND</center>    |<center>Tierra Comun</center>| 

## Arquitectura de Hardware

![](assets/Imagenes/Arquitectura%20de%20hardware%20de%20la%20tarjeta%20de%20desarrollo%20IoT-Pintar.png)
