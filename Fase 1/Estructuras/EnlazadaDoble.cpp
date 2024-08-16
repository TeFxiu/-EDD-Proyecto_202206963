#include <iostream>
#include <string>
#include "../headers/NodoStories.h"

#ifndef ENLAZADADOBLE_CPP
#define ENLAZADADOBLE_CPP

using namespace std;

class DoublyLinkedList{
    private:
        NodoStories *head;
        NodoStories *tail;
    public:
        DoublyLinkedList():head(nullptr), tail(nullptr){};
        bool estaVacia() {return head == nullptr;};
        void append(Publicacion dato){
            NodoStories* newNodo = new NodoStories(dato);
            if (this->estaVacia()) {
                head = newNodo;
                tail = newNodo;
            }else{
                tail->siguiente = newNodo;
                newNodo->anterior = tail;
                tail = newNodo;
            }
        }

        void push(Publicacion dato){
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

        /*
        void remove(string dato){
            NodoStories* temp = head;
            if (this->estaVacia()){
                cout << "La lista esta vacia" <<endl;
                return;

            }
            while(temp != nullptr && temp->dato.getEmail() != dato){
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
                delete del;
            }

            
            
        }*/

        void mostrar(){
            NodoStories* current = head;
            if (this->estaVacia()){
                cout << "La lista esta vacia" <<endl;
                return;
            }
            while(current != nullptr) {
                cout << "Email: " << current->dato.getId() << endl;
                cout << "Texto: " << current->dato.getTexto() << endl;
                cout << "Fecha: " << current->dato.getFecha() << endl;
                cout << "Hora:  " << current->dato.getHora() << endl;
                cout << "--------------------------------" << endl;
                current = current->siguiente;
            }
        }


        /*
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