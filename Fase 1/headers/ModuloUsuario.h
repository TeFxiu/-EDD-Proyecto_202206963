#include <string>
#include <iostream>
#include "Usuario.h"
#include "Publicacion.h"
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

class ModuloUsuario{
    private:
        Usuario *user;
        bool inter;
        DoublyLinkedList* listaPublicaciones;
        ListaSimple* listaUsuarios;
    public:
        ModuloUsuario(Usuario& entrada, DoublyLinkedList* listaEntrada, ListaSimple* usuarios);
        void encabezadoInterfaz();
        void menu();
        void bucleInterfaz();
        void crearPublicacion();
        int menuPrincipal();
        void subModuloSolicitudes(int eleccion, bool bucle);
        void obtenerFechaHora(Publicacion& publicacion);  
        void subModuloStories(int eleccion, bool bucle);
        void subModuloPerfil(int eleccion, bool bucle);

};