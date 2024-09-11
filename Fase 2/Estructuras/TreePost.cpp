//
// Created by TeFxiu on 9/11/2024.
//

#include "TreePost.h"

TreePost::TreePost(Publicacion* dato){
    this->lista = new PostSimple();
    lista->push(dato);
    drcha = nullptr;
    izq = nullptr;
}

void TreePost::setlista(PostSimple* lista){
    this->lista = lista;
}

PostSimple* TreePost::getlista(){
    return lista;
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