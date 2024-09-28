//
// Created by TeFxiu on 9/27/

#ifndef PROYECTO1_LISTAPOSTS_H
#define PROYECTO1_LISTAPOSTS_H
#include "NodoPosts.h"


class ListaPosts {
public:
    NodoPosts* head;
    NodoPosts* retorno;
    NodoPosts* existente;
    bool vuelta = true;

    ListaPosts(Publicacion* dato);
    ListaPosts();

    bool estaVacia();

    void insertar(PostSimple* dato);
    Publicacion* recorreraUno();
    string nombreHead();
    void nuevo();
    bool cambio = false;
    void activar();
    
};


#endif //PROYECTO1_LISTAPOSTS_H
