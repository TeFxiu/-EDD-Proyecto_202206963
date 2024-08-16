#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Pila;
class SimpleAmistad;

class Usuario {
    private:
        string nombre;
        string apellido;
        string fechaNacimiento;
        string email;
        string password;
        Pila* recepcion;
        SimpleAmistad* solicitudes;
        void decidirSolicitudes(bool& decision);
    public:
        Usuario();
        Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass);
        void addSolicitud(Usuario* user);
        void rechazarSolicitud();
        void decidirSolicitudes();
        bool findSolicitud(string email);
        string getNombre();
        string getApellido();
        string getFechaNac();
        string getEmail();
        string getPass();
        void setNombre(string nome);
        void setApellido(string apellido);
        void setFechaNac(string fecha);
        void setEmail(string email);
        void setPass(string pass);
};
#endif