#include <iostream>
#include <string>
#include "../headers/NodoAmistad.h"

using namespace std;

class SimpleAmistad{
    private:
        NodoAmistad *head;
        NodoAmistad* retorno;
        bool bandera = true;
    public:
        int contador = 0;
        SimpleAmistad():head(nullptr),retorno(nullptr){};
        
        bool estaVacia() {return head == nullptr;};

        void append(Amistad dato){
            NodoAmistad* newNodo = new NodoAmistad(dato);
            if (this->estaVacia()) {
                head = newNodo;
                contador++;
            }else{
                NodoAmistad* temp = head;
                while (temp->siguiente != nullptr)
                {
                    temp = temp->siguiente;
                }
                temp->siguiente = newNodo;
                contador++;
            }
        };
        Usuario* recorreraUno() {
            if (bandera){
                retorno = head;
                bandera = false;
            }
            if (retorno != nullptr){
                Usuario* ret = retorno->dato.getReceptor();
                retorno = retorno ->siguiente;
                return ret;
            }
            bandera = true;
            return nullptr;
        }

        Amistad extraer(){
            if (this->estaVacia()){
                cout << "La lista esta vacia" << endl;
                return Amistad(nullptr, nullptr);
            }else{
                NodoAmistad* temp = head;
                head = head->siguiente;
                Amistad dato = temp->dato;
                return dato;
            }
        }

        void push(Amistad dato){
            NodoAmistad* newNodo = new NodoAmistad(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                newNodo->siguiente = head;
                head = newNodo;
            }
        }

        bool findEmail(string email){
            NodoAmistad* temp = head;
            while (temp != nullptr)
            {
                if (temp->dato.getReceptor()->getEmail() == email){
                    break;
                }
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                return false;
            }else{
                return true;
            }
        };

        void solicitudRechazada(string email){
            NodoAmistad* temp = head;
            NodoAmistad* temp2 = nullptr;

            while (temp != nullptr){
                if (temp->dato.getReceptor()->getEmail() == email){
                    break;
                }
                temp2 = temp;
                temp = temp->siguiente;
            }

            if (temp == nullptr){
                return;
            }else{
                if (temp2 == nullptr){
                    head = temp->siguiente;
                }else{
                    temp2->siguiente = temp->siguiente;
                }
                contador--;
            }
        };
};
