//
// Created by TeFxiu on 9/26/2024.
//

#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios() {
    head = nullptr;
}

bool ListaUsuarios::estaVacia()
{return head == nullptr;}

void ListaUsuarios::append(Usuario* dato){
    TreeUsuario* newNodo = new TreeUsuario(dato);
    if (this->estaVacia()) {
        head = newNodo;
        contador++;
    }else{
        TreeUsuario* temp = head;
        while (temp->getDrcha() != nullptr)
        {
            temp = temp->getDrcha();
        }
        temp->setDrcha(newNodo);
        contador++;
    }
}

void ListaUsuarios::push(Usuario* dato){
    TreeUsuario* newNodo = new TreeUsuario(dato);
    if (this->estaVacia()) {
        head = newNodo;
    }else{
        newNodo->setDrcha(head);
        head = newNodo;
    }
}

Usuario* ListaUsuarios::recorreraUno() {
    if (bandera){
        retorno = head;
        bandera = false;
    }
    if (retorno != nullptr){
        Usuario* ret = retorno->getData();
        retorno = retorno ->getDrcha();
        return ret;
    }
    bandera = true;
    return nullptr;
}

void ListaUsuarios::reset(){
    TreeUsuario* aux;
    aux = head;
    while (aux != nullptr){
        head = aux->getDrcha();
        delete aux;
        aux = head;
    }
    head = nullptr;
    bandera = true;
    contador = 0;
}
