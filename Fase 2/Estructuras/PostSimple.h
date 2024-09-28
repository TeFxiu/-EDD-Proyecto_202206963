//
// Created by TeFxiu on 9/11/2024.
//

#ifndef PROYECTO1_POSTSIMPLE_H
#define PROYECTO1_POSTSIMPLE_H

#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/NodoStories.h"

class PostSimple {
    private:
        NodoStories* head;
        NodoStories* retorno;
        NodoStories* nuevo;
    public:
        PostSimple();
        bool estaVacia();
        bool vuelta = false;

        void setNuevo();
        void append(Publicacion* dato);
        void push(Publicacion* dato);

        time_t buscarFecha();

        Publicacion* recorrer();
};


#endif //PROYECTO1_POSTSIMPLE_H
