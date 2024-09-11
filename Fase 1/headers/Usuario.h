#ifndef USUARIO_H
#define USUARIO_H
#include <ctime>
#include <iomanip>
#include <string>
#include <windows.h>
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Estructuras/ABBtree.h"

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
        int numRelaciones;
        int numPublicaciones;
        string nombre;
        string apellido;
        string email;
        string password;

        time_t fechaNacimiento;
        ABBtree* feed;
    public:
        Usuario();
        Usuario(string nombre, int id);
        Usuario(string nome, string apellido, time_t fechaNacimiento, string email, string pass);

        int getId();
        void setId(int id);

        string getNombre();
        void setNombre(string nome);

        string getApellido();
        void setApellido(string apellido);

        time_t getFechaNac();
        void setFechaNac(time_t fecha);

        string getEmail();
        void setEmail(string email);

        string getPass();
        void setPass(string pass);

        int getNumRelaciones();
        void setNumRelaciones();

        void setNumPublicaciones();
        int getNumPublicaciones();

        ABBtree* getFeed();
        void setFeed(ABBtree* newFeed);

        ~Usuario();
};
#endif