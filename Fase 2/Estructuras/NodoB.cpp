//
// Created by TeFxiu on 9/29/2024.
//

#include "NodoB.h"

NodoB::NodoB() {
    for (int i =0; i < 5; i++){
        hijos[i] = nullptr;
        datos[i] = nullptr;
    }
}
