#include "ListaUsuarios.h"
#include "C:\Users\TeFxiu\Documents\EDD\[EDD]Proyecto_202206963\Fase 3\Estructuras\Grafo.h"
#include <QTableWidget>
#include <QPushButton>
#include <QStackedWidget>

using namespace std;

class MainWindow;

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
        void inOrden(QStackedWidget*& ventana,QTableWidget* tabla,TreeUsuario* raiz);
        void preOrdenTabla(TreeUsuario* raiz, ListaUsuarios* lista, Usuario* perfil, Grafo* amistades, SuperVertice* relEmisor);
        void preOrden(QStackedWidget*& ventana,QTableWidget* tabla,TreeUsuario* raiz);
        void postOrden(QStackedWidget*& ventana,QTableWidget* tabla, TreeUsuario* raiz);
};
