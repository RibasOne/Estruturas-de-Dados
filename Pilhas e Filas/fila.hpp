#include <iostream>
using namespace std;

template <typename T>
struct Fila{
    T vetor[TAMF];
    int comeco, fim;
};

template <typename T>
void inicializarFila(Fila <T> &f){
    f.comeco = 0;
    f.fim = -1;
}

template <typename T>
bool inserirFila(Fila <T> &f, T valor){
    if( f.fim == TAMF-1 ) return false;
    f.fim++;
    f.vetor[f.fim] = valor;
    return true;
}

template <typename T>
bool retirarFila(Fila <T> &f, T &valor){
    if( f.comeco > f.fim ) return false;
    valor = f.vetor[f.comeco];
    f.comeco++;
    return true;
}

template <typename T>
bool filaVazia(Fila <T> f){
    return (f.comeco > f.fim) ? true : false;
}

template <typename T>
void mostrarFila(char frase[], Fila <T> f){
    T aux;
    cout << frase << ": ";
    while( retirarFila(f, aux) ){
        cout << aux << " ";
    }
    cout << endl;
}
