#include <iostream>
#include <string>
#include "../headers/NodoUser.h"

#ifndef CIRCULARDOBLE_CPP
#define CIRCULARDOBLE_CPP
using namespace std;

class DoublyCircular {
private:
    NodoUser *head;
    NodoUser *tail;
public:
    DoublyCircular() : head(nullptr), tail(nullptr) {};

    bool estaVacia() { return head == nullptr; };

    void append(Usuario dato) {
        NodoUser *newNodo = new NodoUser(dato);
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

    void push(Usuario dato) {
        NodoUser *newNodo = new NodoUser(dato);
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

    bool search(string dato) {
        NodoUser *temp = head;
        if (this->estaVacia()) {
            cout << "La lista esta vacia" << endl;
            return false;
        }
        do {
            if (temp->dato.getEmail() == dato) {
                return true;
            }
            temp = temp->siguiente;
        } while (temp != head);
        return false;

    }

    void remove(string dato) {
        NodoUser *temp = head;
        if (this->estaVacia()) {
            cout << "La lista esta vacia" << endl;
            return;
        }
        do {
            if (temp->dato.getEmail() == dato) {
                if (temp == head) {
                    NodoUser *del = head;
                    head = head->siguiente;
                    tail->siguiente = head;
                    head->anterior = tail;
                    delete del;
                } else if (temp == tail) {
                    NodoUser *del = tail;
                    tail = tail->anterior;
                    head->anterior = tail;
                    tail->siguiente = head;
                    delete del;
                } else {
                    NodoUser *del = temp;
                    temp->anterior->siguiente = temp->siguiente;
                    temp->siguiente->anterior = temp->anterior;
                    delete del;
                }
            }
            temp = temp->siguiente;

        } while (temp != head);


    }
};
#endif