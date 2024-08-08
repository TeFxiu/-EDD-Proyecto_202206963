#include <iostream>
#include <string>
#include "../headers/Nodo.h"

using namespace std;

class DoublyLinkedList{
    private:
        Nodo *head;
        Nodo *tail;
    public:
        DoublyLinkedList():head(nullptr), tail(nullptr){};
        bool estaVacia() {return head == nullptr;};
        void append(Usuario dato){
            Nodo* newNodo = new Nodo(dato);
            if (this->estaVacia()) {
                head = newNodo;
                tail = newNodo;
            }else{
                tail->siguiente = newNodo;
                newNodo->anterior = tail;
                tail = newNodo;
            }
        }

        void push(Usuario dato){
            Nodo* newNodo = new Nodo(dato);
            if (this->estaVacia()) {
                head = newNodo;
                tail = newNodo;
            }else{
                newNodo->siguiente = head;
                head->anterior = newNodo;
                head = newNodo;
            }
        }

        void remove(string dato){
            Nodo* temp = head;
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
                Nodo* del = head;
                head = head->siguiente;
                head->anterior = nullptr;
                delete del;
            }else if (temp == tail){
                Nodo* del = tail;
                tail = tail->anterior;
                tail->siguiente = nullptr;
                delete del;
            }else{
                Nodo* del = temp;
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                delete del;
            }

            
            
        }

        void graph(){
            ofstream file(graph.dot);
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

}