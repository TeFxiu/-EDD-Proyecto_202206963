#include <string>
#include "Publicacion.h"
#ifndef NODOSTORIES_H
#define NODOSTORIES_H
using namespace std;


struct NodoStories
{
    Publicacion dato;
    NodoStories* siguiente;
    NodoStories* anterior;
    NodoStories(Publicacion entrada):dato(entrada), siguiente(nullptr), anterior(nullptr){};

};
#endif
