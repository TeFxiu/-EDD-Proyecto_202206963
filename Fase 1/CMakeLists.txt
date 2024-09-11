cmake_minimum_required(VERSION 3.28)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto1
        main.cpp
        Usuario.cpp
        headers/Usuario.h
        Estructuras/EnlazadaSimple.cpp
        Estructuras/EnlazadaDoble.cpp
        headers/moduloUsuario.h
        headers/ModuloUsuario.cpp
        headers/NodoUser.h
        Estructuras/CircularDoble.cpp
        headers/ModuloAdmin.h
        headers/NodoStories.h
        Estructuras/SimpleAmistad.cpp
        Estructuras/Pila.cpp
        headers/Amistad.h
        headers/ModuloAdmin.cpp
        tinyfiledialogs/tinyfiledialogs.h
        tinyfiledialogs/tinyfiledialogs.c
        Estructuras/Matriz.h
        Estructuras/Matriz.cpp
        "../Fase 2/GUI/main.cpp"
        "../Fase 2/Estructuras/TreeUsuario.h"
        "../Fase 2/Estructuras/TreeUsuario.cpp"
        "../Fase 2/Estructuras/AVLtree.cpp"
)
