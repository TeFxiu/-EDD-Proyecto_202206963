#include "./headers/Usuario.h"
#include "./Estructuras/Pila.cpp"
#include "./Estructuras/SimpleAmistad.cpp"

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
    this->feed = new ABBtree();
    this->relaciones = new Matriz();
    this->solicitudes = new Pila();
    this->enviados = new SimpleAmistad();
    this->miFeed = new ListaABB();
    miFeed->insertar(feed);
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
    this->feed = nullptr;
    this->relaciones = nullptr;
    this->solicitudes = nullptr;
    this->enviados = nullptr;
    this->miFeed = nullptr;
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
    this->feed = new ABBtree();
    this->relaciones = new Matriz();
    this->solicitudes = new Pila();
    this->enviados = new SimpleAmistad();
    this->miFeed = new ListaABB();
    miFeed->insertar(feed);
}

void Usuario::addSolicitud(Usuario* actual){
    Amistad amistad(this, actual);
    actual->getPila()->push(amistad);
    this->getEnviados()->append(amistad);
}

void Usuario::rechazarSolicitud(Usuario* actual){
    this->getPila()->eliminarCola(actual->getEmail());
    actual->getEnviados()->solicitudRechazada(this->getEmail());
}

void Usuario::aceptarSolicitud(Usuario* actual){
    UsuarioA* receptor = new UsuarioA(this->getEmail(), this->getId());
    UsuarioA* emisor = new UsuarioA(actual->getEmail(), actual->getId());
    this->getMatriz()->insertarAmistad(receptor, emisor);
    actual->getMatriz()->insertarAmistad(receptor, emisor);
    miFeed->insertar(actual->getFeed());
    actual->miFeed->insertar(feed);

    feed->conectar(actual->feed);
    actual->feed->conectar(feed);
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
    tm* fecha = localtime(&fechaNacimiento);
    fecha->tm_sec = 0;
    fecha->tm_hour = 0;
    fecha->tm_min = 0;
    time_t retorno = mktime(fecha);
    return retorno;
}

ABBtree* Usuario::getFeed() {
    return this->feed;
}

void Usuario::setFeed(ABBtree* newFeed) {
    this->feed = newFeed;
}

Matriz* Usuario::getMatriz() {
    return this->relaciones;
}

void Usuario::setMatriz(Matriz* nuevo) {
    this->relaciones = nuevo;
}

Pila* Usuario::getPila() {
    return this->solicitudes;
}

void Usuario::setPila(Pila* pila) {
    this->solicitudes = pila;
}

SimpleAmistad* Usuario::getEnviados() {
    return this->enviados;
}

void Usuario::setEnviados(SimpleAmistad *enviado) {
    this->enviados = enviado;
}

Usuario::~Usuario(){
    delete feed;
}
