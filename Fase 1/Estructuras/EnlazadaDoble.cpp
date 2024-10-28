#include "../headers/NodoStories.h"
#ifndef ENLAZADADOBLE_CPP
#define ENLAZADADOBLE_CPP

using namespace std;

class DoublyLinkedList{
    private:
        NodoStories *head;
        NodoStories *tail;
        NodoStories *actual;
        bool bandera;
    public:
        int contador;
        DoublyLinkedList():head(nullptr), tail(nullptr), actual(head), bandera(false){};

        bool estaVacia() {return head == nullptr;};

        void append(Publicacion* dato){
            NodoStories* newNodo = new NodoStories(dato);
            if (this->estaVacia()) {
                contador++;
                head = newNodo;
                tail = newNodo;
            }else{
                tail->siguiente = newNodo;
                newNodo->anterior = tail;
                tail = newNodo;
                contador++;
            }
        }

        void push(Publicacion* dato){
            NodoStories* newNodo = new NodoStories(dato);
            if (this->estaVacia()) {
                head = newNodo;
                tail = newNodo;
            }else{
                newNodo->siguiente = head;
                head->anterior = newNodo;
                head = newNodo;
            }
        }

        Publicacion* recorrerUno(){
            if (bandera){
                actual = head;
                bandera = false;
            }

            while(actual){
                NodoStories* aux = actual;
                actual = actual->siguiente;
                return aux->dato;
            }
            bandera = true;
            return nullptr;
        }
        /*

        void removeAll(string dato){
            NodoStories* temp = head;
            while(temp != nullptr){
                if (this->estaVacia()){
                    cout << "La lista esta vacia" <<endl;
                    return;

                }
                while(temp != nullptr && temp->dato->getUsuario() != dato){
                    temp = temp->siguiente;
                }
                if (temp == nullptr){
                    cout << "El dato no se encuentra en la lista" <<endl;
                    return;
                }

                if (temp == head){
                    NodoStories* del = head;
                    head = head->siguiente;
                    head->anterior = nullptr;
                    delete del;
                }else if (temp == tail){
                    NodoStories* del = tail;
                    tail = tail->anterior;
                    tail->siguiente = nullptr;
                    delete del;
                }else{
                    NodoStories* del = temp;
                    temp->anterior->siguiente = temp->siguiente;
                    temp->siguiente->anterior = temp->anterior;
                    temp = temp->siguiente;
                    delete del;
                }
            }
        }

        Publicacion* mostrarPublicacionesDer(){
            NodoStories* current = head;
            if (this->estaVacia()) {
                cout << "La lista esta vacia" << endl;
                return nullptr;
            }
            if (actual == nullptr){
                actual = head;
            }
            while(current != actual){
                current = current->siguiente;
            }

            Publicacion* devolver = current->dato;

            if (actual->siguiente != nullptr){
                actual = actual->siguiente;
            }else{
                actual = head;
                devolver->final = true;
            }
            return devolver;
        }
        Publicacion* mostrarPublicacionesIzq(){
            NodoStories* current = head;
            if (this->estaVacia()) {
                cout << "La lista esta vacia" << endl;
                return nullptr;
            }
            if (actual == nullptr){
                actual = tail;
            }
            while(current != actual){
                current = current->siguiente;
            }

            Publicacion* devolver = current->dato;

            if (actual->anterior != nullptr){
                actual = actual->anterior;
            }else{
                actual = tail;
                devolver->final = true;
            }
            return devolver;
        }
         */
/*
    void reporte(){
        ofstream archDot("Publicaciones.dot");
        archDot << "digraph Usuarios{"<< endl;
        archDot << "node[shape = \"box\"];"<< endl;
        archDot<< "rankdir=LR" << endl;

        NodoStories* actual = head;
        while(actual) {
            string nodo;
            string agregarParametros;
            if (actual == head) {
                nodo = "\"Nodo " + actual->dato->getTexto() + "\"";
                agregarParametros = nodo + "[label = \"" + actual->dato->getTexto() + " " + actual->dato->getId() +"\"];";
            }else {

                nodo = "\"Nodo " + actual->dato->getTexto() + "\"";
                string doble = nodo + "[dir=both];";
                archDot << doble << endl;
                agregarParametros = nodo + "[label = \"" + actual->dato->getTexto()+" "+ actual->dato->getId() +"\"];";
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

        int result = system("dot -Tpng ./Publicaciones.dot -o ./Publicaciones.png");
        if (result != 0) {
            cout << "Ocurrió un error al momento de crear la imagen" << endl;
        } else {
            cout << "La imagen fue generada exitosamente" << endl;
        }

    }

        void graph(){
            ofstream file("graph.dot");
            file<< "digraph G {" <<endl;
            file<< "rankdir=LR;" <<endl;
            file<< "node [shape=record];" <<endl;

            Nodo* current = head;
            int id = 0;
            while (current != nullptr){
                file << "node" << id << "[label=\"{" << current->dato.getEmail() << "|" << current->dato.getPass() << "}\"];" <<endl;
                if (current->siguiente != nullptr){
                    file << "node" << id << "->node" << id+1 << ";" <<endl;
                    file << "node" << id+1 << "->node" << id << ";" <<endl;

                }
                current = current->siguiente;
                id++;
            }

            file << "}" <<endl;
            file.close();

            string command = "dot -Tpng graph.dot -o graph.png";
            system(command.c_str());

        }
        */


};
#endif
