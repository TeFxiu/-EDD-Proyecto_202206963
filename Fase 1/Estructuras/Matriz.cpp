#include "Matriz.h"
#include "CircularDoble.cpp"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

Matriz::Matriz() {
    raiz = new NodoUser(new Usuario("raiz", -1));
}

bool Matriz::estaVacio() {
    return raiz->siguiente == nullptr ;
}

void Matriz::buscarColumna(Usuario* entrada, NodoUser*& auxColumna) {
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

void Matriz::buscarFila(Usuario* entrada, NodoUser*& auxFila, NodoUser*& auxColumna) {
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

void Matriz::insertarAmistad(Usuario* entrada, Usuario* amigo) {
    NodoUser* nuevoFila = new NodoUser(entrada);
    NodoUser* nuevoColumna = new NodoUser(entrada);
    NodoUser* amigoFila = new NodoUser(amigo);
    NodoUser* amigoColumna = new NodoUser(amigo);
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

void Matriz::eliminarAmistad(Usuario* usuario){
    NodoUser* auxFila = raiz;
    NodoUser* auxColumna = raiz;
    NodoUser* aux = nullptr;
    Usuario* amigo = nullptr;

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
            amigo->restarRelaciones();
            amigo->getPublicacionesAmigos()->eliminar(usuario->getEmail());
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

void Matriz::buscarColumnaTemp(Usuario *entrada, NodoUser *&auxColumna) {
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

void Matriz::buscarFilaTemp(Usuario* entrada, NodoUser*& auxFila, NodoUser*& auxColumna){
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

bool Matriz::insertarAmistad(Usuario* entrada, Usuario* amigo, bool bandera) {
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

void Matriz::reporte() {
    ofstream archDot("Matriz_de_relaciones.dot");
    archDot << "digraph Relaciones{"<< endl;
    archDot << "node[shape = \"box\"];"<< endl;
    int fila =0;

    NodoUser* rowAux = raiz;
    while(rowAux){
        string rank = "{rank = same";
        NodoUser* columnAux = rowAux;
        while(columnAux){
            string titulo = columnAux->dato->getNombre();
            string name;
            if (columnAux->amigo == nullptr && fila == 0) {
                name = "\"Nodo" + titulo + "\"";
            }else if (columnAux-> amigo == nullptr){
                name = "\"Nodo" + titulo + "1" + "\"";
                titulo = titulo + "1";
            }else{
                titulo = titulo + to_string(columnAux->dato->getId()) +"," + to_string(columnAux->amigo->getId())+","+
                         to_string(columnAux->id);
                name = "\"Nodo" + titulo + "\"";
            }
            string nodeDec;

            if (columnAux->dato->getId() == -1) {
                nodeDec = name + "[label = \"root\", group =\"" + to_string(fila) + "\"];";
            }else if (columnAux->amigo == nullptr && columnAux->bandera){
                nodeDec = name + "[label = \""+ columnAux->dato->getNombre()+"1" +"\", group =\"" + to_string(fila) + "\"];";
            }else if(columnAux->amigo == nullptr){
                nodeDec = name + "[label = \""+ columnAux->dato->getNombre() +"\", group =\"" + to_string(fila) + "\"];";
            }else{
                nodeDec = name + "[label = \" Relacionados\", group =\"" + to_string(fila) + "\"];";
            }

            archDot << nodeDec << endl;


            if (columnAux->siguiente && columnAux->siguiente->amigo == nullptr){
                string nombre = columnAux->siguiente->dato->getNombre();

                string conexion = "\"Nodo" + titulo + "\"->\"Nodo"+ nombre +"\"";
                string conexionBack = conexion + "[dir = back];";

                archDot << conexion << endl;
                archDot << conexionBack << endl;
            }else if (columnAux->siguiente){

                string nombre = columnAux->siguiente->dato->getNombre();
                string conexion = "\"Nodo" + titulo + "\"->\"Nodo"+ nombre+ to_string(columnAux->siguiente->dato->getId()) +"," + to_string(columnAux->siguiente->amigo->getId()) +","+
                                  to_string(columnAux->id)+ "\"";
                string conexionBack = conexion + "[dir = back];";

                archDot << conexion << endl;
                archDot << conexionBack << endl;
            }

            if (columnAux->abajo && columnAux->abajo->amigo == nullptr){
                string nombre = columnAux->abajo->dato->getNombre();

                string conexion = "\"Nodo" + titulo + "\"->\"Nodo"+ nombre+ "1" + "\"";
                string conexionBack = conexion + "[dir = back];";

                archDot << conexion << endl;
                archDot << conexionBack << endl;
            }else if (columnAux->abajo){
                string nombre = columnAux->abajo->dato->getNombre();
                string conexion = "\"Nodo" + titulo + "\"->\"Nodo"+ nombre+ to_string(columnAux->abajo->dato->getId()) +"," + to_string(columnAux->abajo->amigo->getId()) +","+
                                  to_string(columnAux->id)+ "\"";
                string conexionBack = conexion + "[dir = back];";
                archDot << conexion << endl;
                archDot << conexionBack << endl;
            }
            rank += ";\"Nodo"+ titulo + "\"";
            columnAux = columnAux->siguiente;

        }
        fila ++;
        rank += "}";
        archDot << rank << endl;
        rowAux = rowAux->abajo;
    }
    archDot << "}"<< endl;
    archDot.close();

    int result = system("dot -Tpng ./Matriz_de_relaciones.dot -o ./matriz_relaciones.png");
    if (result != 0) {
        cout << "Ocurrió un error al momento de crear la imagen" << endl;
    } else {
        cout << "La imagen fue generada exitosamente" << endl;
    }


}