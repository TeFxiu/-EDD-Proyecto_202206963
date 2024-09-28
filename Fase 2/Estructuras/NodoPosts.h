//
// Created by TeFxiu on 9/27/2024.
//

#ifndef PROYECTO1_NODOPOSTS_H
#define PROYECTO1_NODOPOSTS_H

#include "PostSimple.h"

class NodoPosts {
    public:
    PostSimple* dato;
    NodoPosts* siguiente;
    NodoPosts(Publicacion* post);
    NodoPosts(PostSimple* dato);
};


#endif //PROYECTO1_NODOPOSTS_H
