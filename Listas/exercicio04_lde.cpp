#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lde.hpp"
using namespace std;

template <typename T>
LDE <T> diferenca( LDE <T> lista1, LDE <T> lista2 ){
    LDE <T> resultado;
    No <T> *aux = lista1.comeco;

    inicializarLDE(resultado);
    while( aux != NULL ){
        if( pesquisarLDE(lista2, aux->info) == NULL )
            inserirLDE(resultado, aux->info );
        aux = aux->eloP;
    }

    return resultado;
}

int main(){
    srand(time(NULL));
    LDE <int> lista1, lista2, lista3, lista4;
    int tam1 = rand()%15 + 5;
    int tam2 = rand()%15 + 5;

    inicializarLDE(lista1);
    for( int i=0; i<tam1; i++ )
        inserirLDE(lista1, rand()%20 );
    inicializarLDE(lista2);
    for( int i=0; i<tam2; i++ )
        inserirLDE(lista2, rand()%20 );

    lista3 = diferenca(lista1, lista2);
    lista4 = diferenca(lista2, lista1);

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);
    cout << endl << "Lista 2: ";
    mostrarLDE(lista2);
    cout << endl << "Lista 3: ";
    mostrarLDE(lista3);
    cout << endl << "Lista 4: ";
    mostrarLDE(lista4);

    liberarLDE(lista1);
    liberarLDE(lista2);
    liberarLDE(lista3);
    liberarLDE(lista4);

    cout << endl;
}
