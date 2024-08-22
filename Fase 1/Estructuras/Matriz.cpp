#include "Matriz.h"
using namespace std;

Matriz::Matriz() {
    raiz = new NodoUser(Usuario("raiz", -1));
}

bool Matriz::estaVacio() {
    return raiz->siguiente == nullptr ;
}

void Matriz::buscarColumna(Usuario entrada, NodoUser*& auxColumna) {
    NodoUser* aux = raiz;
    while(aux->abajo != nullptr){
        if(aux->abajo->dato.getId() == entrada.getId()){
            delete auxColumna;
            auxColumna = aux->abajo;
            return;
        }else if(aux->abajo->dato.getId() > entrada.getId()){
            auxColumna->abajo = aux->abajo;
            aux->abajo->arriba = auxColumna;
            aux->abajo = auxColumna;
            auxColumna->arriba = aux;
            return;
        }
        aux = aux->abajo;
    }
    aux->abajo = auxColumna;
    auxColumna->arriba = aux;
}

void Matriz::buscarFila(Usuario entrada, NodoUser*& auxFila, NodoUser*& auxColumna) {
    NodoUser* aux = raiz;
    while(aux->siguiente != nullptr){
        if(aux->siguiente->dato.getId() == entrada.getId()){
            delete auxFila;
            auxFila = aux->siguiente;
            buscarColumna(entrada, auxColumna);
            return;
        }else if(aux->siguiente->dato.getId() > entrada.getId()){
            auxFila->siguiente = aux->siguiente;
            aux->siguiente->anterior = auxFila;
            aux->siguiente = auxFila;
            auxFila->anterior = aux;
            buscarColumna(entrada, auxColumna);
            return;
        }
        aux = aux->siguiente;
    }
    aux->siguiente = auxFila;
    auxFila->anterior = aux;

    buscarColumna(entrada , auxColumna);
}

NodoUser* Matriz::buscarRelacionFila(NodoUser* fila, NodoUser* columna) {
    NodoUser* aux = fila;
    while(aux->abajo != nullptr){
        if(aux->abajo->amigo.getId() == columna->dato.getId() || aux->abajo->dato.getId() == columna->dato.getId()){
            return nullptr;
        }else if (aux->abajo->amigo.getId() > columna->dato.getId() || aux->abajo->dato.getId() > columna->dato.getId()){
            return aux;
        }
        aux = aux->abajo;
    }
    return aux;
}

NodoUser* Matriz::buscarRelacionColumna(NodoUser* columna, NodoUser* fila) {
    NodoUser* aux = columna;
    while(aux->siguiente != nullptr){
        if(aux->siguiente->amigo.getId() == fila->dato.getId() || aux->siguiente->dato.getId() == fila->dato.getId()){
            return nullptr;
        }else if (aux->siguiente->amigo.getId() > fila->dato.getId() || aux->siguiente->dato.getId() > fila->dato.getId()){
            return aux;
        }
        aux = aux->siguiente;
    }
    return aux;
}

void Matriz::conectarFila(NodoUser* pivote, NodoUser* nuevo) {
    if (pivote->abajo == nullptr){
        pivote->abajo = nuevo;
        nuevo->arriba = pivote;
    }else{
        nuevo->abajo = pivote->abajo;
        pivote->abajo->arriba = nuevo;
        pivote->abajo = nuevo;
        nuevo->arriba = pivote;
    }

}

void Matriz::conectarColumna(NodoUser* pivote, NodoUser* nuevo) {
    if (pivote->siguiente == nullptr){
        pivote->siguiente = nuevo;
        nuevo->anterior = pivote;
    }else{
        nuevo->siguiente = pivote->siguiente;
        pivote->siguiente->anterior = nuevo;
        pivote->siguiente = nuevo;
        nuevo->anterior = pivote;
    }
}

