
# Controlador BL-UsbMach-V2.1

![](../img/f1774bbb5ef5f8537a108f5befbb1110.jpeg)

![](../img/bl5breakoutboard-datasheet.pdf)

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

