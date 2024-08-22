#include <string>
#include "../Estructuras/EnlazadaDoble.cpp"
#ifndef NODOLISTAS_H
#define NODOLISTAS_H
using namespace std;


struct NodoListas
{
    DoublyLinkedList* listaPublicaciones;
    NodoListas* siguiente;
    NodoListas* anterior;
    NodoListas(Publicacion entrada):dato(entrada), siguiente(nullptr), anterior(nullptr){};

};
#endif
