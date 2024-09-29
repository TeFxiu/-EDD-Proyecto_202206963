#ifndef MATRIZ_H
#define MATRIZ_H

#include  "../headers/NodoUser.h"
#include <iostream>
#include <string>

using namespace std;
class Matriz{
private:
    NodoUser* raiz;
    void buscarColumna(UsuarioA* entrada, NodoUser*& auxColumna);
    void buscarFila(UsuarioA* entrada, NodoUser*& auxFila, NodoUser*& auxColumna);
    NodoUser* buscarRelacionFila(NodoUser* fila, NodoUser* columna);
    NodoUser* buscarRelacionColumna(NodoUser* columna, NodoUser* fila);
    void insertarInicio(NodoUser* raiz, NodoUser* primeroFila, NodoUser* segundoFila, NodoUser* primeroColumna, NodoUser* segundoColumna);
    void conectarFila(NodoUser* pivote, NodoUser* nuevo);
    void conectarColumna(NodoUser* pivote, NodoUser* nuevo);
    void buscarColumnaTemp(UsuarioA* entrada, NodoUser*& auxColumna);
    void buscarFilaTemp(UsuarioA* entrada, NodoUser*& auxFila, NodoUser*& auxColumna);
public:
    Matriz();
    void insertarAmistad(UsuarioA* entrada, UsuarioA* amigo);
    bool insertarAmistad(UsuarioA* entrada, UsuarioA* amigo, bool bandera);
    void eliminarAmistad(UsuarioA* entrada);
    bool buscarAmistad(string amigo, string perfil);
    bool buscar(string amigo, string perfil);
    bool estaVacio();
};
#endif
