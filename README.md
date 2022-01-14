# Cmake_tutorial
Self-learning CMake ways.

## CLI guide
Para buildear un proyecto y obtener los ejectuables:
```
mkdir build
cd build
cmake .. // Establece el directorio actual como el CMAKE_BINARY_DIR, y el
            pasado por línea de comandos como el CMAKE_SOURCE_DIR
cmake --build . //  Buildea el proyecto en el BINARY_DIR indicado.
cmake --install . --prefix <absolute_path_install_dir> //normally $(pwd)/../instalation
```

# Guía rápida de comandos

## Setup inicial
```
cmake_minimum_required(VERSION <version_number>)

project(<PROJECT_NAME>)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
## Funciones
#
```
add_executable (<target_name> <sources>...)
```
Crea un nuevo "target" ejecutable.
#

```
add_library(<library_target_name> <sources>...)
```
Crea un nuevo "target" no ejecutable. Una librería es solo un conjunto de objetos `*.o` sin linkear (su extensión, para librería estática es `*.a`).

#
```
target_include_directories (<target_name> PUBLIC|PRIVATE|INTERFACE [<header_path1> <header_path2>])
```
Agrega el path hacia la carpeta donde se encuentran los header files, cosa de poder incluirlos en el código usando simplemente `#include "header.h"`, sin importar el path relativo.

PUBLIC|PRIVATE|INTERFACE establece el modo en que deben ser incluídos:

1. PUBLIC: Los header files pueden ser vistos por el target, y cualquier otro target que quiera linkear con este.

2. PRIVATE: Los header files solo pueden ser vistos por el target en cuestión.

3. INTERFACE: Los header files solo pueden ser vistos por cualquier otro target que quiera linkear con este, pero NO son vistos por el target que los incluye.

#
```
target_link_libraries(<target_name> PUBLIC|PRIVATE|INTERFACE <target_to_link_to>)
```
Linkea una librería creada con `add_library()` junto con el target en cuestión. El modo PUBLIC|PRIVATE|INTERFACE tiene el mismo significado que para los headers, modificando la visibilidad del linkeo para las dependencias del target que linkea <target_name>.

# 
```
add_subdirectory(<path_to_CMakeLists.txt>)
```
Dado un subdirectorio donde haya un archivo CMakeLists.txt, crea ese mismo subdirectorio dentro del build, donde ejecuta el CMakeLists.txt anidado. 

#

## Instalation

La instalación no es un proceso aparte en sí mismo, sino que se definen qué elementos de todos aquellos que hemos construido son necesarios para el usuario. Consiste en mover los archivos construidos a un directorio de instalación designado.

```
install(TARGETS|FILES|DIRECTORY <element> DESTINATION <directory_path>)
```



## Variables
```
${CMAKE_SOURCE_DIR}

${CMAKE_CURRENT_SOURCE_DIR}

${CMAKE_BINARY_DIR}

${CMAKE_CURRENT_BINARY_DIR}

${PROJECT_SOURCE_DIR} = Path absoluto hacia el archivo CMakeLists.txt que llamó a project().

${PROJECT_BINARY_DIR} = Path absoluto hacia la carpeta donde se realiza el buildeo.
```


