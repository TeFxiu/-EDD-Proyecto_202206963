#include "ModuloUsuario.h"
using namespace std;

void ModuloUsuario::encabezadoInterfaz(){
    cout<< " \n\n"<<endl;
    cout << "---------------------------------------------------------------------------------"<<endl;
    cout << "Hola " << this->user->getNombre() << " " << this->user->getApellido() << endl;
}

void ModuloUsuario::menu(){
    int op;
    cout << "1. Perfil" << endl;
    cout << "2. Solicitudes" << endl;
    cout << "3. Publicaciones" << endl;
    cout << "4. Reportes" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> op;
    switch (op)
    {
    case 1:
        cout<< "1. Ver perfil"<<endl;
        cout << "2. Eliminar cuenta"<<endl;
        cout << "3. Salir" << endl;
        break;

    case 2:
        cout<< "1.Ver solicitudes"<<endl;
        cout<< "2. Enviar solicitud"<<endl;
        cout << "3. Salir" << endl;
        break;

    case 3:
        cout<< "1. Ver publicaciones"<<endl;
        cout<< "2. Crear publicacion"<<endl;
        cout<< "3. Eliminar publicacion"<<endl;
        cout << "4. Salir" << endl;
        break;
    case 4:
        break;
    case 5:
        this->inter = false;
        break;
    default:
        cout << "Opcion no valida" << endl;
        this->inter = true;
        break;
    }
}

void ModuloUsuario::crearPublicacion(){
    string texto;
    cout << "Escriba su publicacion: ";
    cin >> texto;
    cout << "Publicacion creada" << endl;
}

void ModuloUsuario::bucleInterfaz(){
    do{
        this->encabezadoInterfaz();
        this->menu();
    }while(this->inter);

}
