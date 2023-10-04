#include <iostream>
#include "abb.hpp"
using namespace std;

template <typename T>
void caminharVetor(No <T> *raiz, T vetor[], int &pos){
    if(raiz == NULL) 
        return;
    caminharVetor(raiz->esq, vetor, pos);
    vetor[pos++] = raiz->info;
    caminharVetor(raiz->dir, vetor, pos);
}

template <typename T>
bool testarIguais(No <T> *raiz1, No <T> *raiz2){
    int tam1 = contar(raiz1);
    int tam2 = contar(raiz2);
    if(tam1 != tam2) return false;

    T *vetor1 = new T[tam1];
    T *vetor2 = new T[tam2];
    int pos1 = 0, pos2 = 0;

    caminharVetor(raiz1, vetor1, pos1);
    caminharVetor(raiz2, vetor2, pos2);

    for(int i=0; i<pos1; i++){
        if(vetor1[i] != vetor2[i]) 
            return false;
    }
    return true;
}

int main(){
    No <char> *raiz1 = NULL;
    inserir(raiz1, 'P');
    inserir(raiz1, 'E');
    inserir(raiz1, 'R');
    inserir(raiz1, 'N');
    inserir(raiz1, 'A');
    inserir(raiz1, 'M');
    inserir(raiz1, 'B');
    inserir(raiz1, 'U');
    inserir(raiz1, 'C');
    inserir(raiz1, 'O');

    No <char> *raiz2 = NULL;
    inserir(raiz2, 'R');
    inserir(raiz2, 'U');
    inserir(raiz2, 'C');
    inserir(raiz2, 'O');
    inserir(raiz2, 'N');
    inserir(raiz2, 'A');
    inserir(raiz2, 'M');
    inserir(raiz2, 'B');
    inserir(raiz2, 'P');
    inserir(raiz2, 'E');

    No <char> *raiz3 = NULL;
    inserir(raiz3, 'C');
    inserir(raiz3, 'O');
    inserir(raiz3, 'M');
    inserir(raiz3, 'P');
    inserir(raiz3, 'U');
    inserir(raiz3, 'T');
    inserir(raiz3, 'A');
    inserir(raiz3, 'R');
    inserir(raiz3, 'X');
    inserir(raiz3, 'D');

    if( testarIguais(raiz1, raiz2) )
        cout << "Arvore 1 e 2 sao iguais" << endl;
    else
        cout << "Arvore 1 e 2 sao diferentes" << endl;
    if( testarIguais(raiz2, raiz3) )
        cout << "Arvore 2 e 3 sao iguais" << endl;
    else
        cout << "Arvore 2 e 3 sao diferentes" << endl;

    cout << endl;
}

