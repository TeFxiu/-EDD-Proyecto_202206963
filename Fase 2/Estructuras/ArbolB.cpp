//
// Created by TeFxiu on 9/29/2024.
//

#include "ArbolB.h"
ArbolB::ArbolB() {
    raiz = nullptr;
}

void ArbolB::insertar(Comentarios* dato) {
    Comentarios* nuevo;

    NodoB* child = nullptr;

    if (child){
        if (setValue(dato, nuevo, raiz, &child)){
            raiz = nuevoNodo(dato, child);
        }
    }

    raiz = nuevoNodo(dato, child);
}

bool ArbolB::setValue(Comentarios *dato, Comentarios*& segundo, NodoB *raiz, NodoB **nuevo) {
    int pos;
    if (!raiz) {
        segundo = dato;
        *nuevo = nullptr;
        return true;
    }

    if (dato->getFecha_hora() < raiz->datos[1]->getFecha_hora()) {
        pos = 0;
    } else {
        for (pos = raiz->contador; (pos > 1 && dato->getFecha_hora() < raiz->datos[pos]->getFecha_hora()); pos--);
        if (dato->getFecha_hora() == raiz->datos[pos]->getFecha_hora()) {
            return false;
        }
    }

    if (setValue(dato, segundo, raiz->hijos[pos], nuevo)) {
        if (raiz->contador < MAX) {
            insertarNodo(pos, dato, raiz, *nuevo);
        } else {
            division(segundo, segundo, pos, raiz, *nuevo, nuevo);
        }
    }

    return true;

}

NodoB* ArbolB::nuevoNodo(Comentarios* dato, NodoB* nuevo){
    NodoB* nodo = new NodoB();
    nodo->datos[1] = dato;
    nodo->contador = 1;
    nodo->hijos[0] = raiz;
    nodo->hijos[1] = nuevo;
    return nodo;
}

void ArbolB::insertarNodo(int pos, Comentarios* dato, NodoB* raiz, NodoB* subarbol){
    int j = raiz->contador;

    while (j > pos){
        raiz->datos[j+1] = raiz->datos[j];
        j--;
    }

    raiz->datos[pos + 1] = dato;
    raiz->hijos[pos + 1] = subarbol;
    raiz->contador++;
}

void ArbolB::division(Comentarios* val, Comentarios*& apuntaVal, int pos, NodoB* raiz, NodoB* segundo, NodoB** child){
    int median, j;

    if (pos > MIN){
        median = MIN + 1;
    }else{
        median = MIN;
    }

    *child = new NodoB();
    j = median+1;
    while(j<= MAX){
        (*child)->datos[j-median] = raiz->datos[j];
        (*child)->hijos[j-median] = raiz->hijos[j];
        j++;
    }

    raiz->contador = median;
    (*child)->contador = MAX - median;

    if (pos <= MIN){
        insertarNodo(pos, val,raiz, segundo);
    }else{
        insertarNodo(pos-median, val, *child, segundo);
    }

    apuntaVal = raiz->datos[raiz->contador];
    (*child)->hijos[0] = raiz->hijos[raiz->contador];
    raiz->contador--;
}
