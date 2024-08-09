cmake_minimum_required(VERSION 3.28)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proyecto1
        main.cpp
        Usuario.cpp
        headers/Usuario.h
        Listas/EnlazadaSimple.cpp
        Listas/EnlazadaDoble.cpp
        headers/moduloUsuario.h
        headers/ModuloUsuario.cpp)
