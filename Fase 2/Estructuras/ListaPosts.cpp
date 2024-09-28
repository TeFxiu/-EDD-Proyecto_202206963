//
// Created by TeFxiu on 9/27/2024.
//

#include "ListaPosts.h"

ListaPosts::ListaPosts(Publicacion *dato) {
    head = new NodoPosts(dato);
    retorno = nullptr;
    existente = nullptr;
}
ListaPosts::ListaPosts() {
    head = nullptr;
    retorno = nullptr;
    existente = nullptr;
}

bool ListaPosts::estaVacia() {
    return head == nullptr;
}

void ListaPosts::insertar(PostSimple* dato) {
    NodoPosts* nuevo = new NodoPosts(dato);
    NodoPosts* aux = head;

    if(estaVacia()){
        head = nuevo;
    }else{
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void ListaPosts::nuevo(){
    existente = head;
    head->dato->setNuevo();
    cambio = true;
};

void ListaPosts::activar(){
    NodoPosts* aux = head;
    while (aux != nullptr ){
        aux->dato->vuelta = true;
        aux = aux->siguiente;
    }

    this->vuelta = true;
};

Publicacion* ListaPosts::recorreraUno(){
    if (vuelta){
        retorno = head;
        vuelta = false;
        existente = retorno;
    }

    if (cambio){
        Publicacion* devolver = retorno->dato->recorreraUno();
        cambio = false;
        existente = retorno;
        if (devolver != nullptr){
            return devolver;
        }
    } else if(retorno != nullptr){
        Publicacion* devolver = retorno->dato->recorreraUno();
        if (devolver != nullptr){
            return devolver;
        }
        retorno = retorno->siguiente;
        existente = retorno;
    }

    return nullptr;
}

string ListaPosts::nombreHead() {
    return head->dato->nombreHead();
}
