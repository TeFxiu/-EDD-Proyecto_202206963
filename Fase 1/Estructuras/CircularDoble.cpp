/*
 #include <iostream>
#include <string>
#include "../headers/NodoListas.h"

#ifndef CIRCULARDOBLE_CPP
#define CIRCULARDOBLE_CPP
using namespace std;

class DoublyCircular {
private:
    NodoListas *head;
    NodoListas *tail;
    NodoListas *actual;
public:
    DoublyCircular() : head(nullptr), tail(nullptr), actual(head) {};

    bool estaVacia() { return head == nullptr; };

    void append(DoublyLinkedList* dato) {
        NodoListas *newNodo = new NodoListas(dato);
        if (this->estaVacia()) {
            head = newNodo;
            tail = newNodo;
            head->siguiente = tail;
            tail->siguiente = head;
            head->anterior = tail;
            tail->anterior = head;
        } else {
            tail->siguiente = newNodo;
            head->anterior = newNodo;
            newNodo->anterior = tail;
            newNodo->siguiente = head;
            tail = newNodo;
        }
    }

    void push(DoublyLinkedList* dato) {
        NodoListas *newNodo = new NodoListas(dato);
        if (this->estaVacia()) {
            head = newNodo;
            tail = newNodo;
            head->siguiente = tail;
            tail->siguiente = head;
            head->anterior = tail;
            tail->anterior = head;
        } else {
            head->anterior = newNodo;
            tail->siguiente = newNodo;
            newNodo->siguiente = head;
            newNodo->anterior = tail;
            head = newNodo;
        }
    }

    Publicacion* mostrarPublicacionDer(){
        if (estaVacia()){
            cout << "No hay publicaciones por mostrar"<< endl;
            return nullptr;
        }
        if (actual == nullptr){
            actual = head;
        }
        NodoListas* temp = head;
        while(temp != actual){
            temp = temp->siguiente;
        }

        Publicacion* contenido = temp->listaPublicaciones->mostrarPublicacionesDer();
        if (contenido == nullptr){
            return contenido;
        }

        if (contenido->final){
            actual = actual->siguiente;
        }
        return contenido;
    }
    Publicacion* mostrarPublicacionIzq(){
        if (estaVacia()){
            cout << "No hay publicaciones por mostrar"<< endl;
            return nullptr;
        }
        if (actual == nullptr){
            actual = head;
        }
        NodoListas* temp = head;
        while(temp != actual){
            temp = temp->siguiente;
        }

        Publicacion* contenido = temp->listaPublicaciones->mostrarPublicacionesIzq();
        if (contenido == nullptr){
            return contenido;
        }

        if (contenido->final){
            actual = actual->anterior;
        }
        return contenido;
    }

    void eliminar(string email){
        if (estaVacia()){
            cout << "No hay publicaciones por eliminar" << endl;
            return;
        }
        NodoListas* temp = head;
        while(temp->listaPublicaciones->propietario != email){
            temp = temp->siguiente;
        }

        if (temp == head && temp == tail){
            head = nullptr;
            tail = nullptr;
            delete temp;
            return;
        }

        if (temp == head){
            head = head->siguiente;
            head->anterior = tail;
            tail->siguiente = head;
            delete temp;
            return;
        }

        if (temp == tail){
            tail = tail->anterior;
            tail->siguiente = head;
            head->anterior = tail;
            delete temp;
            return;
        }

        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
        delete temp;
        return;

    }
    void reporte(){
        ofstream archDot("Amigos.dot");
        archDot << "digraph Amigos{"<< endl;
        archDot << "node[shape = \"box\"];"<< endl;
        archDot<< "rankdir=LR" << endl;

        NodoListas* actual = head;
        do{
            string nodo;
            string agregarParametros;
            if (actual == head) {
                nodo = "\"Nodo " + actual->listaPublicaciones->propietario + "\"";
                agregarParametros = nodo + "[label = \"" + actual->listaPublicaciones->propietario  +"\"];";
            }else {

                nodo = "\"Nodo " + actual->listaPublicaciones->propietario + "\"";
                string doble = nodo + "[dir=both];";
                archDot << doble << endl;
                agregarParametros = nodo + "[label = \"" + actual->listaPublicaciones->propietario +"\"];";
            }
            archDot << agregarParametros << endl;
            archDot << nodo;
            if (actual->siguiente) {
                string conexion  = "->";
                archDot << conexion;
            }
            actual = actual->siguiente;

        }while(actual == head);
        archDot << "}"<< endl;
        archDot.close();

        int result = system("dot -Tpng ./Amigos.dot -o ./Amigos.png");
        if (result != 0) {
            cout << "Ocurrió un error al momento de crear la imagen" << endl;
        } else {
            cout << "La imagen fue generada exitosamente" << endl;
        }

    }
};
#endif
 */