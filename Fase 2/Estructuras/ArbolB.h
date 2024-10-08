//
// Created by TeFxiu on 9/29/2024.
//
#include "NodoB.h"

#ifndef PROYECTO1_ARBOLB_H
#define PROYECTO1_ARBOLB_H

class ArbolB {
private:
    NodoB* raiz;
    bool setValue(Comentarios* dato, Comentarios*& segundo, NodoB* raiz, NodoB** nuevo);
    NodoB* nuevoNodo(Comentarios* dato, NodoB* child);
    void insertarNodo(int pos, Comentarios* dato, NodoB* raiz, NodoB* subArbol);
    void division(Comentarios* val, Comentarios*& apuntaVal, int pos, NodoB* raiz, NodoB* segundo, NodoB** child);
public:
    ArbolB();

    void insertar(Comentarios* dato);
};


#endif //PROYECTO1_ARBOLB_H
