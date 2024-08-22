#ifndef NODOUSER_H
#define NODOUSER_H
#include "Usuario.h"

using namespace std;


struct NodoUser
{
    Usuario dato;
    Usuario amigo;
    NodoUser* siguiente;
    NodoUser* arriba;
    NodoUser* abajo;
    NodoUser* anterior;
    NodoUser(Usuario entrada):dato(entrada), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr), amigo(){};
    NodoUser(Usuario entrada, Usuario amigo):dato(entrada), amigo(amigo), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr){};
};
#endif