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
    NodoListas(DoublyLinkedList* entrada):listaPublicaciones(entrada), siguiente(nullptr), anterior(nullptr){};

};
#endif
