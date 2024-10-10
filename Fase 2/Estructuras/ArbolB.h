//
// Created by TeFxiu on 9/29/2024.
//
#include "NodoB.h"

#ifndef PROYECTO1_ARBOLB_H
#define PROYECTO1_ARBOLB_H

class ArbolB {
private:
    NodoB* nuevoNodo(Comentarios* dato, NodoB* child);

    bool setValue(Comentarios* dato, Comentarios*& retorno, NodoB* root, NodoB*& child);
    bool buscarPosicion(Comentarios* dato, NodoB* root, int& pos);

    void insertarNodo(int pos, Comentarios* dato, NodoB* raiz, NodoB* child);
    void forzarInsercion(int pos, Comentarios* dato, NodoB* raiz);
    void division(Comentarios* val, Comentarios*& retorno, int pos, NodoB* root, NodoB*& child);

public:
    ArbolB();

    NodoB* raiz;

    void insertar(Comentarios* dato);
};


#endif //PROYECTO1_ARBOLB_H
