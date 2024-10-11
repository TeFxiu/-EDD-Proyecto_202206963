//
// Created by TeFxiu on 10/10/2024.
//

#include "Grafo.h"

Grafo::Grafo() {}

void Grafo::insertar(Usuario *emisor, Usuario *receptor) {
    SuperVertice* super = new SuperVertice(emisor);
    SuperVertice* aux = nullptr;
    if (!primero){
        primero = super;
        ultimo = primero;
        super->insertar(receptor);
        return;
    }
    aux = primero;
    while (aux) {
        if (aux->emisor->getEmail() == emisor->getEmail()) {
            aux->insertar(receptor);
            return;
        }
        aux = aux->siguiente;
    }
    ultimo->siguiente = super;
    super->anterior = ultimo;
    ultimo = super;
    ultimo->insertar(receptor);
}

SuperVertice* Grafo::amistedesEmisor(Usuario *emisor) {
    SuperVertice* aux = primero;
    while (aux){
        if (aux->emisor->getEmail() == emisor->getEmail()) return aux;
        aux = aux->siguiente;
    }
    return nullptr;
}

bool Grafo::buscarAmistad(Usuario *emisor, Usuario *receptor) {
    SuperVertice* aux = primero;

    while (aux){
        if (aux->emisor->getEmail() == emisor->getEmail()) return aux->buscarRelacion(receptor);
        aux = aux->siguiente;
    }
    return false;

}
