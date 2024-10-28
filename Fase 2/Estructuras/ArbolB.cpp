#include "ArbolB.h"

ArbolB::ArbolB() {
    raiz = nullptr;
}

void ArbolB::insertar(Comentarios *dato) {
    NodoB* child = nullptr;
    Comentarios* retorno = nullptr;

    if (setValue(dato, retorno, raiz, child)){
        raiz = nuevoNodo(retorno, child);
    }
}

bool ArbolB::setValue(Comentarios *dato, Comentarios *& retorno, NodoB* root, NodoB*& child) {
    int pos = 0;
    if (!root){
        child = nullptr;
        retorno = dato;
        return true;
    }
    bool ver = buscarPosicion(dato, root, pos);
    if (!ver){
        return false;
    }
    if (setValue(dato, retorno, root->hijos[pos], child)){
        if (root->contador < MAX){
            insertarNodo(pos, retorno, root, child);
        } else{
            division(retorno, retorno, pos, root, child);
            return true;
        }
    }
    return false;
}

void ArbolB::division(Comentarios* val, Comentarios*& retorno, int pos, NodoB* root, NodoB*& child) {
    forzarInsercion(pos, retorno, root);
    retorno = root->datos[MID];
    NodoB* childA = child;
    child = new NodoB();
    int j = MAX;
    while (j> MID){
        int indice = MAX-j;
        child->datos[indice] = root->datos[MID + indice + 1];
        child->contador++;
        root->datos[MID + indice + 1] = nullptr;
        j--;
    }
    for (int i = 0 ; i < child->contador + 1; i++ ){
        if (pos > MID){
            if (pos == i + MID + 1){
                child->hijos[i] = root->hijos[i + MID + 1];
                i++;
                child->hijos[i] = childA;
                continue;
            }
            child->hijos[i] = root->hijos[i + MID +1];
        }else if (pos == MID){
            child->hijos[i] = childA;
            pos = 0;
            continue;
        }
        child->hijos[i] = root->hijos[MID + i];

        if (pos < MID){
            if (pos + 1 == i){
                int correr = child->contador;
                while (correr >= pos + 1){
                    root->hijos[correr + 1] = root->hijos[correr];
                    correr--;
                }
                root->hijos[i] = childA;
            }
        }
    }
    for (int i =MID; i < MAX;i++){
        root->hijos[i + 1] = nullptr;
    }

    root->datos[MID] = nullptr;
    root->contador = MID;
}

void ArbolB::insertarNodo(int pos, Comentarios* dato, NodoB* root, NodoB* child){
    if (root->datos[pos] == nullptr){
        root->datos[pos] = dato;
        root->hijos[pos + 1] = child;
        root->contador++;
        return;
    }
    int j = root->contador;

    while (j > pos){
        root->datos[j] = root->datos[j-1];
        root->hijos[j+1] = root->hijos[j];
        j--;
    }
    root->hijos[j+1] = child;
    root->datos[j] = dato;
    root->contador++;
}

void ArbolB::forzarInsercion(int pos, Comentarios* dato, NodoB* root){
    if (root->datos[pos] == nullptr){
        root->datos[pos] = dato;
        return;
    }
    int j = root->contador;
    while (j > pos){
        root->datos[j] = root->datos[j-1];
        j--;
    }
    root->datos[j] = dato;
}

bool ArbolB::buscarPosicion(Comentarios* dato, NodoB* root, int& pos){
    int i = 0;
    for (i; ( root->datos[i]->getFecha_hora() < dato->getFecha_hora() && i < 5) ; i++) {
        if (root->datos[i+1] == nullptr){
            pos = i+1;
            return true;
        }
    }
    if (root->datos[i]->getFecha_hora() == dato->getFecha_hora() ){
        return false;
    }
    pos = i;
    return true;
}

NodoB* ArbolB::nuevoNodo(Comentarios *dato, NodoB *child) {
    NodoB* root = new NodoB();
    root->datos[0] = dato;
    root->contador++;
    root->hijos[0] = raiz;
    root->hijos[1] = child;
    return root;
}

string ArbolB::resumen(string refactor, NodoB* actual){
    if (!actual) return "";

    for (int i = 0; i < 5; i++ ){
        resumen(refactor, actual->hijos[i]);
        if (actual->datos[i]) refactor += actual->datos[i]->resumir();
    }
    return "s";
}
