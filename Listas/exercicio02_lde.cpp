#include <iostream>
#include "lde.hpp"
using namespace std;

// Testa igualdade em ORDEM, ou seja, na mesma posição
template <typename T>
bool iguais( LDE <T> lista1, LDE <T> lista2 ){
    No <T> *aux1 = lista1.comeco;
    No <T> *aux2 = lista2.comeco;

    while( aux1 != NULL && aux2 != NULL ){
        if( aux1->info != aux2->info ) return false;
        aux1 = aux1->eloP;
        aux2 = aux2->eloP;
    }
    return (aux1 == NULL && aux2 == NULL ) ? true : false;
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

    LDE <char> lista2;

    inicializarLDE(lista2);
    inserirLDE(lista2, 'P');
    inserirLDE(lista2, 'E');
    inserirLDE(lista2, 'R');
    inserirLDE(lista2, 'N');
    inserirLDE(lista2, 'A');
    inserirLDE(lista2, 'M');
    inserirLDE(lista2, 'B');
    inserirLDE(lista2, 'U');
    inserirLDE(lista2, 'C');
    inserirLDE(lista2, 'O');

    LDE <char> lista3;
    inicializarLDE(lista3);
    inserirFinalLDE(lista3, 'P');
    inserirFinalLDE(lista3, 'E');
    inserirFinalLDE(lista3, 'R');
    inserirFinalLDE(lista3, 'N');
    inserirFinalLDE(lista3, 'A');
    inserirFinalLDE(lista3, 'M');
    inserirFinalLDE(lista3, 'B');
    inserirFinalLDE(lista3, 'U');
    inserirFinalLDE(lista3, 'C');
    inserirFinalLDE(lista3, 'O');

    cout << endl << "Lista 1: ";
    mostrarLDE(lista1);
    cout << endl << "Lista 2: ";
    mostrarLDE(lista2);
    cout << endl << "Lista 3: ";
    mostrarLDE(lista3);

    if( iguais(lista1,lista2) )
        cout << endl << "Lista 1 = Lista 2";
    else
        cout << endl << "Lista 1 != Lista 2";
    if( iguais(lista1,lista3) )
        cout << endl << "Lista 1 = Lista 3";
    else
        cout << endl << "Lista 1 != Lista 3";
    if( iguais(lista2,lista3) )
        cout << endl << "Lista 2 = Lista 3";
    else
        cout << endl << "Lista 2 != Lista 3";

    retirarLDE(lista2, 'E');
    cout << endl << "Lista 2: ";
    mostrarLDE(lista2);
    if( iguais(lista1,lista2) )
        cout << endl << "Lista 1 = Lista 2";
    else
        cout << endl << "Lista 1 != Lista 2";
    if( iguais(lista2,lista3) )
        cout << endl << "Lista 2 = Lista 3";
    else
        cout << endl << "Lista 2 != Lista 3";

    liberarLDE(lista1);
    liberarLDE(lista2);
    liberarLDE(lista3);

    cout << endl;
}
