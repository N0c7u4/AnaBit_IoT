# Crear Libreria de Componentes Electronicos

Crear una libreria de componentes consiste en varios pasos que son los siguiente...

- Crear la Libreria de simbolo de nuestro componente
- Crear la libreria de la huella (footprint) del componente
- Agregar el modelo 3D del componente

> NOTA: Se puede crear mas de un simbolo por libreria ejemplo si  se añadira varios componentes como resistencias de diferente tamaño SMD entonces solo es necesario crear una libreria de simbolo y luego adentro de esta se crea todos los componentes, no es necesario agregar una libreria de simbolos por cada variacion del mismo tipo de dispositivo electronico...

> NOTA: Tambien es el mismo caso con la huella (footprint) si el chip tiene una version con THT y la otra con SMD no es necesario crear una libreria por cada version si no que con la misma libreria se agrega las dos huellas (footprints) del componente...

# Creacion del Simbolo (Dibujo del esquematico)

Para la creacion de librerias tenemos irnos al menu del lado derecho de la ventana principal de KiCAD y seleccionar   `Editor de Simbolos`....

![](../../img/Pasted%20image%2020230223180623.png)

![](../../img/Pasted%20image%2020230223180711.png)

Luego nos saldra la siguiente ventana que es nuestra ventana de edicion de simbolos...

![](../../img/Pasted%20image%2020230223181324.png)

Aqui para agregar una nueva libreria tendremos que irnos al menu superior y seleccionar la siguiente ruta...

```
Archivo/Nueva Libreria...
```

Esto nos dara una ventana que nos pedira si la libreria la queremos global o para solo usarce en un proyecto, lo recomendado es usarla de forma global para poder utilizarce en otros proyectos futuros...

![](../../img/Pasted%20image%2020230223181602.png)

Luego nos pedira el lugar donde guardarla y listo...

volviendo al editor de simbolos, vemos que nuestra libreria ya debe estar en la lista de librerias que se muestra en el lado izquierdo de la ventana de edicion de simbolos...

![](../../img/Pasted%20image%2020230223181722.png)

Para este ejemplo creamos la libreria `Puente_de_Diodos` al darle clic derecho a la libreira y seleccionar `nuevo simbolo`  o usar el atajo de teclado `N`  seleccionando la libreria esto nos arrojara la siguiente ventana de configuracion...

![](../../img/Pasted%20image%2020230223181924.png)

la cual llenaremos lo siguiente...

- Nombre del simbolo
- Referencia por defecto

Este ultimo es la letra que se usara para identificar el dispositivo al lado de un numero que indicara el numero asignado a este dispositivo esto ayuda a saber cuantos componentes se tienen en el esquematico...

Para este ejemplo el componente se llama `KBPC5010`  y la referencia es `PD`  luego de darle aceptar nos desplegara dos etiquetas que una es el nombre del componente y otra la referencia...

![](../../img/Pasted%20image%2020230223182232.png)

Aqui empezamos a dibujar el simbolo para esto tenemos las herramientas del lado derecho de la ventana de edicion...

Luego de hacer el simbolo nos queda de la siguiente forma...

![](../../img/Pasted%20image%2020230223184244.png)

Listo Guardamos y tenemos el simbolo ya hecho

# Creacion de la Huella (footprint)

Para crear la huella (footprint) tenemos que ir a la ventana principal de KiCAD y seleccionar `Editor de huellas`...

![](../../img/Pasted%20image%2020230223180623.png)

![](../../img/Pasted%20image%2020230223184447.png)

Luego nos aparecera la ventana de edicion de huellas...

![](../../img/Pasted%20image%2020230223184604.png)

La cual para empezar a crear la libreria de huellas para nuestro componente nos dirigimos a la barra superior y le damos al boton de archivo y luego a nueva libreria como se describe la siguiente direccion

```
Archivos/Nueva Libreria...
```

Esto nos arrojara una ventana de opciones la cual nos indica que si queremos que la libreria sea global o solo para un proyecto lo recomendable es que sea global...

![](../../img/Pasted%20image%2020230223184827.png)

nos pedira donde guardar la libreria y listo podemos ver la libreria en el panel de lado izquierda de la ventana donde en lista todas las librerias...

![](../../img/Pasted%20image%2020230223185237.png)

Luego selecionamos la libreria y le damos clic derecho y seleccionamos `nueva huella` o suamos el atajo de teclado `ctrl+N` esto nos arrojara la ventana siguiente en la cual agregamos el nombre del componente y de que tipo es SMD o THT...

![](../../img/Pasted%20image%2020230223185217.png)

Luego de crear el componente nos aparecera dentro de la libreria y nos dara como etiqueta las referencias y el nombre del componente...

![](../../img/Pasted%20image%2020230223185337.png)

Para la creacion de la huella tenemos la barra de herramientas del lado derecho para construirlo...

La construccion del componente que estoy creando es el siguiente...

![](../../img/Pasted%20image%2020230223195830.png)

Luego le damos a guardar y listo

# Añadir el modelo 3D al componente

Para añadir el modelo 3D nos dirigimos a editar propiedades de la huella 

![](../../img/Pasted%20image%2020230223200024.png)

Luego nos aparece una ventana de configuracion

![](../../img/Pasted%20image%2020230223200055.png)

Nos dirigimos a la pestaña de Modelos 3D...

![](../../img/Pasted%20image%2020230223200131.png)

t vemos nuestra huella en 3D, ahora solo queda en añadir el componente y listo...

![](../../img/Pasted%20image%2020230223201603.png)

