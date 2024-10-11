//
// Created by TeFxiu on 10/10/2024.
//

#ifndef PROYECTO1_VERTICE_H
#define PROYECTO1_VERTICE_H
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/headers/Usuario.h"

class Vertice {
public:
    Usuario* receptor = nullptr;
    Vertice* delante = nullptr;

    Vertice(Usuario* _receptor);
    ~Vertice();
};


#endif //PROYECTO1_VERTICE_H
