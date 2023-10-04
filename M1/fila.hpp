#include <iostream>
using namespace std;
#define TAM 50

template <typename T>
struct Fila{
    T vetor[TAM];
    int comeco, fim;
};

template <typename T>
void inicializarFila(Fila <T> &f){
    f.comeco = 0;
    f.fim = -1;
}

template <typename T>
bool inserirFila(Fila <T> &f, T valor){
    if(f.fim < TAM){
        f.fim++;
        f.vetor[f.fim] = valor;
        return true;
    }else
        return false;
}

template <typename T>
bool retirarFila(Fila <T> &f, T &valor){
    if(f.comeco <= f.fim){
        valor = f.vetor[f.comeco];
        f.comeco++;
        return true;
    }else
        return false;
}

// template <typename T>
// void mostrarFila(Fila <T> f){
//     T aux;
//     while(retirarFila(f, aux)){
//         cout << aux << " ";
//     }
//     cout << endl;
// }

template <typename T>
void mostrarFila(Fila <T> f){
    int i=0;
    while(i <= f.fim){
        cout <<"  "<< f.vetor[i];
        i++;
    }
    cout<<endl;
}

template <typename T>
bool filaVazia(Fila <T> &f){
    return (f.comeco > f.fim) ? true : false;
}