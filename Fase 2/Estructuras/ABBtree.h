//
// Created by TeFxiu on 9/11/2024.
//

#ifndef PROYECTO1_ABBTREE_H
#define PROYECTO1_ABBTREE_H
#include "TreePost.h"

using namespace std;

class ABBtree{
private:
    void insertar(Publicacion* data, TreePost* root);

    Publicacion* buscarPublicacion(string email, TreePost* actual);
public:
    ABBtree();
    TreePost* root;

    bool estaVacio();

    Publicacion* buscarPublicacion(string mail);

    void insertar(Publicacion* data);
    void inOrden(TreePost* raiz);
    void preOrden(TreePost* raiz);
};


#endif //PROYECTO1_ABBTREE_H
