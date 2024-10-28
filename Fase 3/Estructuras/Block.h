//
// Created by TeFxiu on 10/18/2024.
//
#ifndef PROYECTO1_BLOCK_H
#define PROYECTO1_BLOCK_H
#include <windows.h>
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/EnlazadaDoble.cpp"

#include <sstream>
#include <iomanip>
using namespace std;

class Block {
private:
    static int index;
    time_t timestamp;
    string merkle;
    string nonce;
    string hashNow;
    string previousHash;

public:
    Block(string merkle, string anterior);
    Block* siguiente;
};


#endif //PROYECTO1_BLOCK_H
