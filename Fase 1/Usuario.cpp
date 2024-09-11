#include "./headers/Usuario.h"
#include "./Estructuras/Pila.cpp"
#include "./Estructuras/SimpleAmistad.cpp"
#include "./Estructuras/Matriz.h"
#include "./Estructuras/CircularDoble.cpp"
#include "./Estructuras/EnlazadaDoble.cpp"

using namespace std;

int Usuario::idCounter = 0;

Usuario::Usuario() {
    this->id = idCounter++;
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
    this->fechaNacimiento = -1;
    this->nombre = "";
    this->email = "";
    this->apellido = "";
    this->password = "";
}

Usuario::Usuario(string _nombre, int id) {
    this->fechaNacimiento = -1;
    this->id = id;
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
    this->nombre = _nombre;
    this->email = "";
    this->apellido = "";
    this->password = "";
}

Usuario::Usuario(string nombre, string apellido, time_t fechaNacimiento, string email, string pass) {
    this->nombre = nombre;
    this->email = email;
    this->apellido = apellido;
    this->password = pass;
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
    this->id = idCounter++;
    this->fechaNacimiento = fechaNacimiento;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getNombre() {
    return this->nombre;
}

void Usuario::setApellido(string apellido) {
    this->apellido = apellido;
}

string Usuario::getApellido() {
    return this->apellido;
}


void Usuario::setEmail(string email) {
    this->email = email;
}

string Usuario::getEmail() {
    return this->email;
}

void Usuario::setPass(string pass) {
    this->password = pass;
}

string Usuario::getPass() {
    return this->password;
}

void Usuario::setId(int id) {
    this->id = id;
}

int Usuario::getId() {
    return this->id;
}

void Usuario::setNumRelaciones() {
    this->numRelaciones = 1+ numRelaciones;
}

int Usuario::getNumRelaciones() {
    return this->numRelaciones;
}

void Usuario::setNumPublicaciones() {
    this->numPublicaciones = 1+numPublicaciones;
}

int Usuario::getNumPublicaciones() {
    return this->numPublicaciones;
}

void Usuario::setFechaNac(time_t fecha) {
    this->fechaNacimiento = fecha;
}

time_t Usuario::getFechaNac() {
    return this->fechaNacimiento;
}

Usuario::~Usuario(){}