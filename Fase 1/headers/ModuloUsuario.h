#include <string>
#include <iostream>
#include "Usuario.h"
#include "../Listas/EnlazadaDoble.cpp"

using namespace std;

class ModuloUsuario{
    private:
        Usuario *user;
        bool inter;
        DoublyLinkedList* listaPublicaciones;
    public:
        ModuloUsuario(Usuario& entrada, DoublyLinkedList* listaEntrada){user = &entrada; inter = false; listaPublicaciones = listaEntrada;};
        void encabezadoInterfaz();
        void menu();
        void bucleInterfaz();
        void crearPublicacion();    

};