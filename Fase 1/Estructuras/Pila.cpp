#include <string>
#include <iostream>
#include "../headers/NodoAmistad.h"


using namespace std;

class Pila{
    private:
        NodoAmistad* top;
    public:
        Pila(): top(nullptr) {};
        bool estaVacia() {return top == nullptr;};
        
        void push(Amistad dato){
            NodoAmistad* newNodo = new NodoAmistad(dato);
            if (this->estaVacia()) {
                top = newNodo;
            }else{
                newNodo->siguiente = top;
                top = newNodo;
            }
        };

        bool findEmail(string email){
            NodoAmistad* temp = top;
            while(temp != nullptr && temp->dato.getEmisor()->getEmail() != email){
                temp = temp->siguiente;
            }
            if (temp == nullptr)
            {
                return false;    
            }else{
                return true;
            }
            
        }

        bool elementosMinimos(){
            return top->siguiente != nullptr;
        }

        void mostrarTop(){
            cout << top->dato.getEmisor()->getNombre() << top->dato.getEmisor()->getApellido();
        }

        Usuario* pop(){
            if (this->estaVacia()){
                return nullptr;
            }else{
                NodoAmistad* temp = top;
                top = top->siguiente;
                Usuario* user = temp->dato.getEmisor();
                return user;
            }
        }

        void eliminarCola(string eliminando){
            NodoAmistad* temp = top;
            NodoAmistad* prev = nullptr;
            while (temp != nullptr && temp->dato.getEmisor()->getEmail() != eliminando)
            {
                prev = temp;
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                cout << "El dato no se encuentra en la lista" <<endl;
                return;
            }
            if (prev == nullptr){
                top = top->siguiente;
                delete temp;
                return;
            }
            prev->siguiente = temp->siguiente;
            delete temp;
        }
};