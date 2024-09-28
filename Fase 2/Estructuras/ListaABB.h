//
// Created by TeFxiu on 9/27/2024.
//

#ifndef PROYECTO1_LISTAABB_H
#define PROYECTO1_LISTAABB_H
#include "NodoABB.h"

class ListaABB {
private:
public:
    NodoABB* head;
    NodoABB* retorno;

    ListaABB(): head(nullptr), retorno(nullptr){};
    bool estaVacia();
    void insertar(ABBtree* dato);
    ListaPosts* buscarPublicaciones(time_t fecha);

    void conectar(time_t fecha);


};


#endif //PROYECTO1_LISTAABB_H
