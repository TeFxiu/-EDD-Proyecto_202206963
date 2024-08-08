#include <string>
#include "Usuario.h"

using namespace std;


struct Nodo
{
    Usuario dato;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Usuario entrada):dato(entrada), siguiente(nullptr), anterior(nullptr){};

};
