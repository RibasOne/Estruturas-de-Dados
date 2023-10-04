#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lue.hpp"
using namespace std;

template <typename T>
void copiar(LUE <T> lista1, LUE <T> &lista2){
    No <T> *aux = lista1.comeco;

    inicializarLUE(lista2);
    while( aux != NULL ){
        inserirFinalLUE(lista2, aux->info);
        aux = aux->elo;
    }
}

template <typename T>
LUE <T> copiar( LUE <T> lista ){
    No <T> *aux = lista.comeco;
    LUE <T> lista2;

    inicializarLUE(lista2);
    while( aux != NULL ){
        inserirFinalLUE(lista2, aux->info);
        aux = aux->elo;
    }
    return lista2;
}

int main(){
    srand(time(NULL));
    LUE <int> lista1, lista2, lista3;
    int tam = rand()%15 + 5;
    srand(time(NULL));

    inicializarLUE(lista1);
    for( int i=0; i<tam; i++ )
        inserirLUE(lista1, rand()%30 );

    copiar( lista1, lista2 );
    lista3 = copiar(lista1);

    cout << endl << "Lista 1: ";
    mostrarLUE(lista1);
    cout << endl << "Lista 2: ";
    mostrarLUE(lista2);
    cout << endl << "Lista 3: ";
    mostrarLUE(lista3);

    liberarLUE(lista1);
    liberarLUE(lista2);
    liberarLUE(lista3);

    cout << endl;
}
