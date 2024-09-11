#include "TreeUsuario.h"

TreeUsuario::TreeUsuario(Usuario* data){
    this->data = data;
    altura = 1;
    drcha = nullptr;
    izq = nullptr;
}

Usuario* TreeUsuario::getData(){
    return data;
}

int TreeUsuario::getAltura(){
    return altura;
}

TreeUsuario* TreeUsuario::getDrcha(){
    return drcha;
}

TreeUsuario* TreeUsuario::getIzq(){
    return izq;
}

TreeUsuario*& TreeUsuario::refDrcha(){
    return drcha;
}

TreeUsuario*& TreeUsuario::refIzq(){
    return izq;
}

void TreeUsuario::setData(Usuario* data){
    this->data = data;
}

void TreeUsuario::setAltura(int altura){
    this->altura = altura;
}

void TreeUsuario::setDrcha(TreeUsuario *drcha){
        this->drcha = drcha;
}

void TreeUsuario::setIzq(TreeUsuario *izq){
    this->izq = izq;
}

