#KiCAD

[Instalacion de KiCAD](Instalacion%20de%20KiCAD.md)

Por defecto tiene unas librerias muy deficientes, asi que a continuacion, instalaremos mas librerias para complementar y dejar bien configurado listo para trabajar

# Librerias de Repositorio Oficial GitLab

Estas estan en GitLab por consiguiente para clonarlas se usa los siguientes comandos...

[kicad-footprints](https://gitlab.com/kicad/libraries/kicad-footprints/-/tree/master/)

```bash
git clone https://gitlab.com/kicad/libraries/kicad-footprints.git
```

[kicad-symbols](https://gitlab.com/kicad/libraries/kicad-symbols/-/tree/master/)

```bash
git clone https://gitlab.com/kicad/libraries/kicad-symbols.git
```

[kicad-packages3D](https://gitlab.com/kicad/libraries/kicad-packages3D/-/tree/master/)

```bash
git clone https://gitlab.com/kicad/libraries/kicad-packages3D.git
```

las direcciones de la carpeta de librerias son las siguiente...

> Footprints

```bash
cd /usr/share/kicad/footprints/
```

> Symbols

```bash
cd /usr/share/kicad/symbols/
```

> 3D Models

```bash
cd /usr/share/kicad/3dmodels/
```

Crearemos una carpeta en la siguiente ubicacion...

```bash
cd /usr/share/kicad/github_lib
```

y clonamos todos los repositorios ahi...

```bash
❯ ls
 kicad-footprints   kicad-packages3D-master   kicad-symbols
```

Ahora lo que haremos es remplazar todas las librerias usando el siguiente script que se encargara de actualizar los repositorios y actualizar las librerias en las direcciones adecuadas

```bash
───────┬──────────────────────────────────────────────────────────────────────────────
       │ File: actualizar.sh
───────┼──────────────────────────────────────────────────────────────────────────────
   1   │ #!/bin/bash
   2   │ 
   3   │ echo "Actualizando Repositorios"
   4   │ 
   5   │ cd /usr/share/kicad/github_lib/kicad-symbols
   6   │ git pull
   7   │ cd /usr/share/kicad/github_lib/kicad-footprints
   8   │ git pull
   9   │ cd /usr/share/kicad/github_lib/kicad-packages3D
  10   │ git pull
  11   │ 
  12   │ echo "repositorios Actualizados"
  13   │ 
  14   │ echo "Copiando la Actualizacion de los Repositorios..."
  15   │ 
  16   │ echo "cp kicad-symbols -> symbols ..."
  17   │ cp -r /usr/share/kicad/symbols /usr/share/kicad/symbols-backup
  18   │ cd /usr/share/kicad/github_lib/kicad-symbols
  19   │ cp -r * /usr/share/kicad/symbols/*
  20   │ 
  21   │ echo "cp kicad-footprints -> footprints ..."
  22   │ cp -r /usr/share/kicad/footprints /usr/share/kicad/footprints-backup
  23   │ cd /usr/share/kicad/github_lib/kicad-footprints
  24   │ cp -r * /usr/share/kicad/footprints/*
  25   │ 
  26   │ echo "cp kicad-packages3D -> 3dmodels ..."
  27   │ cp -r /usr/share/kicad/3dmodels /usr/share/kicad/3dmodels-backup
  28   │ cd /usr/share/kicad/github_lib/kicad-packages3D
  29   │ cp -r * /usr/share/kicad/3dmodels/*
  30   │ 
  31   │ echo "Actualizacion Terminada..."
───────┴──────────────────────────────────────────────────────────────────────────────

```
