#include <iostream>
#define TAMP 50
#define TAMF 50
#include "pilha.hpp"
#include "fila.hpp"
using namespace std;

bool ehPalindromo(string frase){
    Pilha <char> p;
    Fila <char> f;
    char auxP, auxF;

    inicializarPilha(p);
    inicializarFila(f);

    for( int i=0; i<frase.length(); i++ ){
        if( frase[i] != ' ' ){
            inserirPilha(p, frase[i]);
            inserirFila(f, frase[i]);
        }
    }

    while( retirarPilha(p,auxP) ){
        retirarFila(f, auxF);
        if( auxP != auxF ) return false;
    }
    return true;
}

int main(){
    string frase;

    do{
        cout << "Digite uma frase (fim-terminar): ";
        getline(cin, frase);
        if( frase != "fim" ){
            if( ehPalindromo(frase) )
                cout << "Esta frase eh um palindromo" << endl;
            else
                cout << "Esta frase nao eh um palindromo" << endl;
        }
    }while( frase != "fim" );
    cout << endl;
}
