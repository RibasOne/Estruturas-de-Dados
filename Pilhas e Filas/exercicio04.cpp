#include <iostream>
#define TAMP 50
#define TAMF 50
#include "pilha.hpp"
#include "fila.hpp"
using namespace std;

template <typename T>
void inverterFila(Fila <T> &f){
    Pilha <T> p;
    T aux;

    inicializarPilha(p);
    while( retirarFila(f, aux) )
        inserirPilha(p, aux);
    inicializarFila(f);
    while( retirarPilha(p, aux))
        inserirFila(f,aux);
}

int main(){
    Fila <char> fila;
    string texto;

    cout << "Digite uma frase: ";
    getline(cin, texto);

    inicializarFila(fila);
    for( int i=0; i<texto.length(); i++ )
        inserirFila(fila, texto[i]);

    inverterFila(fila);
    mostrarFila("Fila resultado", fila);

    cout << endl;
}
