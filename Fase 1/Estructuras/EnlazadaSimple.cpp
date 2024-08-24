#include <iostream>
#include <string>
#include "../headers/NodoUser.h"
#include <iomanip>
#include <fstream>

using namespace std;

class ListaSimple{
    private:
        NodoUser* head;
        NodoUser* retorno;
    public:
        ListaSimple():head(nullptr),retorno(nullptr){};
        
        bool estaVacia() {return head == nullptr;};

        void append(Usuario* dato){
            NodoUser* newNodo = new NodoUser(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                NodoUser* temp = head;
                while (temp->siguiente != nullptr)
                {
                    temp = temp->siguiente;
                }
                temp->siguiente = newNodo;
            }
        };

        void push(Usuario* dato){
            NodoUser* newNodo = new NodoUser(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                newNodo->siguiente = head;
                head = newNodo;
            }
        }

        bool findEmail(string email){
            NodoUser* temp = head;
            while (temp != nullptr && temp->dato->getEmail() != email)
            {
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                return true;
            }else{
                retorno = temp;
                return false;
            }
        }

        bool comprobarCredenciales(string email, string pass){
            NodoUser* temp = head;
            while (temp != nullptr && temp->dato->getEmail() != email)
            {
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                return false;
            }else{
                if (temp->dato->getPass() == pass){
                    retorno = temp;
                    return true;
                }else{
                    return false;
                }
            }
        }

        Usuario* getCredenciales(){
                NodoUser* temp = retorno;
                retorno = nullptr;
                return temp->dato;
        }

        void remove(string dato){
            if (estaVacia()){
                cout << "La lista esta vacia" <<endl;
            }else if (head->dato->getEmail() == dato){
                NodoUser* temp = head;
                head = head->siguiente;
                delete temp->dato;
                delete temp;
            }else{
                NodoUser* temp = head;
                NodoUser* previo = nullptr;
                while (temp != nullptr && temp->dato->getEmail() != dato)
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

        void reporte(){
            ofstream archDot("Matriz de relaciones.dot");
            archDot << "digraph Relaciones{"<< endl;
            archDot << "node[shape = \"box\"];"<< endl;

            NodoUser* rowAux = head;
            while(rowAux){
                string rank = "{rank = same";
            }
            return;
        }
};
