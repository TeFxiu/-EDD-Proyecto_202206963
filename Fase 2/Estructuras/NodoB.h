//
// Created by TeFxiu on 9/29/2024.
//
#include "Comentarios.h"
#ifndef PROYECTO1_NODOB_H
#define PROYECTO1_NODOB_H

#define MAX 4
#define MID 2

class NodoB {
public:
    int contador = 0;
    NodoB* hijos[MAX + 1];
    Comentarios* datos[MAX + 1];

    NodoB();
};


#endif //PROYECTO1_NODOB_H
