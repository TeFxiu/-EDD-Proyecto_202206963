#include "Usuario.h"

using namespace std;


struct NodoUser
{
    Usuario dato;
    NodoUser* siguiente;
    NodoUser* anterior;
    NodoUser(Usuario entrada):dato(entrada), siguiente(nullptr), anterior(nullptr){};

};
