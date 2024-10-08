//
// Created by TeFxiu on 9/29/2024.
//

#include "Comentarios.h"

Comentarios::Comentarios(std::string correo, std::string contenido, time_t fecha_hora) {
    this->correo = correo;
    this->contenido = contenido;
    this->fecha_hora = fecha_hora;
}

string Comentarios::getCorreo() {
    return correo;
}

string Comentarios::getContenido() {
    return contenido;
}

time_t Comentarios::getFecha_hora() {
    return fecha_hora;
}