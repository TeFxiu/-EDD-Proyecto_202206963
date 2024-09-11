#include <iostream>
#include <fstream>
#include <sstream>

#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Usuario.h"

using namespace std;

class TreeUsuario{
    private:
        Usuario* data;
        int altura;
        TreeUsuario *drcha, *izq;
    public:
        TreeUsuario(Usuario* data);
        Usuario* getData();
        TreeUsuario* getDrcha();
        TreeUsuario* getIzq();
        TreeUsuario*& refDrcha();
        TreeUsuario*& refIzq();
        int getAltura();
        void setData(Usuario* data);
        void setDrcha(TreeUsuario *drcha);
        void setIzq(TreeUsuario *Izq);
        void setAltura(int altura);
};