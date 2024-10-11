//
// Created by TeFxiu on 10/10/2024.
//

#ifndef PROYECTO1_SUPERVERTICE_H
#define PROYECTO1_SUPERVERTICE_H

#include "Vertice.h"

class SuperVertice {
public:
    Usuario* emisor = nullptr;
    Vertice* amigos = nullptr;
    SuperVertice* anterior = nullptr;
    SuperVertice* siguiente = nullptr;

    SuperVertice();
    SuperVertice(Usuario* _emisor);
    ~SuperVertice();

    void insertar(Usuario* receptor);

    bool buscarRelacion(Usuario* receptor);

};


#endif //PROYECTO1_SUPERVERTICE_H
