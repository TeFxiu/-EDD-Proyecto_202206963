//
// Created by TeFxiu on 10/28/2024.
//

#ifndef PROYECTO1_HUFFMAN_H
#define PROYECTO1_HUFFMAN_H

#include "NodoH.h"

class Huffman {
private:
    NodoH *raiz;
    std::string codigos[256];

    void insertarCaracter(NodoH*);
    void graficar(NodoH*, std::ofstream&);
    void eliminar(NodoH*);

public:
    Huffman();
    ~Huffman();

    void crearArbol(std::string);
    void crearCodigosHuffman(NodoH*, std::string);
    void graficar();
    void imprimirCodigos();

    std::string comprimir(std::string);
    std::string descomprimir(std::string);

    NodoH* getRaiz();
};
#endif //PROYECTO1_HUFFMAN_H
