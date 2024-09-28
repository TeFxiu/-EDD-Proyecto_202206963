#include <string>
#include "../headers/NodoAmistad.h"


using namespace std;

class Pila{
private:
    NodoAmistad* top;
    NodoAmistad* retorno;
    bool bandera = true;
public:
    int contador = 0;
    Pila(): top(nullptr), retorno(nullptr) {};
    bool estaVacia() {return top == nullptr;};

    void push(Amistad dato){
        NodoAmistad* newNodo = new NodoAmistad(dato);
        if (this->estaVacia()) {
            top = newNodo;
            contador++;
        }else{
            newNodo->siguiente = top;
            top = newNodo;
            contador++;
        }
    };

    bool findEmail(string email){
        NodoAmistad* temp = top;
        while(temp != nullptr){
            if(temp->dato.getEmisor()->getEmail() == email){
                break;
            }
            temp = temp->siguiente;
        }
        if (temp == nullptr)
        {
            return false;
        }else{
            return true;
        }

    }

    Usuario* pop(){
        if (this->estaVacia()){
            return nullptr;
        }else{
            NodoAmistad* temp = top;
            top = top->siguiente;
            Usuario* user = temp->dato.getEmisor();
            contador--;
            return user;
        }
    }

    Usuario* recorreraUno(){
        if (bandera){
            retorno = top;
            bandera = false;
        }
        if (retorno != nullptr){
            Usuario* ret = retorno->dato.getEmisor();
            retorno = retorno ->siguiente;
            return ret;
        }
        bandera = true;
        return nullptr;
    }


    void eliminarCola(string eliminando){
        NodoAmistad* temp = top;
        NodoAmistad* prev = nullptr;
        while (temp != nullptr ){
            if (temp->dato.getEmisor()->getEmail() == eliminando){
                break;
            }
            prev = temp;
            temp = temp->siguiente;

        }
        if (temp == nullptr){
            return;
        }
        if (prev == nullptr){
            top = top->siguiente;
            contador--;
            return;
        }
        prev->siguiente = temp->siguiente;
        contador--;
    }
};
