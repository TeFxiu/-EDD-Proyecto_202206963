#ifndef MATRIZ_H
#define MATRIZ_H
#include "../headers/NodoUser.h"
#include <iostream>
#include <string>
class Matriz{
    private:
        NodoUser* raiz;
        void buscarColumna(Usuario* entrada, NodoUser*& auxColumna);
        void buscarFila(Usuario* entrada, NodoUser*& auxFila, NodoUser*& auxColumna);
        NodoUser* buscarRelacionFila(NodoUser* fila, NodoUser* columna);
        NodoUser* buscarRelacionColumna(NodoUser* columna, NodoUser* fila);       
        void insertarInicio(NodoUser* raiz, NodoUser* primeroFila, NodoUser* segundoFila, NodoUser* primeroColumna, NodoUser* segundoColumna);
        void conectarFila(NodoUser* pivote, NodoUser* nuevo);
        void conectarColumna(NodoUser* pivote, NodoUser* nuevo);
        void buscarColumnaTemp(Usuario* entrada, NodoUser*& auxColumna);
        void buscarFilaTemp(Usuario* entrada, NodoUser*& auxFila, NodoUser*& auxColumna);
    public:
        Matriz();
        void insertarAmistad(Usuario* entrada, Usuario* amigo);
        bool insertarAmistad(Usuario* entrada, Usuario* amigo, bool bandera);
        void eliminarAmistad(Usuario* entrada);
        bool estaVacio();
};
#endif