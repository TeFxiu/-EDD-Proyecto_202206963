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
    cout << "4. Salir" << endl;
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
        Usuario nuevoUsuario(
            it.value()["nombres"],
            it.value()["apellidos"],
            it.value()["fecha_de_nacimiento"],
            it.value()["correo"],
            it.value()["contraseña"]
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
        Publicacion nuevaPublicacion(
            it.value()["correo"],
            it.value()["contenido"],
            it.value()["fecha"],
            it.value()["hora"]
        );
        listaUsuarios->findEmail(it.value()["correo"]);
        Usuario& usuario = listaUsuarios->getCredenciales();
        usuario.publicacionesPersonales->append(nuevaPublicacion);
        usuario.numPublicaciones++;
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
        Usuario& emisor = listaUsuarios->getCredenciales();
        listaUsuarios->findEmail(it.value()["receptor"]);
        Usuario& receptor = listaUsuarios->getCredenciales();

        if(estado == "ACEPTADA"){
            matrizRelaciones->insertarAmistad(emisor, receptor);
            emisor.numRelaciones++;
            receptor.numRelaciones++;
            emisor.addStoriesAmigos(receptor.publicacionesPersonales);
            receptor.addStoriesAmigos(emisor.publicacionesPersonales);
        }else{
            receptor.addSolicitud(&emisor);
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
            cout << "Saliendo..." << endl;
            opcion = 0;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }while(opcion != 0);
}




