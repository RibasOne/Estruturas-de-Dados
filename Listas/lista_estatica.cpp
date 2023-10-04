#include <iostream>
using namespace std;
#define MAXTAM 20

/*
    TADS LISTA EST�TICA
*/
struct Lista{
    char vetor[MAXTAM];
    int ultimo;
};

// lista => lista a ser inicializada
void inicializar(Lista &lista){
    lista.ultimo = -1;
}

// lista => lista a ser manipulada
// valor => valor a ser armazenado na lista
// ordem => ordem da inser��o: ''- sem ordem // 'C'-cresc // 'D'-descr
// Retorna true (inser��o OK) ou false (inser��o falhou)
bool inserir(Lista &lista, char valor, char ordem=' '){
    int pos;
    if( lista.ultimo == MAXTAM-1 ) return false;

    switch(ordem){
        case 'C':
            pos=0;
            while( pos <= lista.ultimo && valor > lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        case 'D':
            pos=0;
            while( pos <= lista.ultimo && valor < lista.vetor[pos]) pos++;
            lista.ultimo++;
            for( int i=lista.ultimo; i>pos; i-- )
                lista.vetor[i] = lista.vetor[i-1];
            lista.vetor[pos] = valor;
            break;
        default:
            lista.ultimo++;
            lista.vetor[lista.ultimo] = valor;
            break;
    }
    return true;
}

// lista => lista a ser usada na pesquisa
// valor => valor a ser procurado
// retorna a posi��o do valor ou -1 se n�o achou
int pesquisar(Lista lista, char valor){
}

// lista => lista a ser usada na retirada
// valor => valor a ser retirado
// retorna true (retirada ok) ou false (retirada falhou)
bool retirar(Lista &lista, char valor){
}

// lista => lista a ser usada na retirada
// pos => posicao do valor a ser retirado
// retorna true (retirada ok) ou false (retirada falhou)
bool retirar(Lista &lista, int pos){
}


// Mostrar a lista na tela
void mostrar(Lista lista){
    for( int i=0; i<=lista.ultimo; i++ )
        cout << lista.vetor[i] << "\t";
}
/*
    FIM TADS
*/

int main(){
    Lista l1;

    inicializar(l1);
    inserir(l1, 'P', 'D');
    inserir(l1, 'E', 'D');
    inserir(l1, 'R', 'D');
    inserir(l1, 'N', 'D');
    inserir(l1, 'A', 'D');
    inserir(l1, 'M', 'D');

    cout << endl << "Lista 1: ";
    mostrar(l1);

}
