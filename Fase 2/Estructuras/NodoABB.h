#ifndef PROYECTO1_NODOABB_H
#define PROYECTO1_NODOABB_H
#include "ABBtree.h"

class NodoABB {
    public:
    NodoABB(ABBtree* dato): dato(dato), siguiente(nullptr){};
    ABBtree* dato;
    NodoABB* siguiente;
};


#endif //PROYECTO1_NODOABB_H
