#include <iostream>
#include "lde.hpp"
using namespace std;


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

    cout << endl << "Lista 1 (C): ";
    mostrarLDE(lista1);
    cout << endl << "Lista 1 (D): ";
    mostrarLDE(lista1, 'D');

    cout << endl;
    No <char> *aux = pesquisarLDE(lista1, 'M');
    if( aux == NULL )
        cout << "Informacao nao localizada";
    else
        cout << "Informacao esta na lista";

    retirarLDE(lista1, 'A');
    retirarLDE(lista1, 'U');
    retirarLDE(lista1, 'N');
    retirarLDE(lista1, 'E');
    retirarLDE(lista1, 'R');
    retirarLDE(lista1, 'O');

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);

    retirarLDE(lista1, 'B');
    retirarLDE(lista1, 'C');
    retirarLDE(lista1, 'M');
    retirarLDE(lista1, 'P');

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);

    liberarLDE(lista1);

    cout << endl;
}
