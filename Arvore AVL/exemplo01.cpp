#include <iostream>
#include "avl.hpp"
using namespace std;

int main(){
    No <char> *raiz = NULL;

    raiz = inserir(raiz, 'P');
    raiz = inserir(raiz, 'E');
    raiz = inserir(raiz, 'A');

    cout << "Prefixado: ";
    prefixado(raiz);
    cout << endl << "Infixado: ";
    infixado(raiz);
    cout << endl<< "Posfixado: ";
    posfixado(raiz);

    cout << endl;
}
