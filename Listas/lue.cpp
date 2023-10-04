#include <iostream>
#include "lue.hpp"
using namespace std;

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

    cout << endl;
    No <char> *aux = pesquisarLUE(lista1, 'M');
    if( aux == NULL )
        cout << "Informacao nao localizada";
    else
        cout << "Informacao esta na lista";

    retirarLUE(lista1, 'A');
    retirarLUE(lista1, 'U');
    retirarLUE(lista1, 'N');
    retirarLUE(lista1, 'E');
    retirarLUE(lista1, 'R');
    retirarLUE(lista1, 'O');

    cout << endl << "Lista 1: ";
    mostrarLUE(lista1);

    retirarLUE(lista1, 'B');
    retirarLUE(lista1, 'C');
    retirarLUE(lista1, 'M');
    retirarLUE(lista1, 'P');

    cout << endl << "Lista 1: ";
    mostrarLUE(lista1);

    liberarLUE(lista1);

    cout << endl;
}
