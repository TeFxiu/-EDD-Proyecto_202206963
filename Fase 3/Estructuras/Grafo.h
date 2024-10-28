//
// Created by TeFxiu on 10/10/2024.
//

#ifndef PROYECTO1_GRAFO_H
#define PROYECTO1_GRAFO_H
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Estructuras/ListaUsuarios.h"
#include "SuperVertice.h"

class Grafo {
public:
    SuperVertice* primero = nullptr;
    SuperVertice* ultimo = nullptr;

    Grafo();
    ~Grafo();

    void insertar(Usuario* emisor, Usuario* receptor);
    void buscarRecomendaciones(SuperVertice* amigos, ListaUsuarios* usuarios);

    SuperVertice* amistedesEmisor(Usuario* emisor);

    bool buscarAmistad(Usuario* emisor, Usuario* receptor);

    void generarSugerencias(Grafo* general, SuperVertice* amigos);
    void generarGrafo();
    void listaAdyacencia();
};


#endif //PROYECTO1_GRAFO_H
