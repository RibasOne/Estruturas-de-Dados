#include <iostream>
using namespace std;
#define TAM 50

template <typename T>
struct Pilha{
    T vetor[TAM];
    int topo;
};

template <typename T>
void inicializarPilha(Pilha <T> &p){
    p.topo = -1;
}

template <typename T>
bool inserirPilha(Pilha <T> &p, T valor){
    if(p.topo < TAM){
        p.topo++;
        p.vetor[p.topo] = valor;
        return true;
    }else
        return false;
}

template <typename T>
bool retirarPilha(Pilha <T> &p, T &valor){
    if(p.topo >= 0){
        valor = p.vetor[p.topo];
        p.topo--;
        return true;
    }else
        return false;
}

// template <typename T>
// void mostrarPilha(Pilha <T> p){
//     T aux;
//     while(retirarPilha(p, aux)){
//         cout << aux << " ";
//     }
//     cout << endl;
// }

template <typename T>
void mostrarPilha(Pilha <T> p){
    int i = 0;
    while(i <= p.topo){
        cout <<"  "<< p.vetor[i];
        i++;
    }
    cout<<endl;
}

template <typename T>
bool pilhaVazia(Pilha <T> &p){
    return (p.topo == -1) ? true : false;
}