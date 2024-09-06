#include <iostream>
#include <string>
#include "../headers/NodoUser.h"
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
        ofstream archDot("Usuarios.dot");
        archDot << "digraph Usuarios{"<< endl;
        archDot << "node[shape = \"box\"];"<< endl;
        archDot<< "rankdir=LR" << endl;

        NodoUser* actual = head;
        while(actual) {
            string nodo;
            string agregarParametros;
            if (actual == head) {
                nodo = "\"Nodo" + to_string(actual->dato->getId()) + "\"";
                agregarParametros = nodo + "[label = \"" + actual->dato->getNombre() +"\"];";
            }else {
                nodo = "\"Nodo" + to_string(actual->dato->getId()) + "\"";
                archDot << nodo << endl;
                agregarParametros = nodo + "[label = \"" + actual->dato->getNombre() +"\"];";
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

        int result = system("dot -Tpng ./Usuarios.dot -o ./Usuarios.png");
        if (result != 0) {
            cout << "Ocurrió un error al momento de crear la imagen" << endl;
        } else {
            cout << "La imagen fue generada exitosamente" << endl;
        }

    }
};