//
// Created by TeFxiu on 9/11/2024.
//

#include "ABBtree.h"

ABBtree::ABBtree(){
    root = nullptr;
}

bool ABBtree::estaVacio(){
    return root == nullptr;
}
/*

Publicacion* ABBtree::buscarPublicacion(string email, TreePost* actual) {
    if (actual == nullptr){
        return nullptr;
    }

    if(actual->getData()->getEmail() == email){
        return actual->getData();
    } else if (actual->getData()->getEmail() < email){
        return buscarPublicacion(email, actual->getDrcha());
    } else if (actual->getData()->getEmail() > email){
        return buscarPublicacion(email, actual->getIzq());
    }
}

Publicacion* ABBtree::buscarPublicacion(string mail){
    return buscarPublicacion(mail, root);
}
 */

void ABBtree::insertar(Publicacion* data){
    insertar(data,root);
}

void ABBtree::insertar(Publicacion* data, TreePost* root){
    if (root == nullptr) {
        root = new TreePost(data);
        return;
    }

    PostSimple* listaActual = root->getlista();
    time_t tiempo = listaActual->buscarFecha();

    if (data->getFecha() < tiempo){
        insertar(data, root->getIzq());
    }else if(data->getFecha() > tiempo){
        insertar(data, root->getDrcha());
    }else if(data->getFecha() == tiempo){
        listaActual->push(data);
    }
}

void ABBtree::preOrden(TreePost* raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void ABBtree::inOrden(TreePost* raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}