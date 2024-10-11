//
// Created by TeFxiu on 10/10/2024.
//

#include "SuperVertice.h"

SuperVertice::SuperVertice() {}

SuperVertice::SuperVertice(Usuario *_emisor):emisor(_emisor){};

SuperVertice::~SuperVertice() {}

void SuperVertice::insertar(Usuario *receptor) {
    Vertice* nuevo = new Vertice(receptor);
    Vertice* aux = nullptr;
    if (!amigos){
        amigos = nuevo;
        return;
    }
    aux = amigos;
    if (aux->receptor->getEmail() == receptor->getEmail()) return;

    while (aux->delante){
        if (aux->delante->receptor->getEmail() == receptor->getEmail()){
            return;
        }
        aux = aux->delante;
    }
    aux->delante = nuevo;
}

bool SuperVertice::buscarRelacion(Usuario *receptor) {
    Vertice* aux = amigos;
    while (aux){
        if (aux->receptor->getEmail() == receptor->getEmail()) return true;
        aux = aux->delante;
    }
    return false;
}