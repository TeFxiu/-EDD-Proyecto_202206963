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
public:
    DoublyCircular() : head(nullptr), tail(nullptr) {};

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


};
#endif