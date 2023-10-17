#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    int altura=1;
    No *esq=NULL, *dir=NULL;
};

template <typename T>
int getAltura(No <T> *raiz){
    return (raiz==NULL) ? 0 : raiz->altura;
}

template <typename T>
int calcularAltura(No <T> *raiz){
    int altE = getAltura(raiz->esq);
    int altD = getAltura(raiz->dir);
    return (altE>altD) ? altE+1 : altD+1;
}

template <typename T>
No <T> * RotacaoSimplesDireita(No <T> *k){
    No <T> *x = k->esq;
    No <T> *t2 = x->dir;

    x->dir = k;
    k->esq = t2;
    k->altura = calcularAltura(k);
    x->altura = calcularAltura(x);
    return x;
}

template <typename T>
No <T> * RotacaoDuplaDireita(No <T> *k){
}

template <typename T>
No <T> * RotacaoSimplesEsquerda(No <T> *k){
}

template <typename T>
No <T>* RotacaoDuplaEsquerda(No <T> *k){
}

template <typename T>
No <T> * aplicarRotacao(No <T> *k){
    if( getAltura(k->esq) > getAltura(k->dir) ){ // Rotação a direita
        No <T> *x = k->esq;
        if( getAltura(x->esq) >= getAltura(x->dir) )
            return RotacaoSimplesDireita(k);
        else
            return RotacaoDuplaDireita(k);
    } else { // rotacao a esquerda
        No <T> *y = k->dir;
        if( getAltura(y->dir) >= getAltura(y->esq) )
            return RotacaoSimplesEsquerda(k);
        else
            return RotacaoDuplaEsquerda(k);
    }
}

template <typename T>
No <T> * inserir( No <T> *&raiz, T valor ){
    if( raiz == NULL ){
        raiz = new No <T>;
        raiz->info = valor;
        return raiz;
    }
    if( raiz->info == valor ) return NULL;
    if( valor < raiz->info )
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    int altE = getAltura(raiz->esq);
    int altD = getAltura(raiz->dir);
    if( (altE-altD == 2) || (altE-altD == -2) )
        raiz = aplicarRotacao(raiz);
    raiz->altura = calcularAltura(raiz);
    return raiz;
}

template <typename T>
T buscar_maior( No <T> *raiz ){
    if( raiz->dir != NULL )
        return buscar_maior(raiz->dir);
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

template <typename T>
int contar(No <T> *raiz){
    if( raiz == NULL ) return 0;
    return 1 + contar(raiz->esq) + contar(raiz->dir);
}

template <typename T>
int altura( No <T> *raiz ){
    if( raiz == NULL ) return 0;
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    return (altE > altD) ? altE+1 : altD+1;
}

template <typename T>
void mostrar_arvore(No  <T> *raiz, int tab ){
    cout << endl;
    for( int i=0; i<tab; i++ ) cout << " ";
    if( raiz == NULL ){
        cout << "*";
        return;
    }
    cout << raiz->freq << "(" << raiz->ch << ")";
    mostrar_arvore( raiz->esq, tab+3 );
    mostrar_arvore( raiz->dir, tab+3 );
}
