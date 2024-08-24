#include <string>
#include <iostream>
#include "Usuario.h"
#include "Publicacion.h"
#include "../Estructuras/Matriz.h"
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
    Matriz* matrizRelaciones;
public:
    ModuloUsuario(Usuario* entrada, DoublyLinkedList* listaEntrada, ListaSimple* usuarios, Matriz* relaciones);
    void encabezadoInterfaz();
    void menu();
    void bucleInterfaz();
    void crearPublicacion();
    void reportes();
    int menuPrincipal();
    void verPublicaciones();
    void eliminarMiCuenta(string email);
    void subModuloSolicitudes(int eleccion, bool bucle);
    void obtenerFechaHora(Publicacion* publicacion);
    void subModuloStories(int eleccion, bool bucle);
    void subModuloPerfil(int eleccion, bool bucle);

};