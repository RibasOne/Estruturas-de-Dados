#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lde.hpp"
using namespace std;

template <typename T>
int comprimento(LDE <T> lista){
    No <T> *aux = lista.comeco;
    int cont = 0;

    while( aux != NULL ){
        cont++;
        aux = aux->eloP;
    }
    return cont;
}

int main(){
    LDE <char> lista1;

    inicializarLDE(lista1);
    inserirLDE(lista1, 'P');
    inserirLDE(lista1, 'E');
    inserirLDE(lista1, 'R');
    inserirLDE(lista1, 'N');
    inserirLDE(lista1, 'A');
    inserirLDE(lista1, 'M');
    inserirLDE(lista1, 'B');
    inserirLDE(lista1, 'U');
    inserirLDE(lista1, 'C');
    inserirLDE(lista1, 'O');

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);
    cout << endl << "Tamanho da lista 1: " << comprimento(lista1);
    liberarLDE(lista1);

    LDE <int> lista2;
    int tam = rand()%10 + 5;
    srand(time(NULL));

    inicializarLDE(lista2);
    for( int i=0; i<tam; i++ )
        inserirLDE(lista2, rand()%30 );

    cout << endl << "Lista 2: ";
    mostrarLDE(lista2);
    cout << endl << "Tamanho da lista 2: " << comprimento(lista2);

    liberarLDE(lista2);

    cout << endl;
}
