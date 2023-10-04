#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lue.hpp"
using namespace std;

template <typename T>
int comprimento(LUE <T> lista){
    No <T> *aux = lista.comeco;
    int cont = 0;

    while( aux != NULL ){
        cont++;
        aux = aux->elo;
    }
    return cont;
}

int main(){
    LUE <char> lista1;

    inicializarLUE(lista1);
    inserirLUE(lista1, 'P');
    inserirLUE(lista1, 'E');
    inserirLUE(lista1, 'R');
    inserirLUE(lista1, 'N');
    inserirLUE(lista1, 'A');
    inserirLUE(lista1, 'M');
    inserirLUE(lista1, 'B');
    inserirLUE(lista1, 'U');
    inserirLUE(lista1, 'C');
    inserirLUE(lista1, 'O');

    cout << endl << "Lista 1: ";
    mostrarLUE(lista1);
    cout << endl << "Tamanho da lista 1: " << comprimento(lista1);
    liberarLUE(lista1);

    LUE <int> lista2;
    int tam = rand()%10 + 5;
    srand(time(NULL));

    inicializarLUE(lista2);
    for( int i=0; i<tam; i++ )
        inserirLUE(lista2, rand()%30 );

    cout << endl << "Lista 2: ";
    mostrarLUE(lista2);
    cout << endl << "Tamanho da lista 2: " << comprimento(lista2);

    liberarLUE(lista2);

    cout << endl;
}
