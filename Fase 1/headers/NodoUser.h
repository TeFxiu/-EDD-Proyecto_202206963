#ifndef NODOUSER_H
#define NODOUSER_H
#include "UsuarioA.h"

using namespace std;

struct NodoUser
{
    UsuarioA* dato;
    UsuarioA* amigo;
    NodoUser* siguiente;
    NodoUser* arriba;
    NodoUser* abajo;
    NodoUser* anterior;
    bool bandera = false;

    NodoUser(UsuarioA* entrada):
        dato(entrada),
        siguiente(nullptr),
        anterior(nullptr),
        arriba(nullptr),
        abajo(nullptr),
        amigo(nullptr){};

    NodoUser(UsuarioA* entrada, int num):
        dato(entrada),
        siguiente(nullptr),
        anterior(nullptr),
        arriba(nullptr),
        abajo(nullptr),
        amigo(nullptr){};

    NodoUser(int num, UsuarioA* entrada):
        dato(entrada),
        siguiente(nullptr),
        anterior(nullptr),
        arriba(nullptr),
        abajo(nullptr),
        amigo(nullptr){};

    NodoUser(UsuarioA* entrada, UsuarioA* amigo):dato(entrada), amigo(amigo), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr){};

    NodoUser(UsuarioA* entrada, UsuarioA* amigo, bool lxd):dato(entrada), amigo(amigo), siguiente(nullptr), anterior(nullptr), arriba(nullptr), abajo(nullptr){};
};
#endif
