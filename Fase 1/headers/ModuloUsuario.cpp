#include "../Estructuras/EnlazadaDoble.cpp"
#include "../Estructuras/EnlazadaSimple.cpp"
#include "../Estructuras/CircularDoble.cpp"

#include "ModuloUsuario.h"
#include <string>
#include <windows.h>

using namespace std;

ModuloUsuario::ModuloUsuario(Usuario& entrada, DoublyLinkedList* listaEntrada, ListaSimple* usuarios, Matriz* relaciones){
    this->user = &entrada;
    this->listaPublicaciones = listaEntrada;
    this->listaUsuarios = usuarios;
    this->matrizRelaciones = relaciones;
    this->inter = false;
}

void ModuloUsuario::encabezadoInterfaz(){
    cout<< " \n\n"<<endl;
    cout << "---------------------------------------------------------------------------------"<<endl;
    cout << "Hola " << this->user->getNombre() << " " << this->user->getApellido() << endl;
}

void ModuloUsuario::verPublicaciones(){
    cout<< "Sus amigos y usted tienen estas publicaciones"<< endl;
    while(true){
        if(GetAsyncKeyState(VK_RIGHT)& 0x8000){
            DoublyCircular* coleccion = user->publicacionesAmigos;
            Publicacion* contenido = coleccion->mostrarPublicacionDer();
            if (contenido != nullptr) {
                cout << "Usuario: " << contenido->getId() << endl;
                cout << "Publicacion: " << contenido->getTexto() << endl;
                cout << "Fecha: " << contenido->getFecha() << endl;
                cout << "Hora: " << contenido->getHora() << endl;
            }
            Sleep(300);
        }
        if(GetAsyncKeyState(VK_LEFT)& 0x8000){
            DoublyCircular* coleccion = user->publicacionesAmigos;
            Publicacion* contenido = coleccion->mostrarPublicacionIzq();
            if (contenido != nullptr) {
                cout << "Usuario" << contenido->getId() << endl;
                cout << "Publicacion: " << contenido->getTexto() << endl;
                cout << "Fecha: " << contenido->getFecha() << endl;
                cout << "Hora: " << contenido->getHora() << endl;
            }
            Sleep(300);
        }
        if(GetAsyncKeyState(VK_ESCAPE)& 0x8000){
            break;
        }
        Sleep(50);
    }
}

void ModuloUsuario::subModuloStories(int eleccion, bool bucle){
        bucle = true;
        do {
            cout<< "1. Ver publicaciones"<<endl;
            cout<< "2. Crear publicacion"<<endl;
            cout<< "3. Eliminar publicacion"<<endl;
            cout << "4. Salir" << endl;
            cin >> eleccion;
            switch (eleccion)
            {
            case 1:
                verPublicaciones();
                break;
            case 2:
                this->crearPublicacion();
                break;
            case 3:
                break;
            case 4:
                bucle = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
            
            }
        }while (bucle);
        
        
}

void ModuloUsuario::subModuloPerfil(int eleccion, bool bucle){
    bucle = true;
    do{
        cout << "1. Ver perfil" << endl;
        cout << "2. Eliminar cuenta" << endl;
        cout << "3. Salir" << endl;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:
            cout << "Nombre: " << this->user->getNombre() << endl;
            cout << "Apellido: " << this->user->getApellido() << endl;
            cout << "Fecha de nacimiento: " << this->user->getFechaNac() << endl;
            cout << "Email: " << this->user->getEmail() << endl;
            break;
        case 2:
            cout << "Cuenta eliminada" << endl;
            bucle = false;
            break;
        case 3:
            bucle = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }

    }while(bucle);

}

void ModuloUsuario::subModuloSolicitudes(int eleccion, bool bucle){
    string email;
    bucle = true;
    do{
        cout << "1. Ver solicitudes" << endl;
        cout << "2. Enviar solicitud" << endl;
        cout << "3. Salir" << endl;
        cin >> eleccion;
        switch (eleccion)
        {
        case 1:
            cout << "Solicitudes: " << endl;
            this->user->decidirSolicitudes(matrizRelaciones);
            break;
        case 2:
            cout << endl<< "Ingrese el email de la persona a la que desea enviar la solicitud: ";
            cin >> email;
            for(char &s:email){
                s = tolower(s);
            }
            if (!this->listaUsuarios->findEmail(email)){
                if (!this->user->findSolicitud(email)){
                    Usuario& solicitud = this->listaUsuarios->getCredenciales();
                    bool verificar = matrizRelaciones->insertarAmistad(*user, solicitud, true);
                    if (verificar){
                        solicitud.addSolicitud(this->user);
                        cout << "Solicitud enviada" << endl;
                    }else{
                        cout << "Ya existe una relacion con este usuario" << endl;
                    }
                }else{
                    cout << "Hay una solicitud en proceso con este usuario" << endl;
                }
            }else{
                cout  << "Email no encontrado" << endl;
            }
            break;
        case 3:
            bucle = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }while(bucle);
}

void ModuloUsuario::menu(){
    bool bucleInterno = false;
    int opInterna = 0;
    int op = 0;
    this->inter = true;
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
        this->subModuloPerfil(opInterna, bucleInterno);
        break;

    case 2:
        this->subModuloSolicitudes(opInterna, bucleInterno);
        break;

    case 3:
        this->subModuloStories(opInterna, bucleInterno);
        break;
    case 4:
        break;
    case 5:
        this->inter = false;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
}

void ModuloUsuario::crearPublicacion(){
    string texto;
    Publicacion publicacion;
    publicacion.setId(this->user->getEmail());
    cout << "Escriba su publicacion: ";
    cin.ignore();
    getline(cin, texto);
    publicacion.setTexto(texto);
    this->obtenerFechaHora(publicacion);
    this->listaPublicaciones->append(publicacion);
    this->user->numPublicaciones++;
    this->user->publicacionesPersonales->append(publicacion);
    cout << "Publicacion creada" << endl;
}

void ModuloUsuario::bucleInterfaz(){
    do{
        this->encabezadoInterfaz();
        this->menu();
    }while(this->inter);

}

void ModuloUsuario::obtenerFechaHora(Publicacion& publicacion){
    auto tiempoActual = chrono::system_clock::now();
    time_t fecha = chrono::system_clock::to_time_t(tiempoActual);
    tm* tiempo = localtime(&fecha);

    stringstream fechaStream;
    fechaStream << put_time(tiempo, "%d/%m/%Y");
    publicacion.setFecha(fechaStream.str());

    
    stringstream horaStream;
    horaStream << put_time(tiempo, "%H:%M");
    publicacion.setHora(horaStream.str());
}
