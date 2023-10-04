#include <iostream>
using namespace std;

template <typename T>
struct Pilha{
    T vetor[TAMP];
    int topo;
};

template <typename T>
void inicializarPilha(Pilha <T> &p){
    p.topo = -1;
}

template <typename T>
bool inserirPilha(Pilha <T> &p, T valor){
    if( p.topo == TAMP-1 ) return false;
    p.topo++;
    p.vetor[p.topo] = valor;
    return true;
}

template <typename T>
bool retirarPilha(Pilha <T> &p, T &valor){
    if( p.topo == -1 ) return false;
    valor = p.vetor[p.topo];
    p.topo--;
    return true;
}

template <typename T>
bool pilhaVazia(Pilha <T> p){
    return (p.topo == -1) ? true : false;
}

template <typename T>
void mostrarPilha(char frase[], Pilha <T> p){
    T aux;
    cout << frase << ": ";
    while( retirarPilha(p, aux) ){
        cout << aux << " ";
    }
    cout << endl;
}
