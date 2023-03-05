# FreeCAD

FreeCAD es multiplataforma y es un software gratuito y tiene la filosofia de software libre...

# Instalacion en Arch Linux

Para la instalacion de freecad en arch linux se usara el siguiente comando...

```bash
sudo pacman -S freecad
```

y listo...

# Instalacion en Windows 

Para la instalacion de freecad en Windows 10 se tiene que ir a la pagina oficial de FreeCAD que es la siguiente...

[freecad.org](https://www.freecad.org/downloads.php?lang=es_ES)

Luego seleccionamos descargar para windows y este nos dara su instalador...

> NOTA: Se debe instalar python3 y instalar el programa en el disco donde este el windows por lo general en el `Disco :C` 

# Insterfaz de FreeCAD

![](../../img/Pasted%20image%2020230219160253.png)

# Temas de la interfaz de FreeCAD

Para configurar los temas ingresaremos al apartado de preferencia que se encuentra en la barra de herramientas superior izquierda en el boton `editar` , esta tiene la siguiente direccion...

```
Editar/Preferencia...
```

Esto nos mostrara la siguiente ventana...

![](../../img/Pasted%20image%2020230219160554.png)

en la seccion `general` vemos en la pestaña `general` que en el apartado de `ventana principal` dentro de esta esta `Hoja de estilo` donde podremos escoger el estilo de la interfaz como se quiera...

por ejemplo el estilo `behave-dark` que se muestra en la siguiente imagen...

![](../../img/Pasted%20image%2020230219160757.png)

# Configuracion del entorno de Trabajo

Por defecto FreeCAD posee algunos incomvenientes que dificultad un poco el trabajo del diseño en 3D de la pieza, entonces para esto es necesario configurar el apartado de `preferencias`...

## Cambio del modulo por defecto a `Part Design`

Para el cambio tendremos que ir a la seccion de `iniciar` en `preferencias` y cambiar la linea de `Carga automatica del modulo despues de iniciar`  como se muestra en la siguiente imagen...

![](../../img/Pasted%20image%2020230219161219.png)

## Configuracion de Unidades

Ya que para usar modelos que se puedan usar una `CNC` para su construccion tendremos que configurar las unidades en `minutos` y `milimetros` , para esto tendremos que estar en el apartado `General` y luego dirigirnos a la pestaña de `unidades` y cambiar la linea que tiene como nombre `Unidad de sistema` y cambiarla por `Pieza pequeñas que son métricas & CNC (mm, mm/min)` como muestra la siguiente imagen...

![](../../img/Pasted%20image%2020230219162325.png)

## Agregar Escenarios (`Path`, `Sketcher`)

Para agregar mas Escenarios se puede ir al apartado de `escenarios` y luego seleccionar el escenario `Path`, como se muestra en la siguiente imagen...

![](../../img/Pasted%20image%2020230219161831.png)

Luego de cargar el escenario nos mostrara de la siguiente forma la ventana de preferencias...

![](../../img/Pasted%20image%2020230219162514.png)

Ahora tambien tenemos que agregar el `sketcher` de la siguiente forma, como se muestra en la siguiente imagen...

![](../../img/Pasted%20image%2020230219163102.png)

Esto nos arrojara en la barra lateral lo siguiente...

![](../../img/Pasted%20image%2020230219163144.png)

listo hemos agregado todos los escenarios basicos...

## Configuracion del Diseño de Piezas

Esto es para que una pieza si esta alineado y pegado con otra piesa la cara donde se juntan las dos no quede con una linea dividiendo esa cara, en cambio, esta cara se funsiones y solo quede una cara y no dos...

Para esto nos dirigimos en el apartado de `Part/Part Design` y en la pestaña de `General` seleccionamos todos las `3 opciones` que se muestran en la siguiente imagen...

![](../../img/Pasted%20image%2020230219163244.png)

## Configuracion del Croquizador

Esta configuracion nos permitira evitar que la pieza se oculte cuando estamos en este modo puesto que la pieza ya existente se oculta...

Para esto tendremos que ir al apartado de `croquizador` y la pestaña de `mostrar` en la seccion de `visibilidad automatica` deseleccionamos la linea `Ocultar todos los objetos que dependen del croquis`, como se muestra en la siguiente imagen...

![](../../img/Pasted%20image%2020230219163634.png)

Listo le damos aplicar y listo...




