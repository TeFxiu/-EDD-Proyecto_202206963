#include "TreeUsuario.h"

using namespace std;

class AVLtree{
    private:
        int obtenerAltura(TreeUsuario* root);
        int max(int a, int b);
        int obtenerBalance(TreeUsuario* root);

        void insertar(Usuario* data, TreeUsuario*& root);
        void rotacionDerecha(TreeUsuario* &root);
        void rotacionIzq(TreeUsuario* &root);

        Usuario* buscarUsuario(string email, TreeUsuario* actual);
    public: 
        AVLtree();
        TreeUsuario* root;

        bool estaVacio();

        Usuario* buscarUsuario(string mail);
        void insertar(Usuario* data);
        void inOrden(TreeUsuario* raiz);
        void preOrden(TreeUsuario* raiz);
};