//
// Created by TeFxiu on 10/21/2024.
//
#include "Nodo.h"
#ifndef PROYECTO1_MERKLE_H
#define PROYECTO1_MERKLE_H


class Merkle {
public:
    Nodo* buildMerkleTree(Nodo** leaves, int start, int end);
    Nodo* combineNodes(Nodo* left, Nodo* rigth);
    Nodo* root;
    Merkle();
};


#endif //PROYECTO1_MERKLE_H
