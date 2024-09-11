#include "AVLtree.h"

AVLtree::AVLtree(){
    root = nullptr;
}

bool AVLtree::estaVacio(){
    return root == nullptr;
}

Usuario* AVLtree::buscarUsuario(string email, TreeUsuario* actual) {
    if (actual == nullptr){
        return nullptr;
    }

    if(actual->getData()->getEmail() == email){
        return actual->getData();
    } else if (actual->getData()->getEmail() < email){
        return buscarUsuario(email, actual->getDrcha());
    } else if (actual->getData()->getEmail() > email){
        return buscarUsuario(email, actual->getIzq());
    }
}

Usuario* AVLtree::buscarUsuario(string mail){
    return buscarUsuario(mail, root);
}

void AVLtree::insertar(Usuario* data){
    insertar(data,root);
}

void AVLtree::insertar(Usuario* data, TreeUsuario*& root){
    if (root == nullptr){
        root = new TreeUsuario(data);
    }else if (data->getEmail() < root->getData()->getEmail()){
        insertar(data, root->refIzq());
    }else if(data->getEmail() > root->getData()->getEmail()){
        insertar(data, root->refDrcha());
    }

    root->setAltura(1 + max(obtenerAltura(root->getIzq()), obtenerAltura(root->getDrcha())));

    if(obtenerBalance(root) > 1){
        if(obtenerBalance(root->getDrcha()) < 0){
            rotacionDerecha(root->refDrcha());
            rotacionIzq(root);
        }else{
            rotacionIzq(root);
        }        

    }

    if(obtenerBalance(root) < -1){
        if(obtenerBalance(root->getIzq()) > 0){
            rotacionIzq(root->refIzq());
            rotacionDerecha(root);
        }else{
            rotacionDerecha(root);
        }
    }
}

int AVLtree::obtenerAltura(TreeUsuario* root){
    if (root == nullptr){
        return 0;
    }else{
        return root->getAltura();
    }

}

int AVLtree::max(int a, int b){
    return (a > b) ? a : b;
}

int AVLtree::obtenerBalance(TreeUsuario* root){
    if (root == nullptr){
        return 0;
    }else{
        return obtenerAltura(root->getDrcha()) - obtenerAltura(root->getIzq());
    }
}

void AVLtree::rotacionDerecha(TreeUsuario* &root){
    TreeUsuario* aux = root->refIzq();
    TreeUsuario* iniciado = root;

    root = aux;
    iniciado->setIzq(aux->getDrcha());
    aux->setDrcha(iniciado);
    root->setAltura(1 + max(obtenerAltura(root->getIzq()), obtenerAltura(root->getDrcha())));
    aux->setAltura(1 + max(obtenerAltura(aux->getIzq()), obtenerAltura(aux->getDrcha())));
}

void AVLtree::rotacionIzq(TreeUsuario* &root){
    TreeUsuario* aux = root->refDrcha();
    TreeUsuario* iniciado = root;

    root = aux;
    iniciado->setDrcha(aux->getIzq());
    aux->setIzq(iniciado);
    root->setAltura(1 + max(obtenerAltura(root->getIzq()), obtenerAltura(root->getDrcha())));
    aux->setAltura(1 + max(obtenerAltura(aux->getIzq()), obtenerAltura(aux->getDrcha())));
}

void AVLtree::preOrden(TreeUsuario* raiz){
    if(raiz != nullptr){
        std::cout << raiz->getData()->getNombre() << ", ";
        preOrden(raiz->getIzq());
        preOrden(raiz->getDrcha());
    }
}

void AVLtree::inOrden(TreeUsuario* raiz){
    if(raiz != nullptr){
        preOrden(raiz->getIzq());
        std::cout << raiz->getData()->getNombre() << ", ";
        preOrden(raiz->getDrcha());
    }
}