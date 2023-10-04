#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No *esq=NULL, *dir=NULL;
};

template <typename T>
bool inserir( No <T> *&raiz, T valor ){
    if( raiz == NULL ){
        raiz = new No <T>;
        raiz->info = valor;
        return true;
    }
    if( raiz->info == valor ) return false;
    if( valor < raiz->info )
        return inserir(raiz->esq, valor);
    else
        return inserir(raiz->dir, valor);
}

template <typename T>
T buscar_maior( No <T> *raiz ){
    if( raiz->dir != NULL )
        return buscar_maior(raiz->dir);
    else
        return raiz->info;
}

template <typename T>
T buscar_menor( No <T> *raiz ){
    if( raiz->esq != NULL )
        return buscar_menor(raiz->esq);
    else
        return raiz->info;
}

template <typename T>
bool retirar( No <T> *&raiz, T valor ){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ){
        No <T> *aux = raiz;
        if( raiz->esq == NULL && raiz->dir == NULL ){ // Caso A
            raiz = NULL;
            delete aux;
            return true;
        }
        if( raiz->esq == NULL && raiz->dir != NULL ){ // Caso B - parte I
            raiz = raiz->dir;
            delete aux;
            return true;
        }
        if( raiz->esq != NULL && raiz->dir == NULL ){ // Caso B - parte II
            raiz = raiz->esq;
            delete aux;
            return true;
        }
        // caso C
        T info_aux = buscar_maior(raiz->esq);
        raiz->info = info_aux;
        return retirar(raiz->esq, info_aux);
    }
    if( valor < raiz->info )
        return retirar(raiz->esq, valor);
    else
        return retirar(raiz->dir, valor);
}

template <typename T>
void prefixado(No <T> *raiz){
    if( raiz == NULL ) return;
    cout << raiz->info << " ";
    prefixado(raiz->esq);
    prefixado(raiz->dir);
}

template <typename T>
void infixado(No <T> *raiz){
    if( raiz == NULL ) return;
    infixado(raiz->esq);
    cout << raiz->info << " ";
    infixado(raiz->dir);
}

template <typename T>
void posfixado(No <T> *raiz){
    if( raiz == NULL ) return;
    posfixado(raiz->esq);
    posfixado(raiz->dir);
    cout << raiz->info << " ";
}

template <typename T>
void liberar(No <T> *raiz){
    if( raiz == NULL ) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

template <typename T>
bool pesquisar(No <T> *raiz, T valor){
    if( raiz == NULL ) return false;
    if( raiz->info == valor ) return true;
    if( valor < raiz->info )
        return pesquisar(raiz->esq, valor);
    else
        return pesquisar(raiz->dir, valor);
}