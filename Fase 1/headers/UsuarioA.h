#ifndef USUARIOA_H
#define USUARIOA_H
#include <string>
#include <windows.h>

using namespace std;

class UsuarioA{
    private:
        int id;
        string email;

    public:
        UsuarioA(string nombre, int id);

        int getId();
        void setId(int id);

        string getEmail();
        void setEmail(string email);

        ~UsuarioA();
};
#endif
