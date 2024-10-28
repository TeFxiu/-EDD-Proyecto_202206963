//
// Created by TeFxiu on 10/21/2024.
//

#include <string>
#ifndef PROYECTO1_NODO_H
#define PROYECTO1_NODO_H

using namespace std;

class Nodo {
public:
    string hashN;
    Nodo* izq;
    Nodo* der;

    Nodo(string hashN);
};


#endif //PROYECTO1_NODO_H
