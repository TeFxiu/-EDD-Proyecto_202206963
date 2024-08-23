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
        DoublyCircular* publicacionesAmigos;
        DoublyLinkedList* publicacionesPersonales;
        int numRelaciones;
        int numPublicaciones;
        void decidirSolicitudes(bool& decision);
        void aceptarSolicitud();
        void rechazarSolicitud();
    public:
        Usuario(Matriz* general);
        Usuario(string nombre, int id);
        Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass, Matriz* general);
        void addSolicitud(Usuario* user);
        void eliminarSolicitudes();
        void eliminarSolicitud(string email);
        
        void restarRelaciones();
        void addStoriesAmigos(DoublyLinkedList* entrada);
        void decidirSolicitudes();
        bool findSolicitud(string email);
        int getId();
        void setId(int id);
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
        void setRelacionesGlobal(Matriz* relaciones);
        void setRecepcion(Pila* recepcion);
        void setSolicitudes(SimpleAmistad* solicitudes);
        void setPublicacionesAmigos(DoublyCircular* publicacionesAmigos);
        void setPublicacionesPersonales(DoublyLinkedList* publicacionesPersonales);
        void setNumRelaciones();
        void setNumPublicaciones();
        Matriz* getRelacionesGlobal();
        Pila* getRecepcion();
        SimpleAmistad* getSolicitudes();
        DoublyCircular* getPublicacionesAmigos();
        DoublyLinkedList* getPublicacionesPersonales();
        int getNumRelaciones();
        int getNumPublicaciones();
        ~Usuario();
};
#endif