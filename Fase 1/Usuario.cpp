#include <string>
#include "headers/Usuario.h"

using namespace std;


Usuario::Usuario() {
    this->nombre = "";
    this->email = "";
    this->apellido = "";
    this->fechaNacimiento = "";
    this->password = "";
}

Usuario::Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass) {
    this->nombre = nome;
    this->email = email;
    this->apellido = apellido;
    this->fechaNacimiento = fechaNacimiento;
    this->password = pass;
}

string Usuario::getNombre() {
    return this->nombre;
}

string Usuario::getApellido() {
    return this->apellido;
}

string Usuario::getFechaNac() {
    return this->fechaNacimiento;
}

string Usuario::getEmail() {
    return this->email;
}

string Usuario::getPass() {
    return this->password;
}

void Usuario::setNombre(string nome) {
    this->nombre = nome;
}

void Usuario::setApellido(string nome) {
    this->apellido = nome;
}

void Usuario::setFechaNac(string nome) {
    this->fechaNacimiento = nome;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

void Usuario::setPass(string senha) {
    this->password = senha;
}
