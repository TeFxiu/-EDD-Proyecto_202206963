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
            cout << top->dato.getEmisor()->getEmail() ;
        }

        Usuario* pop(){
            if (this->estaVacia()){
                return nullptr;
            }else{
                NodoAmistad* temp = top;
                top = top->siguiente;
                Usuario* user = temp->dato.getEmisor();
                delete temp;
                return user;
            }
        }
};