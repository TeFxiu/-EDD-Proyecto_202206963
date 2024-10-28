#include "AVLtree.h"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/SimpleAmistad.cpp"
#include "C:/Users/TeFxiu/Documents/EDD/[EDD]Proyecto_202206963/Fase 1/Estructuras/Pila.cpp"



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

    return nullptr;
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

void AVLtree::preOrdenTabla(TreeUsuario* raiz, ListaUsuarios* lista , Usuario* perfil, Grafo* amistades){
    if(raiz != nullptr){
        if (raiz->getData()->getEmail() != perfil->getEmail()){
            if(!perfil->getEnviados()->findEmail(raiz->getData()->getEmail())){
                if(!perfil->getPila()->findEmail(raiz->getData()->getEmail())){
                    bool receptor = amistades->buscarAmistad(raiz->getData(), perfil);
                    if (!receptor){
                        lista->append(raiz->getData());
                    }
                }
            }
        }
        preOrdenTabla(raiz->getIzq(), lista, perfil, amistades);
        preOrdenTabla(raiz->getDrcha(), lista, perfil, amistades);
    }
}

void AVLtree::preOrden(QStackedWidget*& ventana,QTableWidget* tabla,TreeUsuario* raiz){
    if(raiz != nullptr){
        tabla->insertRow(tabla->rowCount());
        int row = tabla->rowCount()-1;
        Usuario* user = raiz->getData();

        tabla->setItem(row, 0, new QTableWidgetItem(QString(user->getNombre().c_str())));
        tabla->setItem(row, 1, new QTableWidgetItem(QString(user->getApellido().c_str())));
        tabla->setItem(row, 2, new QTableWidgetItem(QString(user->getEmail().c_str())));

        time_t fecha = user->getFechaNac();
        tm* fechaFormat = localtime(&fecha);

        stringstream fomat;
        fomat << put_time(fechaFormat, "%Y/%m/%d");

        tabla->setItem(row, 3, new QTableWidgetItem(QString(fomat.str().c_str())));

        QPushButton* editar = new QPushButton("Editar");

        QObject::connect(editar, &QPushButton::clicked, [this, &ventana](){
            ventana->setCurrentIndex(1);
        });

        tabla->setCellWidget(row, 4, editar);


        QPushButton* eliminar = new QPushButton("Eliminar");

        QObject::connect(eliminar, &QPushButton::clicked, [this, user](){
            this->estaVacio();
        });

        tabla->setCellWidget(row, 5, eliminar);

        preOrden(ventana,tabla,raiz->getIzq());
        preOrden(ventana,tabla,raiz->getDrcha());
    }
}

void AVLtree::inOrden( QStackedWidget*& ventana,QTableWidget* tabla,TreeUsuario* raiz){
    if(raiz != nullptr){

        inOrden( ventana,tabla, raiz->getIzq());
            tabla->insertRow(tabla->rowCount());
            int row = tabla->rowCount()-1;
            Usuario* user = raiz->getData();

            tabla->setItem(row, 0, new QTableWidgetItem(QString(user->getNombre().c_str())));
            tabla->setItem(row, 1, new QTableWidgetItem(QString(user->getApellido().c_str())));
            tabla->setItem(row, 2, new QTableWidgetItem(QString(user->getEmail().c_str())));

            time_t fecha = user->getFechaNac();
            tm* fechaFormat = localtime(&fecha);

            stringstream fomat;
            fomat << put_time(fechaFormat, "%Y/%m/%d");

            tabla->setItem(row, 3, new QTableWidgetItem(QString(fomat.str().c_str())));

            QPushButton* editar = new QPushButton("Editar");

            QObject::connect(editar, &QPushButton::clicked, [this, &ventana](){
                ventana->setCurrentIndex(1);
            });

            tabla->setCellWidget(row, 4, editar);


            QPushButton* eliminar = new QPushButton("Eliminar");

            QObject::connect(eliminar, &QPushButton::clicked, [this, user](){
                this->estaVacio();
            });

            tabla->setCellWidget(row, 5, eliminar);
        inOrden(ventana,tabla,raiz->getDrcha());
    }
}

void AVLtree::postOrden(QStackedWidget*& ventana,QTableWidget* tabla,TreeUsuario* raiz){
    if(raiz != nullptr){
        postOrden(ventana,tabla, raiz->getIzq());
        postOrden(ventana,tabla, raiz->getDrcha());
        tabla->insertRow(tabla->rowCount());
        int row = tabla->rowCount()-1;
        Usuario* user = raiz->getData();

        tabla->setItem(row, 0, new QTableWidgetItem(QString(user->getNombre().c_str())));
        tabla->setItem(row, 1, new QTableWidgetItem(QString(user->getApellido().c_str())));
        tabla->setItem(row, 2, new QTableWidgetItem(QString(user->getEmail().c_str())));

        time_t fecha = user->getFechaNac();
        tm* fechaFormat = localtime(&fecha);

        stringstream fomat;
        fomat << put_time(fechaFormat, "%Y/%m/%d");

        tabla->setItem(row, 3, new QTableWidgetItem(QString(fomat.str().c_str())));

        QPushButton* editar = new QPushButton("Editar");

        QObject::connect(editar, &QPushButton::clicked, [this, &ventana](){
            ventana->setCurrentIndex(1);
        });

        tabla->setCellWidget(row, 4, editar);


        QPushButton* eliminar = new QPushButton("Eliminar");

        QObject::connect(eliminar, &QPushButton::clicked, [this, user](){
            this->estaVacio();
        });

        tabla->setCellWidget(row, 5, eliminar);
    }
}
