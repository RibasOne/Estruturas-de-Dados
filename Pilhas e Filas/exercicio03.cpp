#include <iostream>
#define TAMP 50
#define TAMF 50
#include "pilha.hpp"
#include "fila.hpp"
using namespace std;

template <typename T>
void formatar(Fila <T> f, Fila <T> &res){
    Pilha <T> p1, p2;
    T aux;
    int cont;

    inicializarPilha(p1);
    while( retirarFila(f,aux) )
        inserirPilha(p1, aux);

    inicializarPilha(p2);
    if( retirarPilha(p1, aux) )
        inserirPilha(p2,aux);
    else
        inserirPilha(p2, '0');
    if( retirarPilha(p1, aux) )
        inserirPilha(p2,aux);
    else
        inserirPilha(p2, '0');
    inserirPilha(p2, ',');

    if( pilhaVazia(p1) )
        inserirPilha(p2, '0');

    cont = 0;
    while( retirarPilha(p1, aux) ){
        inserirPilha(p2,aux);
        cont++;
        if( cont == 3 ){
            if( !pilhaVazia(p1) ) inserirPilha(p2, '.');
            cont = 0;
        }
    }

    inicializarFila(res);
    while( retirarPilha(p2,aux) )
        inserirFila(res, aux);

}

int main(){
    string numero;
    Fila <char> f, res;

    do{
        cout << "Entre com o numero (sem espaco, pontos e virgula - fim p/ terminar): ";
        getline(cin, numero);

        if( numero != "fim" ){
            inicializarFila(f);
            for( int i=0; i<numero.length(); i++ )
                inserirFila(f, numero[i]);
            formatar(f, res);
            mostrarFila("Resultado", res);
        }

    }while( numero != "fim" );
    cout << endl;
}
