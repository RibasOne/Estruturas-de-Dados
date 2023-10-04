#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
bool checkABB(No <T> *raiz){
    if(raiz == NULL)
        return true;
    if(raiz->esq != NULL && buscar_maior(raiz->esq) > raiz->info)
        return false;
    if(raiz->dir != NULL && buscar_menor(raiz->dir) < raiz->info)
        return false;
    if(!checkABB(raiz->esq) || !checkABB(raiz->dir))
        return false;
    return true;
}

int main(){
    No <int> *raiz = NULL;
    inserir(raiz, 3);
    inserir(raiz, 2);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 1);
    inserir(raiz, 4);
    
    if(checkABB(raiz))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    liberar(raiz);
}
