#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Pila;
class SimpleAmistad;
class Matriz;
class DoublyCircular;
class DoublyLinkedList;

class Usuario {
    private:
        static int idCounter;
        int id;
        string nombre;
        string apellido;
        string fechaNacimiento;
        string email;
        string password;
        Matriz* relacionesGlobal;
        Pila* recepcion;
        SimpleAmistad* solicitudes;
        void decidirSolicitudes(bool& decision);
    public:
        Usuario();
        Usuario(string nombre, int id);
        Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass);
        DoublyCircular* publicacionesAmigos;
        int numRelaciones;
        int numPublicaciones;
        void addSolicitud(Usuario* user);
        void rechazarSolicitud();
        void addStoriesAmigos(DoublyLinkedList* entrada);
        void aceptarSolicitud();
        void decidirSolicitudes(Matriz* relaciones);
        bool findSolicitud(string email);
        int getId();
        void setId(int id);
        string getNombre();
        string getApellido();
        string getFechaNac();
        string getEmail();
        string getPass();
        DoublyLinkedList* publicacionesPersonales;
        void setNombre(string nome);
        void setApellido(string apellido);
        void setFechaNac(string fecha);
        void setEmail(string email);
        void setPass(string pass);
};
#endif