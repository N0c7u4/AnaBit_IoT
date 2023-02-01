# Comandos MACH3 (Código G & Código M)

El código G y el código M se clasifican en grupos de códigos, que son los siguientes...

-> Referencias -> [Mach3-GCOde-Lenguej-Reference.pdf](../img/Mach3-GCode-Language-Reference.pdf)

## Código G

### `Grupo 1`

- estos son los códigos que conforman al grupo 1 del código G, estos son los encargados del `MOVIMIENTO`

|     Código G          |        Sintaxis        | Ejemplo             | Descripción                                                            |
|-----------------------|------------------------|---------------------|------------------------------------------------------------------------|
|`G00`                    | G00 X~Y~Z~A~B~C        | G00 X20.0450        |  Posicionamiento Lineal Rápido  |
|`G01`                    | |  Interpolación lineal para alimentación de corte |
|`G02`                    | |  Interpolación circularen sentido horario |
|`G03`                    | |  Interpolación circular en sentido antihorario|
|`G38.2`                  | |  Sondea hacia un objetivo y se detiene al contacto, lo que indica un error si alcanza la posición del objetivo sin activar la sonda|
|`G80`                    | |  Cancelar el modo de movimiento (incluidos los ciclos fijos)|
|`G81`                    | |  Ciclo fijo - perforación|
|`G82`                    | |  Ciclo fijo - taladrado con detención|
|`G84`                    | |  Ciclo fijo - roscado rígido a la derecha|
|`G85`                    | |  Ciclo de rimado|
|`G86`                    | |  Ciclo enlatado - mandrinado|
|`G87`                    | |  Ciclo de barrenado|
|`G88`                    | |  Ciclo de machuelado|
|`G89`                    | |  Ciclo de rimado|

#### **Referencia**

`1` [G38.2-G38.5 - Objetivo de la sonda](https://marlinfw.org/docs/gcode/G038.html)
`2` [CODIGOS G-M TORNO CNC DYNA](https://www.studocu.com/co/document/universidad-tecnologica-de-pereira/manufactura-ii/codigos-g-m/23322361)
`3` [Instrucción G81 (Ciclo fijo de taladrado)](https://www.programacioncnc.es/instruccion-g81-ciclo-fijo-de-taladrado/)
`4` [MACH3 Comandos](https://machmotion.com/documentation/Software/Mach3/Mach3%20G-Code%20Manual.pdf)
`5` [Topic: G82 Drilling Cycle](https://www.machsupport.com/forum/index.php?topic=43395.0)
`6` [G & M Code  REFERENCE MANUAL](https://machmotion.com/downloads/GCode/Mach3-GCode-Language-Reference.pdf)

