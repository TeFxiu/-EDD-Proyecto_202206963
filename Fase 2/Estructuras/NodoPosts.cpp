//
// Created by TeFxiu on 9/27/2024.
//

#include "NodoPosts.h"
NodoPosts::NodoPosts(Publicacion *post) {
    dato = new PostSimple();
    dato->push(post);
    siguiente = nullptr;
}

NodoPosts::NodoPosts(PostSimple* dato) {
    this->dato = dato;
    siguiente = nullptr;
}