#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
void mostrar(No <T> *raiz, T a, T b){
    if(raiz == NULL) 
        return;
    mostrar(raiz->esq, a, b);
    if(a <= raiz->info && raiz->info <= b) 
        cout << raiz->info << " ";
    mostrar(raiz->dir, a, b);
}

int main(){
    No <char> *raiz = NULL;

    inserir(raiz, 'P');
    inserir(raiz, 'E');
    inserir(raiz, 'R');
    inserir(raiz, 'N');
    inserir(raiz, 'A');
    inserir(raiz, 'M');
    inserir(raiz, 'B');
    inserir(raiz, 'U');
    inserir(raiz, 'C');
    inserir(raiz, 'O');

    cout << "Mostrar: ";
    mostrar(raiz, 'D', 'O');

    cout << endl;
}
