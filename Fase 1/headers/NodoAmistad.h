#ifndef NODOAMISTAD_H
#define NODOAMISTAD_H

#include "Amistad.h"
using namespace std;


struct NodoAmistad
{
    Amistad dato;
    NodoAmistad* siguiente;
    NodoAmistad* anterior;
    NodoAmistad(Amistad entrada):dato(entrada), siguiente(nullptr), anterior(nullptr){};

};
#endif
