#include <string>
#ifndef USUARIO_H
#define USUARIO_H
using namespace std;

class Usuario {
    private:
        string nombre;
        string apellido;
        string fechaNacimiento;
        string email;
        string password;
    public:
        Usuario();
        Usuario(string nome, string apellido, string fechaNacimiento, string email, string pass);
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