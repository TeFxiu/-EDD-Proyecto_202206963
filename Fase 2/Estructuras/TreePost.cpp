//
// Created by TeFxiu on 9/11/2024.
//

#include "TreePost.h"

TreePost::TreePost(Publicacion* dato){
    this->lista = new ListaPosts(dato);
    drcha = nullptr;
    izq = nullptr;
}

void TreePost::setlista(ListaPosts* lista){
    this->lista = lista;
}

PostSimple* TreePost::getlista(){
    return lista->head->dato;
}

time_t TreePost::fecha() {
    return lista->head->dato->buscarFecha();
}

void TreePost::setDrcha(TreePost *drcha){
    this->drcha = drcha;
}

TreePost* TreePost::getDrcha(){
    return drcha;
}

void TreePost::setIzq(TreePost *izq){
    this->izq = izq;
}

TreePost* TreePost::getIzq(){
    return izq;
}

TreePost*& TreePost::refDrcha(){
    return drcha;
}

TreePost*& TreePost::refIzq(){
    return izq;
}

