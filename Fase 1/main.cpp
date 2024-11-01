#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <windows.h>
#include "Estructuras/Matriz.h"
#include "Estructuras/EnlazadaSimple.cpp"
#include "Estructuras/EnlazadaDoble.cpp"
#include "headers/ModuloUsuario.h"
#include "headers/ModuloAdmin.h"

using namespace std;    

bool inter = false;
ListaSimple* listaUsuarios = new ListaSimple();
DoublyLinkedList* listaPublicaciones = new DoublyLinkedList("general");
Matriz* matrizRelaciones = new Matriz();
Usuario admin("admin", "admin", "01/01/2000", "admin@gmail.com", "EDD2S2024", matrizRelaciones);

bool verificarFecha(string fecha){
    regex fechaRegex(R"(^([1-2][0-9]{3})/(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])$)");
    smatch match;
    if (regex_search(fecha, match, fechaRegex)){
        return true;
    }else{
        return false;
    }
}
`
bool verificarEmail(string email){
    regex emailRegex(R"(^(\w+)(\.\w+)*@(\w+)(\.\w+)+$)");
    smatch match;
    if (regex_search(email, match, emailRegex)){
        return true;
    }else{
        return false;
    }
}

int consolaUFT8(){
    SetConsoleOutputCP(CP_UTF8);
    locale::global(locale(""));
    return 0;
}

void interfaz();

int main(){
    consolaUFT8();
    do{
        interfaz();
    }while(inter);
};

int menu(){
    int op;
    cout << "1. Iniciar Sesion" <<endl;
    cout << "2. Registrarse" <<endl;
    cout << "3. Informacion" << endl;
    cout << "4. Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> op;
    return op;
}

void inicioSesion(){
    string email, pass;
    cout << "Ingrese su email: ";
    cin >> email;
    for (char &s:email){
        s = tolower(s);
    }   
    cout << "Ingrese su contraseña: ";
    cin.ignore();
    getline(cin, pass);   
    if (listaUsuarios->comprobarCredenciales(email, pass)){
        Usuario* user = listaUsuarios->getCredenciales();
        ModuloUsuario* moduloU = new ModuloUsuario(user, listaPublicaciones, listaUsuarios, matrizRelaciones);
        moduloU->bucleInterfaz();
        delete moduloU;
    }else{
        if (admin.getEmail() == email && admin.getPass() == pass){
            ModuloAdmin* moduloA = new ModuloAdmin(admin, listaPublicaciones, listaUsuarios, matrizRelaciones);
            moduloA->bucleInterfaz();
            delete moduloA;
        }
        else{
            cout << "Credenciales incorrectas" <<endl;
        }
    }
}

void registro(){
    string nombre, apellido, fechaNacimiento, email, pass;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: ";
    cin >> apellido;
    cout << "Ingrese su fecha de nacimiento: ";
    cin >> fechaNacimiento;
    while (!verificarFecha(fechaNacimiento)){
        cout << "Fecha invalida, ingrese nuevamente: ";
        cin >> fechaNacimiento;
        cout << endl;
    }
    cout << "Ingrese su email: ";
    cin >> email;
    for(char &s:email){
        s = tolower(s);
    }
    while (!listaUsuarios->findEmail(email) || !verificarEmail(email)){
        cout << "Hay un problema con el correo ingresado" <<endl;
        cout << "Ingrese un nuevo correo: ";
        cin >> email;
        for(char &s:email){
            s = tolower(s);
        }
    }
    cout << "Ingrese su contraseña: ";
    cin.ignore();
    getline(cin, pass);

    Usuario* user = new Usuario(nombre, apellido, fechaNacimiento, email, pass, matrizRelaciones);
    listaUsuarios->append(user);
    cout<<"Usuario creado exitosamente"<<endl;
    
}

void interfaz(){
    inter = false;
    int inicio = menu();
    switch(inicio){
        case 1:
            cout << "Iniciar Sesion" << endl;
            inicioSesion();
            inter = true;
            break;
        case 2:
            cout << "Registrarse" << endl;
            registro();
            inter = true;
            break;
        case 3:
            cout << "Informacion" << endl;
            break;
        case 4:
            cout << "Salir" << endl;
            inter = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            inter = true;
            cin.clear();
            break;
    }
}