#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
int contFolhas(No <T> *raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    else
        return contFolhas(raiz->esq) + contFolhas(raiz->dir);
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

    cout << "Prefixado: ";
    prefixado(raiz);
    cout << endl<< "Infixado: ";
    infixado(raiz);
    cout << endl << "Posfixado: ";
    posfixado(raiz);
    cout << endl;

    cout << "Numero de nos folhas é: " << contFolhas(raiz);
    cout << endl;
}
