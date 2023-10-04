#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lue.hpp"
using namespace std;

template <typename T>
LUE <T> comuns( LUE <T> lista1, LUE <T> lista2 ){
    LUE <T> resultado;
    No <T> *aux = lista1.comeco;

    inicializarLUE(resultado);
    while( aux != NULL ){
        if( pesquisarLUE(lista2, aux->info) != NULL )
            inserirLUE(resultado, aux->info );
        aux = aux->elo;
    }

    return resultado;
}

int main(){
    srand(time(NULL));
    LUE <int> lista1, lista2, lista3;
    int tam1 = rand()%15 + 5;
    int tam2 = rand()%15 + 5;

    inicializarLUE(lista1);
    for( int i=0; i<tam1; i++ )
        inserirLUE(lista1, rand()%20 );
    inicializarLUE(lista2);
    for( int i=0; i<tam2; i++ )
        inserirLUE(lista2, rand()%20 );

    lista3 = comuns(lista1, lista2);

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
