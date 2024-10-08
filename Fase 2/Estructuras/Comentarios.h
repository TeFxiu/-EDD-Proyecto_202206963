//
// Created by TeFxiu on 9/29/2024.
//
#include <string>

#ifndef PROYECTO1_COMENTARIOS_H
#define PROYECTO1_COMENTARIOS_H

using namespace std;

class Comentarios {
private:
    string correo;
    string contenido;
    time_t fecha_hora;

public:
    Comentarios(string correo, string contenido, time_t fecha_hora);
    string getCorreo();
    string getContenido();
    time_t getFecha_hora();
};


#endif //PROYECTO1_COMENTARIOS_H
