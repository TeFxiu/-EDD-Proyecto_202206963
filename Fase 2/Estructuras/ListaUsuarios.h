//
// Created by TeFxiu on 9/26/2024.
//

#ifndef PROYECTO1_LISTAUSUARIOS_H
#define PROYECTO1_LISTAUSUARIOS_H
#include "TreeUsuario.h"
#include <string>

class ListaUsuarios {

    private:
        TreeUsuario *head;
        bool bandera = true;
        TreeUsuario* retorno;
    public:
        ListaUsuarios();

        bool estaVacia();
        TreeUsuario* buscar(Usuario* buscado);
        int contador = 0;

        void append(Usuario* dato);

        void push(Usuario* dato);
        void reset();

        void ordenar();

        void agregarPerfiles(ListaUsuarios* lista, Usuario* perfil);
        Usuario* recorreraUno();
        bool buscarB(Usuario* buscando);
};


#endif //PROYECTO1_LISTAUSUARIOS_H
