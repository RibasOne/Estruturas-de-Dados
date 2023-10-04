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
void intercalar(Pilha <T> pA, Pilha <T> pB, Pilha <T> &res){
    bool stA, stB;
    T auxA, auxB;

    inicializarPilha(res);

    stA = retirarPilha(pA, auxA);
    stB = retirarPilha(pB, auxB);
    while( stA == true || stB == true ){
        if( stA == true && stB == true ){ // Conseguiu das duas
            if( auxA < auxB ){
                inserirPilha(res, auxA);
                stA = retirarPilha(pA, auxA);
            } else {
                inserirPilha(res, auxB);
                stB = retirarPilha(pB, auxB);
            }
        } else {
            if( stA == true ){ // Conseguiu da primeira
                inserirPilha(res, auxA);
                stA = retirarPilha(pA, auxA);
            }
            if( stB == true ){ // Conseguiu da segunda
                inserirPilha(res, auxB);
                stB = retirarPilha(pB, auxB);
            }
        }
    }
}

int main(){
    Pilha <int> p1, p2, p3;

    inicializarPilha(p1);
    inicializarPilha(p2);

    inserirPilha(p1, 30);
    inserirPilha(p1, 25);
    inserirPilha(p1, 20);
    inserirPilha(p1, 15);
    inserirPilha(p1, 10);
    inserirPilha(p1, 5);

    inserirPilha(p2, 18);
    inserirPilha(p2, 9);
    inserirPilha(p2, 4);
    inserirPilha(p2, 3);

    intercalar( p1, p2, p3 );
    mostrarPilha("Pilha 3", p3);

    cout << endl;
}
