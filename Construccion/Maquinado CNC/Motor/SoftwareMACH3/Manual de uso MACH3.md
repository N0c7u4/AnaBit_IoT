
# Controlador BL-UsbMach-V2.1

![](../img/f1774bbb5ef5f8537a108f5befbb1110.jpeg)

[datasheet.pdf](../img/bl5breakoutboard-datasheet.pdf)


# Configuración de perfiles en MACH3

Cuando se inicia el programa, este nos muestra la siguiente ventana...

Para la creación del perfil le damos al botón ``Create Profile``

![](../img/Pasted%20image%2020230128182146.png)

luego nos abrirá otra ventana que es la siguiente...

`Hay que tener en cuenta`, seleccionar `Default Profile Values` 

![](../img/Pasted%20image%2020230128183332.png)

Luego aparecerá en la lista de perfiles mencionada anterior mente

![](../img/Pasted%20image%2020230128183448.png)
Al `seleccionarlo` y darle en `OK` nos aparece la siguiente venta, que nos habla de los términos de licencia del programa, los "leemos" y si no quiere que vuelva a aparecer le damos en... 

- [x] `Please do not ask this again, I will always agree.`

y luego aceptamos los términos y condiciones -> `I Agree to all terms of this agreement`

![](../img/Pasted%20image%2020230128183646.png)

Luego nos aparecerá la siguiente ventana, que nos menciona que controlador vamos a usar en este caso usaremos el `BL-UsbMach-V2.2` nuestra versiones es` V2.1` sin embargo sigue siendo compatible.

![](../img/Pasted%20image%2020230128183207.png)

Dependiendo de la resolución de configuración de nuestra pantalla nos mostrara la interfaz de control de MACH3 de la siguiente manera...

![](../img/Pasted%20image%2020230128184035.png)

# Configuración de Puertos & Pines

### ``Config``/``Ports and Pins``/``Port Setup and Axis Selection``

En esta ventana de configuración, se debe configurar muy bien el puerto de comunicación `Port #1`  y también debemos prestar atención y configurar de la misma manera el `kernel Speed` a `25000Hz`, como se muestra a continuación…

![](../img/Pasted%20image%2020230128185337.png)

### ``Config``/``Ports and Pins``/`Motor Outputs`

Configuramos ahora los motores paso a paso, de la siguiente manera...

![](../img/Pasted%20image%2020230128185449.png)

### ``Config``/``Ports and Pins``/`Input Signals`

Configuramos ahora el botón de `EStop` de emergencia...
		
![](../img/Pasted%20image%2020230128185535.png)

# Configuración Motor Paso a Paso

## ``Config``/``MotorTuning``

![](../img/Pasted%20image%2020230128121635.png)

Aquí se configura la ``velocidad``, ``aceleración`` y ``pasos`` de los motores de ``los ejes de la maquina X,Y,Z``.

## PERFIL DE MOVIMIENTO DEL MOTOR DE LOS EJES

este ``perfil dependerá del tipo de motor a usar``, los usados son los que se muestran en el #README

|EJE |Steps per   | Velocity (mm's per min) | Acceleration (mm's/sec/sec)|
|----|------------|-------------------------|-----------------------------|
| X  | 50         | 1000                    | 100                         |
| Y  | 50         | 1000                    | 100                         |
| Z  | 50         | 700                     | 100                         |

## Prueba de Movimiento de los EJES

para probar de forma manual los ejes `X`,`Y` y `Z`. Usaremos el `MACH3` sin abrir ninguna ventana y en la sección ``Program Run Alt-1`` oprimimos el botón del teclado ``TAB``, esto causara que emerja una pestaña a la `izquierda` de la siguiente manera...

![](../img/Pasted%20image%2020230128130323.png)

También se puede usar los botones de direcciones <- -> del teclado 

![](../img/Pasted%20image%2020230128190632.png)

`Arriba` y `Abajo` es el eje `Y` & `Derecha` `Izquierda` es el eje `X`

Para el eje `Z` usaremos los botones `Repág` (`Arriba`) & `AvPág` (`Abajo`)

La prueba se muestra a continuación en el siguiente GIF...

![](../img/WhatsApp-Video-2023-01-28-at-7.09.48-PM.gif)


# Configuración del Spindle

### ``Config``/``Ports and Pins``/``Motor Outputs``

la ``configuración`` para el uso del ``Spindle`` por medio de ``PWM`` es la siguiente...

![](../img/Pasted%20image%2020230128124348.png)

### ``Config``/``Ports and Pins``/``Spindle Setup``

Luego ``configuramos`` en control del motor, donde ``tenemos que seleccionar`` lo siguiente en la sección ``Motor Control``

- [x] Use Spindle Motor Output
- [x] PWM Control

``PWMBase Freq.`` : ``10``
``Minimum`` : ``0%``

![](../img/Pasted%20image%2020230128124755.png)

luego con solo darle clic a ``Spindle CW F5`` generara el ``PWM`` y se comunicara con la fuente regulada por PWM del Spindle...

![](../img/Pasted%20image%2020230128125454.png)

### Conexión Física

![](../img/Pasted%20image%2020230128125609.png)

``NOTA``: se debe alimentar ``el controlador MACH3`` con ``12`` o ``24V`` en la siguiente ``bornera``...

![](../img/Pasted%20image%2020230128125730.png)

# Configuración del sensor de altura Z cero

El sensor de altura consiste en la `detección de continuidad` entre `una entrada del controlador` (`int2`) y `tierra` (`GND`), para la `configuración` en el software `MACH3` es la siguiente...

### ``Config``/``Ports and Pins``/``Input Signals``

la fila `Probe` nos indica `la configuración del sensor de altura` la habilitamos como se muestra a continuación...

| signal | Enabled | Port # | Pin Number | Active Low | Emulated | Hotkey |
|-------|----------|-------|-------------|-------------|---------|-------------|
| Probe | **`x`**       |  1    |  11         |    **`x`**        |     -   |    0        |


![](../img/Pasted%20image%2020230128130835.png)

