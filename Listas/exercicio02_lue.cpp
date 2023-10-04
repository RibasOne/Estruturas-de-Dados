#include <iostream>
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


// Testa igualdade de elementos, em qualquer posição na lista
template <typename T>
bool iguais( LUE <T> lista1, LUE <T> lista2 ){
    No <T> *aux = lista1.comeco;

    if( comprimento(lista1) != comprimento(lista2) ) return false;
    while( aux != NULL ){
        if( pesquisarLUE(lista2, aux->info) == NULL ) return false;
        aux = aux->elo;
    }
    return true;
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

    LUE <char> lista2;

    inicializarLUE(lista2);
    inserirLUE(lista2, 'P');
    inserirLUE(lista2, 'E');
    inserirLUE(lista2, 'R');
    inserirLUE(lista2, 'N');
    inserirLUE(lista2, 'A');
    inserirLUE(lista2, 'M');
    inserirLUE(lista2, 'B');
    inserirLUE(lista2, 'U');
    inserirLUE(lista2, 'C');
    inserirLUE(lista2, 'O');

    LUE <char> lista3;
    inicializarLUE(lista3);
    inserirFinalLUE(lista3, 'P');
    inserirFinalLUE(lista3, 'E');
    inserirFinalLUE(lista3, 'R');
    inserirFinalLUE(lista3, 'N');
    inserirFinalLUE(lista3, 'A');
    inserirFinalLUE(lista3, 'M');
    inserirFinalLUE(lista3, 'B');
    inserirFinalLUE(lista3, 'U');
    inserirFinalLUE(lista3, 'C');
    inserirFinalLUE(lista3, 'O');

    cout << endl << "Lista 1: ";
    mostrarLUE(lista1);
    cout << endl << "Lista 2: ";
    mostrarLUE(lista2);
    cout << endl << "Lista 3: ";
    mostrarLUE(lista3);

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

    retirarLUE(lista2, 'E');
    cout << endl << "Lista 2: ";
    mostrarLUE(lista2);
    if( iguais(lista1,lista2) )
        cout << endl << "Lista 1 = Lista 2";
    else
        cout << endl << "Lista 1 != Lista 2";
    if( iguais(lista2,lista3) )
        cout << endl << "Lista 2 = Lista 3";
    else
        cout << endl << "Lista 2 != Lista 3";

    liberarLUE(lista1);
    liberarLUE(lista2);
    liberarLUE(lista3);

    cout << endl;
}
