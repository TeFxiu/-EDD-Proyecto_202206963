#include <iostream>
#include <string>
#include "../headers/Nodo.h"

using namespace std;

class ListaSimple{
    private:
        Nodo *head;
        Nodo* retorno;
    public:
        ListaSimple():head(nullptr),retorno(nullptr){};
        
        bool estaVacia() {return head == nullptr;};

        void append(Usuario dato){
            Nodo* newNodo = new Nodo(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                Nodo* temp = head;
                while (temp->siguiente != nullptr)
                {
                    temp = temp->siguiente;
                }
                temp->siguiente = newNodo;
            }
        };

        void push(Usuario dato){
            Nodo* newNodo = new Nodo(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                newNodo->siguiente = head;
                head = newNodo;
            }
        }

        void mostrarDatos(){
            Nodo* temp = head;
            while (temp != nullptr){
                cout << temp->dato.getNombre() <<endl;
                cout << temp->dato.getApellido() <<endl;
                cout << temp->dato.getFechaNac() <<endl;
                cout << temp->dato.getEmail() <<endl;
                cout << temp->dato.getPass() <<endl;
                temp = temp->siguiente;
            }
        };

        bool findEmail(string email){
            Nodo* temp = head;
            while (temp != nullptr && temp->dato.getEmail() != email)
            {
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                return true;
            }else{
                cout << "El correo ya le pertenece a un Usuario de la plataforma" <<endl;
                return false;
            }
        }

        bool comprobarCredenciales(string email, string pass){
            Nodo* temp = head;
            while (temp != nullptr && temp->dato.getEmail() != email)
            {
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                return false;
            }else{
                if (temp->dato.getPass() == pass){
                    retorno = temp;
                    return true;
                }else{
                    return false;
                }
            }
        }

        Usuario getCredenciales(){
                Nodo* temp = retorno;
                retorno = nullptr;
                return temp->dato;
        }

        void remove(string dato){
            if (estaVacia()){
                cout << "La lista esta vacia" <<endl;
            }else if (head->dato.getEmail() == dato){
                Nodo* temp = head;
                head = head->siguiente;
                delete temp;
            }else{
                Nodo* temp = head;
                Nodo* previo = nullptr;
                while (temp != nullptr && temp->dato.getEmail() != dato)
                {
                    previo = temp;
                    temp = temp->siguiente;
                }
                if (temp == nullptr){
                    cout << "El dato no se encuentra en la lista" <<endl;
                }else{
                    previo->siguiente = temp->siguiente;
                    delete temp;
                    cout<< "Dato eliminado" <<endl;
                }
            }
            return;

        }

        Usuario getDatoHead(){
            return head->dato;
        }
};
