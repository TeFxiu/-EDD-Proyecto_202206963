#include <string>
#include "./headers/Usuario.h"
#include "./Estructuras/Pila.cpp"
#include "./Estructuras/SimpleAmistad.cpp"

using namespace std;

Usuario::Usuario() {
    this->nombre = "";
    this->email = "";
    this->apellido = "";
    this->fechaNacimiento = "";
    this->password = "";
    this->recepcion = new Pila();
    this->solicitudes = new SimpleAmistad();
}

Usuario::Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass) {
    this->nombre = nome;
    this->email = email;
    this->apellido = apellido;
    this->fechaNacimiento = fechaNacimiento;
    this->password = pass;
    this->recepcion = new Pila();
    this->solicitudes = new SimpleAmistad();
}

void Usuario::addSolicitud(Usuario* user) {
    Amistad nueva(user, this);
    this->recepcion->push(nueva);
    user->solicitudes->append(nueva);
}

bool Usuario::findSolicitud(string email) {
    return this->solicitudes->findEmail(email) || this->recepcion->findEmail(email);
}

void Usuario::rechazarSolicitud(){
    Usuario* user = this->recepcion->pop();
    user->solicitudes->solicitudRechazada(this->email);
    cout << "Solicitud de amistad rechazada" << endl;
}

void Usuario::decidirSolicitudes(bool& decision){
    int eleccion;
    if(!this->recepcion->estaVacia()){
        cout << "Acepta o rechaza la solicitud de amistad" << endl;
    }else{
        cout << "No tienes solicitudes de amistad\n" << endl;
        decision = false;
        return;
    }

    cout << "\U0001F600";
    recepcion->mostrarTop();
    cout << " te ha enviado una solicitud de amistad" << endl;

    cout << "1. Aceptar" << endl;
    cout << "2. Rechazar" << endl;
    cout << "3. Salir" << endl;
    cout<< "Elegir una opcion"<<endl;
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:

        cout << "Solicitud aceptada" << endl;
        break;
    case 2:
        rechazarSolicitud();
        break;
    case 3:
        decision = false;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }



}

void Usuario::decidirSolicitudes(){
    bool decision = true;
    do{
        decidirSolicitudes(decision);
    }while(decision);
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
