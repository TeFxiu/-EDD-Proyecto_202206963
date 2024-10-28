//
// Created by TeFxiu on 10/21/2024.
//

#include "Merkle.h"

Merkle::Merkle(){
    root = nullptr;
}

Nodo* Merkle::combineNodes(Nodo* left, Nodo* rigth){
    string combinados = left->hashN + rigth->hashN;
    string combineHash = combinados.data();
    Nodo* parent = new Nodo(combineHash);
    parent->izq = left;
    parent->der = rigth;
    return parent;
}

Nodo* Merkle::buildMerkleTree(Nodo** leaves, int start, int end){
    if (start == end) {
        return leaves[start];
    }

    // Encuentra el punto medio para dividir la lista de hojas
    int mid = (start + end) / 2;

    // Construir el subárbol izquierdo y derecho de manera recursiva
    Nodo* leftSubTree = buildMerkleTree(leaves, start, mid);
    Nodo* rightSubTree = buildMerkleTree(leaves, mid + 1, end);

    // Combinar los dos subárboles en un nodo padre
    return combineNodes(leftSubTree, rightSubTree);
}
