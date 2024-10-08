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

PostSimple* ABBtree::buscarPublicacionesI(time_t fecha, TreePost* actual) {
    if (actual == nullptr){
        return nullptr;
    }

    if(actual->getlista()->buscarFecha() == fecha){
        return actual->getlista();
    } else if (actual->getlista()->buscarFecha() < fecha){
        return buscarPublicacionesI(fecha, actual->getDrcha());
    } else if (actual->getlista()->buscarFecha() > fecha){
        return buscarPublicacionesI(fecha, actual->getIzq());
    }
}

PostSimple* ABBtree::buscarPublicacionesI(time_t fecha){
    return buscarPublicacionesI(fecha, root);
}

ListaPosts* ABBtree::buscarPublicaciones(time_t fecha, TreePost* actual) {
    if (actual == nullptr){
        return nullptr;
    }

    if(actual->getlista()->buscarFecha() == fecha){
        return actual->lista;
    } else if (actual->getlista()->buscarFecha() < fecha){
        return buscarPublicaciones(fecha, actual->getDrcha());
    } else if (actual->getlista()->buscarFecha() > fecha){
        return buscarPublicaciones(fecha, actual->getIzq());
    }
}

ListaPosts* ABBtree::buscarPublicaciones(time_t fecha){
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

void ABBtree::conectar(ABBtree* copia, TreePost* raiz){
    if(raiz != nullptr){
        PostSimple* nuevo = copia->buscarPublicacionesI(raiz->fecha());
        if (nuevo != nullptr){
            raiz->lista->insertar(nuevo);
        }
        conectar(copia,raiz->getIzq());
        conectar(copia,raiz->getDrcha());
    }
}


void ABBtree::conectar(ABBtree* copia){
    conectar(copia, root);
}
void ABBtree::conectar(ABBtree* copia, TreePost* raiz, time_t fecha){
    if(raiz != nullptr){
        if (fecha == raiz->fecha()) {
            PostSimple *nuevo = copia->buscarPublicacionesI(raiz->fecha());
            if (nuevo != nullptr) {
                raiz->lista->insertar(nuevo);
            }
        }
        conectar(copia,raiz->getIzq(), fecha);
        conectar(copia,raiz->getDrcha(), fecha);
    }
}


void ABBtree::conectar(ABBtree* copia, time_t fecha){
    conectar(copia, root, fecha);
}

void ABBtree::preOrden(TreePost* raiz, int contador, PostSimple* nueva, int sube){
    if(raiz != nullptr){
        if (contador == sube){
            return;
        }
        if (sube == 0 ){
            raiz->getlista()->vuelta = true;
        }
        while(true){
            Publicacion* publi = raiz->getlista()->recorreraUno();
            if (!publi){
                break;
            }
            nueva->append(publi);
        }
        sube++;
        preOrden(raiz->getIzq(), contador, nueva, sube);
        preOrden(raiz->getDrcha(), contador, nueva, sube);
    }
}

void ABBtree::inOrden(TreePost* raiz, int contador, PostSimple* nueva, int sube){
    if(raiz != nullptr){
        inOrden(raiz->getIzq(), contador, nueva, sube);
        if (contador == sube){
            return;
        }
        if (sube == 0 ){
            raiz->getlista()->vuelta = true;
        }
        while(true){
            Publicacion* publi = raiz->getlista()->recorreraUno();
            if (!publi){
                break;
            }
            nueva->append(publi);
        }
        sube++;
        inOrden(raiz->getDrcha(), contador, nueva, sube);
    }
}

void ABBtree::postOrden(TreePost* raiz, int contador, PostSimple* nueva, int sube){
    if(raiz != nullptr){
        postOrden(raiz->getIzq(), contador, nueva, sube);
        postOrden(raiz->getDrcha(), contador, nueva, sube);
        if (contador == sube){
            return;
        }
        if (sube == 0 ){
            raiz->getlista()->vuelta = true;
        }
        while(true){
            Publicacion* publi = raiz->getlista()->recorreraUno();
            if (!publi){
                break;
            }
            nueva->append(publi);
        }
        sube++;
    }
}
