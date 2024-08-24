#include "../Estructuras/EnlazadaDoble.cpp"
#include "../Estructuras/EnlazadaSimple.cpp"
#include "ModuloAdmin.h"

ModuloAdmin::ModuloAdmin(Usuario& entrada, DoublyLinkedList* listaEntrada, ListaSimple* usuarios, Matriz* relaciones){
    user = &entrada;
    matrizRelaciones = relaciones;
    listaPublicaciones = listaEntrada;
    listaUsuarios = usuarios;
    inter = false;
}

void ModuloAdmin::encabezadoInterfaz(){
    cout << "1. Carga de usuarios" << endl;
    cout << "2. Carga de relaciones" << endl;
    cout << "3. Carga de publicaciones" << endl;
    cout << "4. Gestionar Usuarios" << endl;
    cout<< "5. Reportes" << endl;
    cout << "6. Salir" << endl;
}

char* ModuloAdmin::buscarDireccion(){
    const char* filter[]= {"*.json"};
    const char* filepath = tinyfd_openFileDialog(
            "Seleccione un archivo",
            "",
            1,
            filter,
            "Archivo JSON",
            0
    );

    if(!filepath){
        cout << "No se selecciono ningun archivo" << endl;
        return nullptr;
    }
    return strdup(filepath);
}

void ModuloAdmin::cargaUsuarios(){
    char* direccion = buscarDireccion();

    ifstream arch(direccion);
    if (!arch.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    json jsonData;
    arch >> jsonData;

    for (const auto& it : jsonData.items()){
        Usuario* nuevoUsuario = new Usuario(
                it.value()["nombres"],
                it.value()["apellidos"],
                it.value()["fecha_de_nacimiento"],
                it.value()["correo"],
                it.value()["contraseña"],
                matrizRelaciones
        );
        listaUsuarios->append(nuevoUsuario);
    }

}

void ModuloAdmin::cargarPublicaciones(){
    char *direccion = buscarDireccion();
    ifstream arch(direccion);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    json jsonData;
    arch >> jsonData;

    for(const auto& it : jsonData.items()){
        Publicacion* nuevaPublicacion = new Publicacion(
                it.value()["correo"],
                it.value()["contenido"],
                it.value()["fecha"],
                it.value()["hora"]
        );
        listaUsuarios->findEmail(it.value()["correo"]);
        Usuario* usuario = listaUsuarios->getCredenciales();
        usuario->getPublicacionesPersonales()->append(nuevaPublicacion);
        usuario->setNumPublicaciones();
        listaPublicaciones->append(nuevaPublicacion);
    }
}

void ModuloAdmin::cargaRelaciones(){
    char* direccion = buscarDireccion();
    ifstream arch(direccion);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    json jsonData;
    arch >> jsonData;

    for(const auto& it : jsonData.items()){
        string estado = it.value()["estado"];
        listaUsuarios->findEmail(it.value()["emisor"]);
        Usuario* emisor = listaUsuarios->getCredenciales();
        listaUsuarios->findEmail(it.value()["receptor"]);
        Usuario* receptor = listaUsuarios->getCredenciales();

        if(estado == "ACEPTADA"){
            matrizRelaciones->insertarAmistad(emisor, receptor);
            emisor->setNumRelaciones();
            receptor->setNumRelaciones();
            emisor->addStoriesAmigos(receptor->getPublicacionesPersonales());
            receptor->addStoriesAmigos(emisor->getPublicacionesPersonales());
        }else{
            receptor->addSolicitud(emisor);
        }
    }
}

Usuario* ModuloAdmin::buscarUsuario(){
    Usuario* usuario = listaUsuarios->getCredenciales();
    return usuario;
}

void ModuloAdmin::eliminarUsuario(){
    int opcion = 0;
    while (opcion == 0)
    {
        cout << "Gestionar usuarios" << endl;
        cout << "1. Eliminar usuario" << endl;
        cout << "2. salir" << endl;
        string email;
        Usuario* usuario = nullptr;
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                cout << "Ingrese el email del usuario a eliminar: ";
                cin >> email;
                for(char &s:email){
                    s = tolower(s);
                }
                if(listaUsuarios->findEmail(email)){
                    cout << "Email no encontrado" << endl;
                    return;
                }
                usuario = buscarUsuario();
                if (usuario->getNumRelaciones() != 0) {
                    matrizRelaciones->eliminarAmistad(usuario);
                    delete usuario->getPublicacionesPersonales();
                    this->listaPublicaciones->removeAll(usuario->getEmail());
                    usuario->eliminarSolicitudes();
                    listaUsuarios->remove(usuario->getEmail());

                }
                cout << "Usuario eliminado" << endl;
                opcion = 0;
                break;
            case 2:
                opcion = 1;
                cout << "Saliendo..." << endl;
                break;
            default:
                break;
        }
    }

}

void ModuloAdmin::reportes(){
    int op = 0;
    while (op == 0){
        cout << "1. Grafico de la lista de usuarios"<<endl;
        cout << "2. Grafico de la matriz dispersa" <<  endl;
        cout << "3. Grafico de la lista doblemente enlazada"<<endl;
        cout << "4. Tops" << endl;
        cout << "5. Salir"<< endl;
        cin >> op;
        switch (op) {
            case 1:
                listaUsuarios->reporte();
                break;
            case 2:
                matrizRelaciones->reporte();
                break;
            case 3:
                listaPublicaciones->reporte();
                break;
            case 4:
                break;
            case 5:
                break;
            default:{
                cout << "Opcion Invalida" << endl;
                break;
            }

        }

    }
}

void ModuloAdmin::bucleInterfaz(){
    int opcion;
    do{
        encabezadoInterfaz();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                cout << "Carga de usuario..." << endl;
                cargaUsuarios();
                break;
            case 2:
                cargaRelaciones();
                cout << "Carga de relaciones" << endl;
                break;
            case 3:
                cout << "Carga de publicaciones" << endl;
                cargarPublicaciones();
                break;
            case 4:
                eliminarUsuario();
                break;

            case 5:
                reportes();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                opcion = 0;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 0);
}