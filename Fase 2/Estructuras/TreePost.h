//
// Created by TeFxiu on 9/11/2024.
//

#ifndef PROYECTO1_TREEPOST_H
#define PROYECTO1_TREEPOST_H

#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ListaPosts.h"

using namespace std;

class TreePost{

public:
    ListaPosts* lista;
    TreePost *drcha, *izq;
    TreePost(Publicacion* dato);

    PostSimple* getlista();
    void setlista(ListaPosts* lista);

    time_t fecha();

    TreePost* getDrcha();
    void setDrcha(TreePost *drcha);

    TreePost* getIzq();
    void setIzq(TreePost *Izq);

    TreePost*& refDrcha();
    TreePost*& refIzq();
};


#endif //PROYECTO1_TREEPOST_H
