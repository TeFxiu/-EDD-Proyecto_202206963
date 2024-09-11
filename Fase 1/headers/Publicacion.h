#ifndef PUBLICACION_H
#define PUBLICACION_H
#include <iostream>
#include <string>

using namespace std;

class Publicacion{
    private:
        static int superId;
        int numComentarios;
        string usuario;
        string texto;
        string imagen;
        time_t fecha_hora;
    public:
        Publicacion():usuario(""), texto(""), fecha_hora(0){};
        Publicacion(string _usuario, string _texto ,time_t _fecha):usuario(_usuario),texto(_texto), fecha_hora(_fecha){superId++;}

        string getUsuario(){return usuario;};
        void setUsuario(string _usuario){usuario = _usuario;};

        string getTexto(){return texto;};
        void setTexto(string _texto){texto = _texto;};

        time_t getFecha(){return fecha_hora;};
        void setFecha(time_t _fecha){fecha_hora = _fecha;};

        time_t getHora(){return fecha_hora;};
        void setHora(time_t _hora){fecha_hora = _hora;};

        int getNumComentario(){return numComentarios;};
        void setComentario(){numComentarios++;};

        ~Publicacion(){};

};
#endif