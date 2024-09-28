#include "Matriz.h"

using namespace std;

Matriz::Matriz() {
    raiz = new NodoUser(new UsuarioA("raiz", -1));
}

bool Matriz::estaVacio() {
    return raiz->siguiente == nullptr;
}

void Matriz::buscarColumna(UsuarioA* entrada, NodoUser*& auxColumna) {
    NodoUser* aux = raiz;
    while(aux->abajo != nullptr){
        if(aux->abajo->dato->getId() == entrada->getId()){
            delete auxColumna;
            auxColumna = aux->abajo;
            return;
        }else if(aux->abajo->dato->getId() > entrada->getId()){
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

//Metodo para buscar Cabezeras y tiene una llamada a la funcion que busca en las columnas el usuario correspondiente
void Matriz::buscarFila(UsuarioA* entrada, NodoUser*& auxFila, NodoUser*& auxColumna) {

    NodoUser* aux = raiz;

    while(aux->siguiente != nullptr){
        if(aux->siguiente->dato->getId() == entrada->getId()){
            delete auxFila;
            auxFila = aux->siguiente;
            buscarColumna(entrada, auxColumna);
            return;
        }else if(aux->siguiente->dato->getId() > entrada->getId()){
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
        if(aux->abajo->amigo->getId() == columna->dato->getId() || aux->abajo->dato->getId() == columna->dato->getId()){
            return nullptr;
        }
        if (aux->abajo->amigo->getId() == fila->dato->getId() && aux->abajo->dato->getId() > columna->dato->getId()){
            return aux->abajo;
        }else if(aux->abajo->dato->getId() == fila->dato->getId() && aux->abajo->amigo->getId() > columna->dato->getId()){
            return aux->abajo;
        }
        aux = aux->abajo;
    }
    return aux;
}

NodoUser* Matriz::buscarRelacionColumna(NodoUser* columna, NodoUser* fila) {
    NodoUser* aux = columna;
    while(aux->siguiente != nullptr){
        if(aux->siguiente->amigo->getId() == fila->dato->getId() || aux->siguiente->dato->getId() == fila->dato->getId()){
            return nullptr;
        }
        if(aux->siguiente->amigo->getId() == columna->dato->getId() && aux->siguiente->dato->getId() > fila->dato->getId()){
            return aux->siguiente;
        }else if(aux->siguiente->dato->getId() == columna->dato->getId() && aux->siguiente->amigo->getId() > fila->dato->getId()){
            return aux->siguiente;
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
        pivote->arriba->abajo = nuevo;
        nuevo->arriba = pivote->arriba;
        pivote->arriba = nuevo;
        nuevo->abajo = pivote;
    }

}

void Matriz::conectarColumna(NodoUser* pivote, NodoUser* nuevo) {
    if (pivote->siguiente == nullptr){
        pivote->siguiente = nuevo;
        nuevo->anterior = pivote;
    }else{
        pivote->anterior->siguiente = nuevo;
        nuevo->anterior = pivote->anterior;
        pivote->anterior = nuevo;
        nuevo->siguiente = pivote;
    }
}

// Insertar Cabeceraz correspondientes
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



void Matriz::eliminarAmistad(UsuarioA* usuario){
    NodoUser* auxFila = raiz;
    NodoUser* auxColumna = raiz;
    NodoUser* aux = nullptr;
    UsuarioA* amigo = nullptr;

    while (auxColumna->dato->getId() != usuario->getId()){
        auxColumna = auxColumna->abajo;
    }

    auxColumna->arriba->abajo = auxColumna->abajo;
    auxColumna->abajo->arriba = auxColumna->arriba;
    aux = auxColumna->siguiente;
    delete auxColumna;
    if (aux != nullptr){
        do{
            auxColumna = aux->siguiente;
            if (aux->dato->getId() < usuario->getId()){
                amigo = aux->dato;
            }else if(aux->amigo->getId() > usuario->getId()){
                amigo = aux->amigo;
            }
            aux->arriba->abajo = aux->abajo;
            if(aux->abajo != nullptr){
                aux->abajo->arriba = aux->arriba;
            }
            delete aux;
            aux = auxColumna;
        }while (auxColumna != nullptr);
        amigo = nullptr;
        aux = nullptr;
    }


    while (auxFila->dato->getId() != usuario->getId()){
        auxFila = auxFila->siguiente;
    }
    auxFila->anterior->siguiente = auxFila->siguiente;
    auxFila->siguiente->anterior = auxFila->anterior;
    aux = auxFila->abajo;
    delete auxFila;

    if (aux != nullptr){
        do{
            auxFila = aux->abajo;
            aux->anterior->siguiente = aux->siguiente;
            if (aux->siguiente != nullptr) {
                aux->siguiente->anterior = aux->anterior;
            }
            delete aux;
            aux = auxFila;
        }while (auxFila != nullptr);
        amigo = nullptr;
        aux = nullptr;
    }

}

void Matriz::buscarColumnaTemp(UsuarioA *entrada, NodoUser *&auxColumna) {
    NodoUser* aux = raiz;
    while(aux->abajo != nullptr) {
        if (aux->abajo->dato->getId() == entrada->getId()) {
            delete auxColumna;
            auxColumna = aux->abajo;
            return;
        }
        aux = aux->abajo;
    }
}

void Matriz::buscarFilaTemp(UsuarioA* entrada, NodoUser*& auxFila, NodoUser*& auxColumna){
    NodoUser* aux = raiz;
    while(aux->siguiente != nullptr) {
        if (aux->siguiente->dato->getId() == entrada->getId()) {
            delete auxFila;
            auxFila = aux->siguiente;
            buscarColumnaTemp(entrada, auxColumna);
            return;
        }
        aux = aux->siguiente;
    }
}

bool Matriz::insertarAmistad(UsuarioA* entrada, UsuarioA* amigo, bool bandera) {
    NodoUser* nuevoFila = nullptr;
    NodoUser* amigoFila = nullptr;
    NodoUser* amigoColumna = nullptr;
    NodoUser* nuevoColumna = nullptr;
    if (estaVacio()){
        return true;
    }

    buscarFilaTemp(entrada, nuevoFila, nuevoColumna);
    buscarFilaTemp(amigo, amigoFila, amigoColumna);
    if(nuevoFila == nullptr || amigoFila == nullptr){
        return true;
    }

    nuevoFila = buscarRelacionFila(nuevoFila, amigoColumna);
    if (nuevoFila == nullptr){
        return false;
    }
    return true;
}

bool Matriz::buscarAmistad(std::string amigo, std::string perfil) {
    NodoUser* aux = raiz;
    while(aux->siguiente != nullptr) {
        if (aux->siguiente->dato->getEmail() == amigo) {
            aux = aux->siguiente;
            while (aux->abajo != nullptr){
                if (aux->abajo->amigo->getEmail() == perfil){
                    return true;
                }
                aux = aux->abajo;
            }
        }
        aux = aux->siguiente;
    }
    return false;
}

void Matriz::insertarAmistad(UsuarioA* entrada, UsuarioA* amigo) {
    NodoUser* nuevoFila = new NodoUser(entrada, 0);
    NodoUser* nuevoColumna = new NodoUser(0, entrada);
    NodoUser* amigoFila = new NodoUser(amigo, 0);
    NodoUser* amigoColumna = new NodoUser(0, amigo);

    if(estaVacio()){
        if (entrada->getId() < amigo->getId() ){
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


    if (entrada->getId() < amigo->getId()){
        nuevaRelacion1 = new NodoUser(entrada, amigo);
        nuevaRelacion2 = new NodoUser(entrada, amigo, false);
    }else{
        nuevaRelacion1 = new NodoUser(amigo, entrada);
        nuevaRelacion2 = new NodoUser(amigo, entrada, false);
    }

    nuevoColumna->bandera = true;
    amigoColumna->bandera = true;
    nuevoFila = buscarRelacionFila(nuevoFila, amigoColumna);
    if (nuevoFila == nullptr){
        return;
    }
    amigoFila = buscarRelacionFila(amigoFila, nuevoColumna);
    nuevoColumna = buscarRelacionColumna(nuevoColumna, amigoFila);
    amigoColumna = buscarRelacionColumna(amigoColumna, nuevoFila);

    conectarFila(nuevoFila, nuevaRelacion1);
    conectarFila(amigoFila, nuevaRelacion2);
    conectarColumna(nuevoColumna, nuevaRelacion2);
    conectarColumna(amigoColumna, nuevaRelacion1);

}