void Matriz::insertarInicio(NodoUser* raiz , NodoUser* primeroFila, NodoUser* segundoFila, NodoUser* primeroColumna, NodoUser* segundoColumna) {
        raiz->siguiente = primeroFila;
        primeroFila->anterior = raiz;
        raiz->abajo = primeroColumna;
        primeroColumna->arriba = raiz;
        primeroFila->siguiente = segundoFila;
        segundoFila->anterior = primeroFila;
        primeroColumna->abajo = segundoColumna;
        segundoColumna->arriba = primeroColumna;

}

void Matriz::insertarAmistad(Usuario& entrada, Usuario& amigo) {
    NodoUser* nuevoFila = new NodoUser(entrada);
    NodoUser* nuevoColumna = new NodoUser(entrada);
    NodoUser* amigoFila = new NodoUser(amigo);
    NodoUser* amigoColumna = new NodoUser(amigo);
    if(estaVacio()){
        if (entrada.getId() < amigo.getId() ){
            insertarInicio(raiz, nuevoFila, amigoFila, nuevoColumna, amigoColumna);
        }
        else{
            insertarInicio(raiz, amigoFila, nuevoFila, amigoColumna, nuevoColumna);
        }
    }else{
        buscarFila(entrada, nuevoFila, nuevoColumna);
        buscarFila(amigo, amigoFila, amigoColumna);
    }
    NodoUser* nuevaRelacion1;
    NodoUser* nuevaRelacion2;

    if (entrada.getId() < amigo.getId()){
        nuevaRelacion1 = new NodoUser(entrada, amigo);
        nuevaRelacion2 = new NodoUser(entrada, amigo);
    }else{
        nuevaRelacion1 = new NodoUser(amigo, entrada);
        nuevaRelacion2 = new NodoUser(amigo, entrada);
    }

    nuevoFila = buscarRelacionFila(nuevoFila, amigoColumna);
    if (nuevoFila == nullptr){
        cout << "Ya existe una relacion entre estos usuarios" << endl;
        return;
    }
    amigoFila = buscarRelacionFila(amigoFila, nuevoColumna);
    nuevoColumna = buscarRelacionColumna(nuevoColumna, amigoFila);
    amigoColumna = buscarRelacionColumna(amigoColumna, nuevoFila);

    conectarFila(nuevoFila, nuevaRelacion1);
    conectarFila(amigoFila, nuevaRelacion2);
    conectarColumna(nuevoColumna, nuevaRelacion2);
    conectarColumna(amigoColumna, nuevaRelacion1);
    cout << "Se acepto la solicitud" << endl;    
}

bool Matriz::insertarAmistad(Usuario& entrada, Usuario& amigo, bool bandera) {
    NodoUser* nuevoFila = new NodoUser(entrada);
    NodoUser* nuevoColumna = new NodoUser(entrada);
    NodoUser* amigoFila = new NodoUser(amigo);
    NodoUser* amigoColumna = new NodoUser(amigo);
    if(estaVacio()){
        if (entrada.getId() < amigo.getId() ){
            insertarInicio(raiz, nuevoFila, amigoFila, nuevoColumna, amigoColumna);
        }
        else{
            insertarInicio(raiz, amigoFila, nuevoFila, amigoColumna, nuevoColumna);
        }
    }else{
        buscarFila(entrada, nuevoFila, nuevoColumna);
        buscarFila(amigo, amigoFila, amigoColumna);
    }
    NodoUser* nuevaRelacion1;
    NodoUser* nuevaRelacion2;

    if (entrada.getId() < amigo.getId()){
        nuevaRelacion1 = new NodoUser(entrada, amigo);
        nuevaRelacion2 = new NodoUser(entrada, amigo);
    }else{
        nuevaRelacion1 = new NodoUser(amigo, entrada);
        nuevaRelacion2 = new NodoUser(amigo, entrada);
    }

    nuevoFila = buscarRelacionFila(nuevoFila, amigoColumna);
    if (nuevoFila == nullptr){
        return false;
    }
    return true;
}