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
        "../Fase 2/Estructuras/ABBtree.h"
        "../Fase 2/Estructuras/ABBtree.cpp"
        "../Fase 2/Estructuras/TreePost.h"
        "../Fase 2/Estructuras/TreePost.cpp"
        "../Fase 2/Estructuras/PostSimple.h"
        "../Fase 2/Estructuras/PostSimple.cpp"
        "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Estructuras/ABBtree.h"
        headers/UsuarioA.h
        UsuarioA.cpp
        "../Fase 2/Estructuras/ListaUsuarios.cpp"
        "../Fase 2/Estructuras/ListaPosts.cpp"
        "../Fase 2/Estructuras/NodoPosts.cpp"
        "../Fase 2/Estructuras/ListaABB.cpp"
        "../Fase 2/Estructuras/Comentarios.h"
        "../Fase 2/Estructuras/Comentarios.cpp"
        "../Fase 2/Estructuras/NodoB.h"
        "../Fase 2/Estructuras/ArbolB.h"
        "../Fase 2/Estructuras/ArbolB.cpp"
        "../Fase 2/Estructuras/sha.h"
        "../Fase 3/Estructuras/Vertice.h"
        "../Fase 3/Estructuras/Vertice.cpp"
        "../Fase 3/Estructuras/SuperVertice.h"
        "../Fase 3/Estructuras/SuperVertice.cpp"
        "../Fase 3/Estructuras/Grafo.h"
        "../Fase 3/Estructuras/Grafo.cpp"
        "../Fase 3/Estructuras/Block.h"
        "../Fase 3/Estructuras/Block.cpp"
        "../Fase 3/Estructuras/Merkle.h"
        "../Fase 3/Estructuras/Merkle.cpp"
        "../Fase 3/Estructuras/Nodo.h"
        "../Fase 3/Estructuras/Nodo.cpp"
        "../Fase 3/Estructuras/Huffman.h"
        "../Fase 3/Estructuras/Huffman.cpp"
        "../Fase 3/Estructuras/NodoH.h"
        "../Fase 3/Estructuras/NodoH.cpp"
)
