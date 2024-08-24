#include <iostream>
#include <string>
#include "../headers/NodoAmistad.h"
#include <iomanip>
#include <fstream>

using namespace std;

class SimpleAmistad{
    private:
        NodoAmistad *head;
        NodoAmistad* retorno;
    public:
        SimpleAmistad():head(nullptr),retorno(nullptr){};
        
        bool estaVacia() {return head == nullptr;};

        void append(Amistad dato){
            NodoAmistad* newNodo = new NodoAmistad(dato);
            if (this->estaVacia()) {
                head = newNodo;
            }else{
                NodoAmistad* temp = head;
                while (temp->siguiente != nullptr)
                {
                    temp = temp->siguiente;
                }
                temp->siguiente = newNodo;
            }
        };

        Amistad extraer(){
            if (this->estaVacia()){
                cout << "La lista esta vacia" << endl;
                return Amistad(nullptr, nullptr);
            }else{
                NodoAmistad* temp = head;
                head = head->siguiente;
                Amistad dato = temp->dato;
                delete temp;
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
            while (temp != nullptr && temp->dato.getReceptor()->getEmail() != email)
            {
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
            while (temp != nullptr && temp->dato.getReceptor()->getEmail() != email)
            {
                temp2 = temp;
                temp = temp->siguiente;
            }
            if (temp == nullptr){
                cout << "No se encontro la solicitud" << endl;
            }else{
                if (temp2 == nullptr){
                    head = temp->siguiente;
                    delete temp;
                }else{
                    temp2->siguiente = temp->siguiente;
                    delete temp;
                }
            }
        };
    void reporte(){
        ofstream archDot("Lista_espera.dot");
        archDot << "digraph Espera{"<< endl;
        archDot << "node[shape = \"box\"];"<< endl;

        NodoAmistad* actual = head;
        while(actual) {
            string nodo;
            string agregarParametros;
            if (actual == head) {
                nodo = "\"Nodo" + to_string(actual->dato.getReceptor()->getId()) + "\"";
                agregarParametros = nodo + "[label = \"" + actual->dato.getReceptor()->getNombre() +"\"];";
            }else {
                nodo = "\"Nodo" + to_string(actual->dato.getReceptor()->getId()) + "\"";
                archDot << nodo << endl;
                agregarParametros = nodo + "[label = \"" + actual->dato.getReceptor()->getNombre() +"\"];";
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

        int result = system("dot -Tpng ./Lista_espera.dot -o ./Lista_espera.png");
        if (result != 0) {
            cout << "Ocurrió un error al momento de crear la imagen" << endl;
        } else {
            cout << "La imagen fue generada exitosamente" << endl;
        }

    }

};
