#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lde.hpp"
using namespace std;

template <typename T>
void copiar(LDE <T> lista1, LDE <T> &lista2){
    No <T> *aux = lista1.comeco;

    inicializarLDE(lista2);
    while( aux != NULL ){
        inserirFinalLDE(lista2, aux->info);
        aux = aux->eloP;
    }
}

template <typename T>
LDE <T> copiar( LDE <T> lista ){
    No <T> *aux = lista.comeco;
    LDE <T> lista2;

    inicializarLDE(lista2);
    while( aux != NULL ){
        inserirFinalLDE(lista2, aux->info);
        aux = aux->eloP;
    }
    return lista2;
}

int main(){
    srand(time(NULL));
    LDE <int> lista1, lista2, lista3;
    int tam = rand()%15 + 5;
    srand(time(NULL));

    inicializarLDE(lista1);
    for( int i=0; i<tam; i++ )
        inserirLDE(lista1, rand()%30 );

    copiar( lista1, lista2 );
    lista3 = copiar(lista1);

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);
    cout << endl << "Lista 2: ";
    mostrarLDE(lista2);
    cout << endl << "Lista 3: ";
    mostrarLDE(lista3);

    liberarLDE(lista1);
    liberarLDE(lista2);
    liberarLDE(lista3);

    cout << endl;
}
