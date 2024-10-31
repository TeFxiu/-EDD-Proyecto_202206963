#include "Huffman.h"

Huffman::Huffman(){
    raiz = nullptr;

    for(int i = 0; i < 256; i++){
        this->codigos[i] = "";
    }
}

Huffman::~Huffman(){
    eliminar(this->raiz);
}

std::string Huffman::comprimir(std::string texto){
    std::string comprimido = "";

    for(char c: texto){
        comprimido+=codigos[(unsigned char)c];
    }
    return comprimido;
}

std::string Huffman::descomprimir(std::string comprimido){
    std::string texto = "";
    NodoH *actual = this->raiz;

    for(char c: comprimido){
        if(c == '0'){actual = actual->izq;}
        else{actual = actual->der;}

        if(actual->izq == nullptr && actual->der == nullptr){
            texto+=actual->c;
            actual = this->raiz;
        }
    }

    return texto;
}

void Huffman::crearArbol(std::string s){
    //Construyendo lista simplemente enlazada
    while(s != ""){
        Nodo *nuevo = new Nodo(s[0]);
        nuevo->n = std::count(s.begin(), s.end(), nuevo->c);
        this->insertarCaracter(nuevo);
        s.erase(std::remove(s.begin(), s.end(), nuevo->c), s.end());
    }

    while(this->raiz->sig != nullptr){
        Nodo *derecha = this->raiz;
        Nodo *izquierda = this->raiz->sig;

        this->raiz = izquierda->sig;

        Nodo *nueva_raiz = new Nodo('~');
        nueva_raiz->n = izquierda->n + derecha->n;
        nueva_raiz->izq = izquierda;
        nueva_raiz->der = derecha;

        insertarCaracter(nueva_raiz);
    }
}

void Huffman::insertarCaracter(Nodo *nuevo){
    //Insertando caracter en lista simplemente enlazada
    if(this->raiz == nullptr){
        this->raiz = nuevo;

    }else{
        Nodo *aux = this->raiz;
        while(aux->sig != nullptr){
            if((nuevo->n < aux->sig->n) ||
               (nuevo->n == aux->sig->n && nuevo->c < aux->sig->c)){
                nuevo->sig = aux->sig;
                aux->sig = nuevo;
                break;
            }
            aux = aux->sig;
        }

        if(aux->sig == nullptr){
            aux->sig = nuevo;
        }
    }
}

void Huffman::crearCodigosHuffman(Nodo *raiz, std::string codigo){
    if(raiz == nullptr) return;

    if(raiz->izq == nullptr && raiz->der == nullptr){
        codigos[(unsigned char)raiz->c] = codigo;
    }

    crearCodigosHuffman(raiz->izq, codigo + "0");
    crearCodigosHuffman(raiz->der, codigo + "1");
}

void Huffman::graficar(){
    std::ofstream outfile ("huffman.dot");
    outfile << "digraph G {" << std::endl;

    if(raiz != nullptr){
        graficar(raiz, outfile);
    }

    outfile << "}" << std::endl;
    outfile.close();
    int returnCode = system("dot -Tpng ./huffman.dot -o ./huffman.png");

    if(returnCode == 0){std::cout << "Command executed successfully." << std::endl;}
    else{std::cout << "Command execution failed or returned non-zero: " << returnCode << std::endl;}
}

void Huffman::imprimirCodigos(){
    for(int i = 0; i < 256; i++){
        if(codigos[i] != ""){
            std::cout << char(i) << ": " << codigos[i] << '\n';
        }
    }
}

void Huffman::graficar(Nodo *raiz, std::ofstream &f){
    if(raiz != nullptr){
        std::ostringstream oss;
        oss << raiz;
        std::string nombre = oss.str();

        f << "Nodo" + nombre + "[label = \"" + raiz->c + "(" + std::to_string(raiz->n) + ")" + "\"]" << std::endl;

        if(raiz->izq != nullptr){
            oss.str("");
            oss << raiz->izq;
            std::string izquierda = oss.str();
            f << "Nodo" + nombre + "->Nodo" + izquierda + "[label = \"0\"];" << std::endl;
        }

        if(raiz->der != nullptr){
            oss.str("");
            oss << raiz->der;
            std::string derecha = oss.str();
            f << "Nodo" + nombre + "->Nodo" + derecha + "[label = \"1\"];" << std::endl;
        }

        this->graficar(raiz->izq, f);
        this->graficar(raiz->der, f);
    }
}

void Huffman::eliminar(Nodo *raiz){
    if(raiz != nullptr){
        eliminar(raiz->izq);
        eliminar(raiz->der);
        delete raiz;
    }
}

Nodo* Huffman::getRaiz(){
    return raiz;
}
