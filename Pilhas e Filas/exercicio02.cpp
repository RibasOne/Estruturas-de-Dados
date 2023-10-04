#include <iostream>
#define TAMP 50
#include "pilha.hpp"
using namespace std;

template <typename T>
void mostrarPilha(char frase[], Pilha <T> p){
    T aux;
    cout << frase << ": ";
    while( retirarPilha(p, aux) ){
        cout << aux << " ";
    }
    cout << endl;
}

template <typename T>
void fatorPrimo( int num, Pilha <T> &p){
    int aux=2;

    inicializarPilha(p);
    while( num > 1 ){
        if( num%aux == 0 ){
            inserirPilha(p, aux);
            num /= aux;
        } else {
            aux++;
        }
    }
}

int main(){
    Pilha <int> p;
    int num;

    do{
        cout << "Entre com o valor (>1): ";
        cin >> num;
    }while( num <= 1 );

    fatorPrimo(num, p);
    mostrarPilha("Pilha", p);

    cout << endl;
}
