//
// Created by TeFxiu on 10/18/2024.
//

#include "Block.h"

int Block::index = 0;

Block::Block(string merkle, string anterior){
    index++;
    string indexS = to_string(index);

    timestamp = time(nullptr);
    tm* fechaNac = localtime(&timestamp);
    stringstream formatString;
    formatString << put_time(fechaNac, "%d/%m/%Y %H:%M:%S");

    nonce = "0000" + to_string(index);
    previousHash = anterior;
    this->merkle = merkle;

    string combinar = indexS + formatString.str() + nonce + merkle + previousHash;
    hashNow = combinar.data();

    siguiente = nullptr;
}
