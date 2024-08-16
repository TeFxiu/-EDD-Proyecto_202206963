#include <iostream>
#include <string>
#ifndef PUBLICACION_H
#define PUBLICACION_H
using namespace std;

class Publicacion{
    private:
        string id;
        string texto;
        string fecha;
        string hora;
    public:
        Publicacion():id(""), texto(""), fecha(""), hora(""){};
        Publicacion(string _id, string _texto ,string _fecha, string _hora):id(_id),texto(_texto), fecha(_fecha), hora(_hora) {};
        string getId(){return id;};
        string getTexto(){return texto;};
        string getFecha(){return fecha;};
        string getHora(){return hora;};
        void setId(string _id){id = _id;};
        void setTexto(string _texto){texto = _texto;};
        void setFecha(string _fecha){fecha = _fecha;};
        void setHora(string _hora){hora = _hora;};
        ~Publicacion(){};

};
#endif