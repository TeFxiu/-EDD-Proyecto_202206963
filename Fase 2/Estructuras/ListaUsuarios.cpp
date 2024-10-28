//
// Created by TeFxiu on 9/26/2024.
//

#include "ListaUsuarios.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/SimpleAmistad.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Pila.cpp"

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
    newNodo->setAltura(1);
    if (this->estaVacia()) {
        head = newNodo;
    }else{
        newNodo->setDrcha(head);
        head = newNodo;
    }
}

void ListaUsuarios::agregarPerfiles(ListaUsuarios* lista, Usuario* perfil){
    Usuario* recomendado = lista->recorreraUno();
    while (recomendado){
        if (perfil->enviados->findEmail(recomendado->getEmail()) || perfil->solicitudes->findEmail(recomendado->getEmail())){
            recomendado = lista->recorreraUno();
            continue;
        }
        TreeUsuario* verificado = this->buscar(recomendado);
        if (verificado){
            verificado->setAltura(verificado->getAltura() + 1);
        }else{
            this->append(recomendado);
        }
        recomendado = lista->recorreraUno();
    }
}

void ListaUsuarios::ordenar(){
    int i;
    while (true){
        i = 1;
        TreeUsuario* prevA = nullptr;
        TreeUsuario* actual = head;
        if (!actual) return;
        TreeUsuario* comparando = actual->getDrcha();
        while (comparando){
            if (actual->getAltura() > comparando->getAltura()){
                if (prevA){
                    prevA->setDrcha(comparando);
                }else{
                    head = comparando;
                }
                actual->setDrcha(comparando->getDrcha());
                comparando->setDrcha(actual);
                prevA = comparando;
                comparando = actual->getDrcha();
            }else{
                i++;
                prevA = actual;
                actual = actual->getDrcha();
                comparando = comparando->getDrcha();
            }
        }

        if (i == contador){
            return;
        }
    }
}

TreeUsuario* ListaUsuarios::buscar(Usuario* buscado){
    TreeUsuario* aux = this->head;
    while (aux){
        if (aux->getData()->getEmail() == buscado->getEmail()) return aux;
        aux = aux->getDrcha();
    }
    return nullptr;
}


bool ListaUsuarios::buscarB(Usuario* buscado){
    TreeUsuario* aux = this->head;
    while (aux){
        if (aux->getData()->getEmail() == buscado->getEmail()) return true;
        aux = aux->getDrcha();
    }
    return false;
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
