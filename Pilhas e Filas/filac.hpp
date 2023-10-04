#include <iostream>
using namespace std;

template <typename T>
struct FilaC{
    T vetor[TAMF];
    int comeco, fim, cont;
};

template <typename T>
void inicializarFila(FilaC <T> &f){
    f.comeco = 0;
    f.fim = -1;
    f.cont = 0;
}

template <typename T>
bool inserirFilaC(FilaC <T> &f, T valor){
    if( f.cont == TAMF ) return false;
    f.fim = (f.fim ==  TAMF-1) ? 0 : f.fim+1;
    f.vetor[f.fim] = valor;
    f.cont++;
    return true;
}

template <typename T>
bool retirarFilaC(FilaC <T> &f, T &valor){
    if( f.cont == 0 ) return false;
    valor = f.vetor[f.comeco];
    f.comeco = (f.comeco == TAMF-1) ? 0 : f.comeco+1;
    f.cont--;
    return true;
}

template <typename T>
bool filaVazia(FilaC <T> f){
    return (f.cont == 0) ? true : false;
}

template <typename T>
void mostrarFilaC(char frase[], FilaC <T> f){
    T aux;
    cout << frase << ": ";
    while( retirarFilaC(f, aux) ){
        cout << aux << " ";
    }
    cout << endl;
}
