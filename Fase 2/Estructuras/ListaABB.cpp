//
// Created by TeFxiu on 9/27/2024.
//

#include "ListaABB.h"

bool ListaABB::estaVacia() {
    return head == nullptr;
}

void ListaABB::insertar(ABBtree* dato) {
    NodoABB* nuevo = new NodoABB(dato);
    NodoABB* aux = head;

    if(estaVacia()){
        head = nuevo;
    }else{
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

ListaPosts* ListaABB::buscarPublicaciones(time_t fecha){
    NodoABB* aux = head;
    ListaPosts* prueba = aux->dato->buscarPublicaciones(fecha);
    if (prueba != nullptr){
        return prueba;
    }

    prueba = new ListaPosts();

    while(aux->siguiente != nullptr){
        aux = aux->siguiente;
        PostSimple* enArbol = aux->dato->buscarPublicacionesI(fecha);
        if (enArbol != nullptr){
            prueba->insertar(enArbol);
        }
    }
    return prueba;
}

void ListaABB::conectar(time_t fecha) {
    NodoABB* aux = head;

    while(aux->siguiente != nullptr){
        aux = aux->siguiente;
        head->dato->conectar(aux->dato, fecha);
        aux->dato->conectar(head->dato, fecha);
    }

}