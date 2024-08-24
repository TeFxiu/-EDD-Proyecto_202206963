#ifndef NODOUSER_H
#define NODOUSER_H
#include "Usuario.h"

using namespace std;

struct NodoUser
{
    Usuario* dato;
    Usuario* amigo;
    NodoUser* siguiente;
    NodoUser* arriba;
    NodoUser* abajo;
    NodoUser* anterior;
    int id = 1;
    bool bandera = false;
    NodoUser(Usuario* entrada, Usuario* amigo, bool lxd):dato(entrada), amigo(amigo), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr){this->id = id -1;};
    NodoUser(Usuario* entrada):dato(entrada), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr), amigo(
            nullptr){};
    NodoUser(Usuario* entrada, Usuario* amigo):dato(entrada), amigo(amigo), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr){};
};
#endif