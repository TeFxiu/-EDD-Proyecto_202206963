#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include <sstream>
#include <ctime>
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 2/Estructuras/ArbolB.h"

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
        ArbolB* comentario = new ArbolB();
        string resumen;
        string cripto;
        inline Publicacion():usuario(""), texto(""), fecha_hora(0){};
        inline Publicacion(string _usuario, string _texto ,time_t _fecha):usuario(_usuario),texto(_texto), fecha_hora(_fecha){superId++;}

        inline string getImage(){return imagen;};
        inline void setImage(string ruta){imagen = ruta;};

        inline string getUsuario(){return usuario;};
        inline void setUsuario(string _usuario){usuario = _usuario;};

        inline string getTexto(){return texto;};
        inline void setTexto(string _texto){texto = _texto;};

        time_t getFecha();
        inline void setFecha(time_t _fecha){fecha_hora = _fecha;};

        inline time_t getHora(){return fecha_hora;};
        inline void setHora(time_t _hora){fecha_hora = _hora;};

        inline int getNumComentario(){return numComentarios;};
        inline void setComentario(){numComentarios++;};

        inline void agregarComentario(Comentarios* dato){
            comentario->insertar(dato);
        }


        inline ~Publicacion(){};

};

inline int Publicacion::superId = 0;

inline time_t Publicacion::getFecha(){
    tm* fecha = localtime(&fecha_hora);
    fecha->tm_sec = 0;
    fecha->tm_hour = 0;
    fecha->tm_min = 0;
    time_t retorno = mktime(fecha);
    return retorno;
}

#endif
