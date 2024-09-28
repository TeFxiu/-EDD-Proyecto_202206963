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

PostSimple* ABBtree::buscarPublicaciones(time_t fecha, TreePost* actual) {
    if (actual == nullptr){
        return nullptr;
    }

    if(actual->getlista()->buscarFecha() == fecha){
        return actual->getlista();
    } else if (actual->getlista()->buscarFecha() < fecha){
        return buscarPublicaciones(fecha, actual->getDrcha());
    } else if (actual->getlista()->buscarFecha() > fecha){
        return buscarPublicaciones(fecha, actual->getIzq());
    }
}

PostSimple* ABBtree::buscarPublicaciones(time_t fecha){
    return buscarPublicaciones(fecha, root);
}

void ABBtree::insertar(Publicacion* data){
    insertar(data,root);
}

void ABBtree::insertar(Publicacion* data, TreePost*& root){
    if (root == nullptr) {
        root = new TreePost(data);

        return;
    }

    PostSimple* listaActual = root->getlista();
    time_t tiempo = listaActual->buscarFecha();

    if (data->getFecha() < tiempo){
        insertar(data, root->refIzq());
    }else if(data->getFecha() > tiempo){
        insertar(data, root->refDrcha());
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
