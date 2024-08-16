#include "Usuario.h"

using namespace std;

class Amistad{
    private:
        Usuario* emisor;
        Usuario* receptor;
    public:
        Amistad(Usuario* entrada, Usuario* salida): emisor(entrada), receptor(salida){};
        Usuario* getEmisor() {return emisor;};
        Usuario* getReceptor() {return receptor;};
};