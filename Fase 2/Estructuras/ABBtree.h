//
// Created by TeFxiu on 9/11/2024.
//

#ifndef PROYECTO1_ABBTREE_H
#define PROYECTO1_ABBTREE_H
#include "TreePost.h"


using namespace std;

class ABBtree{
private:
    void insertar(Publicacion* data, TreePost*& root);

    PostSimple* buscarPublicacionesI(time_t fecha, TreePost* actual);

    ListaPosts* buscarPublicaciones(time_t fecha, TreePost* actual);

    void conectar(ABBtree* copia, TreePost* raiz);
    void conectar(ABBtree* copia, TreePost* raiz, time_t fecha);

public:
    ABBtree();
    TreePost* root;
    bool estaVacio();
    PostSimple* buscarPublicacionesI(time_t fecha);
    ListaPosts* buscarPublicaciones(time_t fecha);


    void insertar(Publicacion* data);
    void conectar(ABBtree* copia);
    void conectar(ABBtree* copia, time_t fecha);

    void inOrden(TreePost* raiz);
    void preOrden(TreePost* raiz);
};


#endif //PROYECTO1_ABBTREE_H
