#KiCAD

# Instalación de KiCAD

KiCAD es multiplataforma y es un software gratuito y tiene la filosofia de software libre...

# Instalacion en Arch Linux

Para la instalacion de KiCAD en arch linux se usara el siguiente comando...

```bash
sudo pacman -S --asdeps kicad kicad-library kicad-library-3d
```

y listo...

# Configuracion de las librerias

Cuando abramos por primera vez un proyecto nos aparecera esta ventana...

![](../../img/Pasted%20image%2020230222135743.png)

El cual seleccionamos la recomendada puesto que el buscara las librerias que instalamos anterior mente...

# Apariencia de la mesa de trabajo

Para cambiar el tema de la mesa de trabajo podemos usar el siguiente reporsitorio en github que nos da los temas a usar, para empezar tendremos que clonar el repositorio con el siguiente comando...

```bash
git clone https://github.com/pointhi/kicad-color-schemes.git
```

luego entramos al repositorio clonado

```bash
cd kicad-color-schemes
```

luego copiamos el tema que queremos (eagle-dark en este caso) usando el siguiente comando...

```bash
cp -r eagle-dark/. ~/.config/kicad/6.0/colors/.
```

luego ejecutamos un script de python para añadir el tema con el siguiente comando...

```bash
python3 patch.py /home/n0c7u4/Repositorios/kicad-color-schemes/eagle-dark ~/.config/kicad/6.0/colors/
```

esto retorna lo siguiente...

```bash
Updating EESchema configuration.
Updating pcb_new configuration.
Updating footprint editor configuration.
```

listo ahora podemos entrar al programa kiCAD...

Cuando estemos dentro vamos a la siguiente ruta en la barra de herramientas superior izquierda...

```direccion
Preferencias/preferencia/colores
```

estando en esa pestaña podemos seleccionar el tema...

al darle aceptar esto quedara de la siguiente forma...

![](../../img/Pasted%20image%2020230222161937.png)


# Complementos de KiCAD

Los siguientes complementos son muy utiles, para esto debes seleccionar la ultima casilla con icono de una caja y luego darle a instalar a cada complemento que se necesite algunos que se instalaron son los siguientes...

## Archive 3D Models

![](../../img/Pasted%20image%2020230222110328.png)

Este crea una copia de los modelos 3D a la subcarpeta local del proyecto asi teniendo los modelos 3D necesarios del proyecto y poderlos importar en otra computadora que no los tenga...
## Keyswitch Kicad Library
![](../../img/Pasted%20image%2020230222112432.png)

Este nos da las librerias 3D de los switch...
## Alternate Kicad Library
![](../../img/Pasted%20image%2020230222112712.png)

Son librerias para kicad de los componentes...

# Desinstalar Kicad

Para desintalar usamos el siguiente comando...

```bash
sudo pacman -Rcns kicad kicad-library kicad-library-3d
```

sin embargo, todavia hay configuraciones del programa tendremos que revisar si hay carpetas con el nombre de `kicad`  en cada una de ellas y eliminarlas, con el siguiente comando...

```bash
ls ~/ | grep kicad
ls /usr/bin | grep kicad
ls /usr/lib | grep kicad
ls /usr/local | grep kicad
ls /usr/share/man | grep kicad
ls /usr/share/doc | grep kicad
ls /var | grep kicad
ls /run | grep kicad
ls /lib | grep kicad
ls ~/.cache | grep kicad
ls ~/.local | grep kicad
ls ~/.local/share | grep kicad
ls ~/.thumbnail | grep kicad
ls ~/.config/ | grep kicad
```
