#include <fstream>
#include "../tinyfiledialogs/tinyfiledialogs.h"
#include "../nlohmann/json.hpp"
#include <iostream>
#include <string>
#include "../tinyfiledialogs/tinyfiledialogs.h"
#include "../nlohmann/json.hpp"
#include "Usuario.h"
#include "../Estructuras/Matriz.h"


using namespace nlohmann;
using namespace std;

class ModuloAdmin{
private:
    Usuario *user;
    bool inter;
    DoublyLinkedList* listaPublicaciones;
    ListaSimple* listaUsuarios;
    Matriz* matrizRelaciones;
public:
    ModuloAdmin(Usuario& entrada, DoublyLinkedList* listaEntrada, ListaSimple* usuarios, Matriz* relaciones);
    void encabezadoInterfaz();
    void bucleInterfaz();
    char* buscarDireccion();
    void reportes();
    void cargaUsuarios();
    void cargaRelaciones();
    void cargarPublicaciones();
    void eliminarUsuario();
    Usuario* buscarUsuario();


};