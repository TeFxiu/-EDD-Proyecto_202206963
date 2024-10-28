//
// Created by TeFxiu on 10/10/2024.
//

#include "Grafo.h"

Grafo::Grafo() {}

void Grafo::insertar(Usuario *emisor, Usuario *receptor) {
    SuperVertice* super = new SuperVertice(emisor);
    SuperVertice* aux = nullptr;
    if (!primero){
        primero = super;
        ultimo = primero;
        super->insertar(receptor);
        return;
    }
    aux = primero;
    while (aux) {
        if (aux->emisor->getEmail() == emisor->getEmail()) {
            aux->insertar(receptor);
            return;
        }
        aux = aux->siguiente;
    }
    ultimo->siguiente = super;
    super->anterior = ultimo;
    ultimo = super;
    ultimo->insertar(receptor);
}

void Grafo::buscarRecomendaciones(SuperVertice* amigo, ListaUsuarios* usuarios){
    Vertice* aux = amigo->amigos;
    while(aux){
        SuperVertice* actual = this->amistedesEmisor(aux->receptor);
        Vertice* candidato = actual->amigos;
        while (candidato){
            if (candidato->receptor->getEmail() != amigo->emisor->getEmail()){
                if (!amigo->buscarRelacion(candidato->receptor)){
                    usuarios->append(candidato->receptor);
                }
            }
            candidato = candidato->delante;
        }
        aux = aux->delante;
    }
}

SuperVertice* Grafo::amistedesEmisor(Usuario *emisor) {
    SuperVertice* aux = primero;
    while (aux){
        if (aux->emisor->getEmail() == emisor->getEmail()) return aux;
        aux = aux->siguiente;
    }
    return nullptr;
}

bool Grafo::buscarAmistad(Usuario *emisor, Usuario *receptor) {
    SuperVertice* aux = primero;

    while (aux){
        if (aux->emisor->getEmail() == emisor->getEmail()) return aux->buscarRelacion(receptor);
        aux = aux->siguiente;
    }
    return false;

}

void Grafo::generarSugerencias(Grafo* general, SuperVertice* amigos){
    ofstream file("sugerencias.dot");
    file << "digraph G{" << endl;
    file << amigos->emisor->getId() << "[label=\"" << amigos->emisor->getNombre() << "\"];"<< endl;
    Vertice* aux = amigos->amigos;
    while (aux){
        file << aux->receptor->getId() << "[label=\"" << aux->receptor->getNombre() << "\", style=filled, fillcolor=red"<< "];"<< endl;
        file << aux->receptor->getId() << " -> " << amigos->emisor->getId() << "[dir=none];" << endl;
        SuperVertice* sugerencias = general->amistedesEmisor(aux->receptor);
        Vertice* subAux = sugerencias->amigos;
        while(subAux){
            if (subAux->receptor->getEmail() == amigos->emisor->getEmail()){
                subAux = subAux->delante;
                continue;
            }
            if (amigos->buscarRelacion(subAux->receptor)){
                subAux = subAux->delante;
                continue;
            }
            file << subAux->receptor->getId() << "[label=\"" << subAux->receptor->getNombre() << "\", style=filled, fillcolor=green"<< "];"<< endl;
            file << subAux->receptor->getId() << " -> " << aux->receptor->getId() << "[dir=none];" << endl;
            subAux = subAux->delante;
        }

        aux = aux->delante;
    }
    file << "}" << endl;
    file.close();
    string command = "dot -Tpng sugerencias.dot -o sugerencias.png";
    if (system(command.c_str()) == 0)
    {
        cout << "Graph created successfully" << endl;
    }
    else
    {
        cout << "Error creating graph" << endl;
    }
}

void Grafo::generarGrafo(){
    ofstream file("grafo.dot");
    file << "digraph G{" << endl;
    SuperVertice* aux = primero;
    ListaUsuarios* registrados = new ListaUsuarios();
    while (aux){
        file << aux->emisor->getId() << "[label=\"" << aux->emisor->getNombre() << "\" " << "];"<< endl;
        SuperVertice* sugerencias = this->amistedesEmisor(aux->emisor);
        Vertice* subAux = sugerencias->amigos;
        while(subAux){
            if (registrados->buscarB(subAux->receptor)) {
                subAux = subAux->delante;
                continue;
            }
            file << subAux->receptor->getId() << "[label=\"" << subAux->receptor->getNombre() << "\""<< "];"<< endl;
            file << subAux->receptor->getId() << " -> " << aux->emisor->getId() << "[dir=none];" << endl;
            subAux = subAux->delante;
        }
        registrados->append(aux->emisor);
        aux = aux->siguiente;
    }
    file << "}" << endl;
    file.close();
    string command = "dot -Tpng grafo.dot -o grafo.png";
    if (system(command.c_str()) == 0)
    {
        cout << "Graph created successfully" << endl;
    }
    else
    {
        cout << "Error creating graph" << endl;
    }
}

void Grafo::listaAdyacencia(){
    ofstream file("adyacencia.dot");
    file << "digraph G{" << endl;
    file << " rankdir=TB;" << endl;
    file << "node[shape = box];" << endl;
    SuperVertice* aux = primero;
    int contador = 1;
    while (aux){
        file << "{rank=same;" << endl;
        file << aux->emisor->getId() << "[label=\"" << aux->emisor->getNombre() << "\" " << "];"<< endl;
        SuperVertice* sugerencias = this->amistedesEmisor(aux->emisor);
        Vertice* subAux = sugerencias->amigos;
        Usuario* anterior = aux->emisor;
        string id = "_" + to_string(contador);
        while(subAux){
            file << "\"" <<subAux->receptor->getId()<< id <<"\"" <<"[label=\"" << subAux->receptor->getNombre() << "\""<< "];"<< endl;
            if (aux->emisor->getId() == anterior->getId()){
                file << anterior->getId() << " -> " << "\"" <<subAux->receptor->getId() << id << "\"" << "[dir=none];" << endl;
            }else{
                file << "\""<< anterior->getId() << id <<"\""<< " -> "<< "\""<< subAux->receptor->getId() << id << "\""<<"[dir=none];" << endl;
            }
            anterior = subAux->receptor;
            subAux = subAux->delante;
        }
        contador++;
        file << "}";
        if (aux->siguiente) file << aux->emisor->getId() << " -> " << aux->siguiente->emisor->getId() << "[dir=none];" << endl;
        aux = aux->siguiente;
    }
    file << "}" << endl;
    file.close();
    string command = "dot -Tpng adyacencia.dot -o adyacencia.png";
    if (system(command.c_str()) == 0)
    {
        cout << "Graph created successfully" << endl;
    }
    else
    {
        cout << "Error creating graph" << endl;
    }
}
