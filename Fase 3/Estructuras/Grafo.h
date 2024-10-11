//
// Created by TeFxiu on 10/10/2024.
//

#ifndef PROYECTO1_GRAFO_H
#define PROYECTO1_GRAFO_H
#include "SuperVertice.h"

class Grafo {
public:
    SuperVertice* primero = nullptr;
    SuperVertice* ultimo = nullptr;

    Grafo();
    ~Grafo();

    void insertar(Usuario* emisor, Usuario* receptor);

    SuperVertice* amistedesEmisor(Usuario* emisor);

    bool buscarAmistad(Usuario* emisor, Usuario* receptor);

};


#endif //PROYECTO1_GRAFO_H
