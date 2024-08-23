#include <string>
#include "./headers/Usuario.h"
#include "./Estructuras/Pila.cpp"
#include "./Estructuras/SimpleAmistad.cpp"
#include "./Estructuras/Matriz.h"
#include "./Estructuras/CircularDoble.cpp"
#include "./Estructuras/EnlazadaDoble.cpp"

using namespace std;

int Usuario::idCounter = 0;

Usuario::Usuario(Matriz* general) {
    this->id = idCounter++;
    this->nombre = "";
    this->email = "";
    this->apellido = "";
    this->fechaNacimiento = "";
    this->password = "";
    this->recepcion = new Pila();
    this->solicitudes = new SimpleAmistad();
    this->publicacionesAmigos = new DoublyCircular();
    this->relacionesGlobal = general;
    this->publicacionesPersonales = new DoublyLinkedList(this->email);
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
    this->publicacionesAmigos->append(this->publicacionesPersonales);
}

Usuario::Usuario(string nome, int id) {
    this->id = id;
    this->nombre =nome;
    this->email = "";
    this->apellido = "";
    this->fechaNacimiento = "";
    this->password = "";
    this->recepcion = nullptr;
    this->solicitudes = nullptr;
    this->publicacionesAmigos = nullptr;
    this->relacionesGlobal = nullptr;
    this->publicacionesPersonales = nullptr;
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
}

Usuario::Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass, Matriz* general) {
    this->nombre = nome;
    this->email = email;
    this->apellido = apellido;
    this->fechaNacimiento = fechaNacimiento;
    this->password = pass;
    this->recepcion = new Pila();
    this->solicitudes = new SimpleAmistad();
    this->publicacionesAmigos = new DoublyCircular();
    this->publicacionesPersonales = new DoublyLinkedList(this->email);
    this->relacionesGlobal = general;
    this->numRelaciones = 0;
    this->numPublicaciones = 0;
    this->id = idCounter++;
    publicacionesAmigos->append(publicacionesPersonales);
}

void Usuario::addSolicitud(Usuario* user) {
    Amistad nueva(user, this);
    this->recepcion->push(nueva);
    user->solicitudes->append(nueva);
}

void Usuario::restarRelaciones(){
    numRelaciones--;
}

bool Usuario::findSolicitud(string email) {
    return this->solicitudes->findEmail(email) || this->recepcion->findEmail(email);
}

void Usuario::rechazarSolicitud(){
    Usuario* user = this->recepcion->pop();
    user->solicitudes->solicitudRechazada(this->email);
    cout << "Solicitud de amistad rechazada" << endl;
}

void Usuario::aceptarSolicitud(){
        Usuario* user = this->recepcion->pop();
        user->solicitudes->solicitudRechazada(this->email);
        this->relacionesGlobal->insertarAmistad(this, user);
        this->numRelaciones++;
        user->setNumRelaciones();
        this->publicacionesAmigos->append(user->publicacionesPersonales);
        user->publicacionesAmigos->append(this->publicacionesPersonales);
        cout << "Solicitud de amistad aceptada" << endl;
}

void Usuario::eliminarSolicitud(string email){
    this->recepcion->eliminarCola(email);
}

void Usuario::eliminarSolicitudes(){
    while(!this->recepcion->estaVacia()){
        Usuario* user = this->recepcion->pop();
        user->solicitudes->solicitudRechazada(this->email);
    }

    Amistad temp = this->solicitudes->extraer();
    while(temp.getReceptor() != nullptr){
        temp.getReceptor()->eliminarSolicitud(this->email);
        temp = this->solicitudes->extraer();
    }
}



void Usuario::addStoriesAmigos(DoublyLinkedList* entrada){
    this->publicacionesAmigos->append(entrada);
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

    cout << "\U0001F600 ";
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
        aceptarSolicitud();
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

int Usuario::getId() {
    return this->id;
}

void Usuario::setId(int id) {
    this->id = id;
}

void Usuario::setRelacionesGlobal(Matriz* relaciones) {
    this->relacionesGlobal = relaciones;
}

void Usuario::setRecepcion(Pila* recepcion) {
    this->recepcion = recepcion;
}

void Usuario::setSolicitudes(SimpleAmistad* solicitudes) {
    this->solicitudes = solicitudes;
}

void Usuario::setPublicacionesAmigos(DoublyCircular* publicacionesAmigos) {
    this->publicacionesAmigos = publicacionesAmigos;
}

void Usuario::setPublicacionesPersonales(DoublyLinkedList* publicacionesPersonales) {
    this->publicacionesPersonales = publicacionesPersonales;
}

void Usuario::setNumRelaciones() {
    this->numRelaciones = 1+ numRelaciones;
}

void Usuario::setNumPublicaciones() {
    this->numPublicaciones = 1+numPublicaciones;
}

Matriz* Usuario::getRelacionesGlobal() {
    return this->relacionesGlobal;
}

Pila* Usuario::getRecepcion() {
    return this->recepcion;
}

SimpleAmistad* Usuario::getSolicitudes() {
    return this->solicitudes;
}

DoublyCircular* Usuario::getPublicacionesAmigos() {
    return this->publicacionesAmigos;
}

DoublyLinkedList* Usuario::getPublicacionesPersonales() {
    return this->publicacionesPersonales;
}

int Usuario::getNumRelaciones() {
    return this->numRelaciones;
}

int Usuario::getNumPublicaciones() {
    return this->numPublicaciones;
}

Usuario::~Usuario() {
    delete this->recepcion;
    delete this->solicitudes;
    delete this->publicacionesAmigos;
    delete this->publicacionesPersonales;
}