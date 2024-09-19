# Instrucciones para Compilar y Ejecutar el Proyecto

A continuación, se detallan los pasos para clonar, compilar y ejecutar el proyecto desde un repositorio de GitHub utilizando **qmake** y **make** en una máquina con Linux. Se asume que tienes instalado `git` en tu sistema.

## Paso 1: Instalar Dependencias

Primero, asegúrate de instalar las herramientas y bibliotecas necesarias para trabajar con **Qt**. Ejecuta el siguiente comando para instalar los paquetes requeridos:

```bash
sudo apt install qtbase5-dev qt5-qmake qtchooser
```

Esto instalará las bibliotecas básicas de Qt, el generador de proyectos qmake y la herramienta qtchooser para gestionar versiones de Qt.

## Paso 2: Clonar el Repositorio

Clona el repositorio del proyecto desde GitHub utilizando el siguiente comando:

```bash
git clone https://github.com/Joel-Barboza/DSA-II_Alg-Analysis.git
```
Esto descargará el código fuente del proyecto en una carpeta llamada DSA-II_Alg-Analysis.

## Paso 3: Entrar en el Directorio del Proyecto

Navega al directorio del proyecto que acabas de clonar:

```bash
cd DSA-II_Alg-Analysis
```

## Paso 4: Generar el Makefile

Utiliza qmake para generar los archivos Makefile que son necesarios para compilar el proyecto:

```bash
qmake
```

Este comando creará un archivo Makefile basado en el archivo de configuración .pro del proyecto.

## Paso 5: Compilar el Proyecto

Compila el proyecto utilizando el comando make:

```bash
make
```

Este comando compilará todo el código y generará un archivo ejecutable en el directorio.

## Paso 6: Ejecutar la Aplicación

Una vez que la compilación haya finalizado correctamente, puedes ejecutar la aplicación con el siguiente comando:

```bash
./DSA-II_Alg-Analysis
```
