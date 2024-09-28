//
// Created by TeFxiu on 9/11/2024.
//

#ifndef PROYECTO1_TREEPOST_H
#define PROYECTO1_TREEPOST_H


#include <iostream>
#include <fstream>
#include <sstream>

#include "PostSimple.h"

using namespace std;

class TreePost{
private:
    PostSimple* lista;
    TreePost *drcha, *izq;
public:
    TreePost(Publicacion* dato);

    PostSimple* getlista();
    void setlista(PostSimple* lista);

    TreePost* getDrcha();
    void setDrcha(TreePost *drcha);

    TreePost* getIzq();
    void setIzq(TreePost *Izq);

    TreePost*& refDrcha();
    TreePost*& refIzq();
};


#endif //PROYECTO1_TREEPOST_H
