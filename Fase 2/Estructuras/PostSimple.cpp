//
// Created by TeFxiu on 9/11/2024.
//

#include "PostSimple.h"

PostSimple::PostSimple() {
    head = nullptr;
    retorno = nullptr;
}

bool PostSimple::estaVacia() {
    return head == nullptr;
}

void PostSimple::append(Publicacion* dato){
    NodoStories* newNodo = new NodoStories(dato);
    if (this->estaVacia()) {
        head = newNodo;
    }else{
        NodoStories* temp = head;
        while (temp->siguiente != nullptr)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = newNodo;
    }
}

void PostSimple::push(Publicacion* dato){
    NodoStories* newNodo = new NodoStories(dato);
    if (this->estaVacia()) {
        head = newNodo;
    }else{
        newNodo->siguiente = head;
        head = newNodo;
    }
}

time_t PostSimple::buscarFecha(){
    if (head != nullptr) {
        return head->dato->getFecha();
    }
    return -1;
}



/*
Publicacion* PostSimple::buscarPublicacion(string correo){
    NodoStories* temp = head;
    while (temp != nullptr && temp->dato->getEmail() != email)
    {
        temp = temp->siguiente;
    }
    if (temp == nullptr){
        return true;
    }else{
        retorno = temp;
        return false;
    }
}


    void PostSimple::reporte(){
        ofstream archDot("Usuarios.dot");
        archDot << "digraph Usuarios{"<< endl;
        archDot << "node[shape = \"box\"];"<< endl;
        archDot<< "rankdir=LR" << endl;

        NodoStories* actual = head;
        while(actual) {
            string nodo;
            string agregarParametros;
            if (actual == head) {
                nodo = "\"Nodo" + to_string(actual->dato->getId()) + "\"";
                agregarParametros = nodo + "[label = \"" + actual->dato->getNombre() +"\"];";
            }else {
                nodo = "\"Nodo" + to_string(actual->dato->getId()) + "\"";
                archDot << nodo << endl;
                agregarParametros = nodo + "[label = \"" + actual->dato->getNombre() +"\"];";
            }
            archDot << agregarParametros << endl;
            archDot << nodo;
            if (actual->siguiente) {
                string conexion  = "->";
                archDot << conexion;
            }
            actual = actual->siguiente;

        }
        archDot << "}"<< endl;
        archDot.close();

        int result = system("dot -Tpng ./Usuarios.dot -o ./Usuarios.png");
        if (result != 0) {
            cout << "Ocurrió un error al momento de crear la imagen" << endl;
        } else {
            cout << "La imagen fue generada exitosamente" << endl;
        }

    }
    */