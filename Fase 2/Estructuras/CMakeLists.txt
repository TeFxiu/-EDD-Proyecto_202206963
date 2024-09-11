cmake_minimum_required(VERSION 3.28)
project(Estructuras)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Estructuras
        AVLtree.cpp
        AVLtree.h
        TreeUsuario.cpp
        TreeUsuario.h
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Usuario.h"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Usuario.cpp"
)
