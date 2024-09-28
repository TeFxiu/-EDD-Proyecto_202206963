#include "./headers/UsuarioA.h"

UsuarioA::UsuarioA(string _nombre, int id) {
    this->id = id;
    this->email = _nombre;
}

void UsuarioA::setEmail(string email) {
    this->email = email;
}
string UsuarioA::getEmail() {
    return this->email;
}

int UsuarioA::getId(){
    return this->id;
}
void UsuarioA::setId(int id){
    this->id = id;
};
UsuarioA::~UsuarioA(){
}
