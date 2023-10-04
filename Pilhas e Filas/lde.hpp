#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No *eloA, *eloP;
};

template <typename T>
struct LDE{
    No <T> *comeco;
    No <T> *fim;
};

//
// Inicializa a lista dada por parâmetro
//
template <typename T>
void inicializarLDE(LDE <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

//
// Mostra todo o conteúdo da lista na tela
//
template <typename T>
void mostrarLDE(LDE <T> lista, char ordem='C'){
    No <T> *aux;

    aux = (ordem == 'C') ? lista.comeco : lista.fim;
    while( aux != NULL ){
        cout << aux->info << " ";
        aux = (ordem == 'C') ? aux->eloP : aux->eloA;
    }
    if( lista.comeco == NULL ) cout << "<Vazio>";
}

//
// Insere o valor na lista dada respeitando a ordem crescente
//
template <typename T>
bool inserirLDE(LDE <T> &lista, T valor){
    No <T> *novo;

    // Criar o novo no
    novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    // Lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    // Inserção no comeco
    if( valor <= lista.comeco->info ){
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
        return true;
    }

    // Inserção no final
    if( valor >= lista.fim->info ){
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
        return true;
    }

    // Inserir no meio
    No <T> *ant = lista.comeco;
    while( ant->info < valor && ant->eloP->info <= valor )
        ant = ant->eloP;
    No <T> *prox = ant->eloP;

    novo->eloA = ant;
    novo->eloP = prox;
    ant->eloP = novo;
    prox->eloA = novo;
    return true;
}

//
// Insere o valor dado sempre no final da lista
//
template <typename T>
bool inserirFinalLDE(LDE <T> &lista, T valor){
    No <T> *novo;

    // Criar o novo no
    novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->eloA = NULL;
    novo->eloP = NULL;

    // Lista vazia
    if( lista.comeco == NULL ){
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    lista.fim->eloP = novo;
    novo->eloA = lista.fim;
    lista.fim = novo;
    return true;
}

//
// Pesquisar se o valor está na lista
// retornar o endereço do valor ou nulo se não estiver
//
template <typename T>
No <T> * pesquisarLDE(LDE <T> lista, T valor){
    No <T> *aux = lista.comeco;

    while( aux != NULL ){
        if( aux->info == valor ) return aux;
        aux = aux->eloP;
    }
    return NULL;
}

//
// Retirar o valor da lista
// retornar verdadeiro ou false se não achar
//
template <typename T>
bool retirarLDE(LDE <T> &lista, T valor ){
    No <T> *aux, *anterior, *proximo;

    aux = pesquisarLDE(lista, valor);

    if( aux == NULL ) return false;
    anterior = aux->eloA;
    proximo = aux->eloP;


    if( aux == lista.comeco ){ // Casos 1 e 2
        lista.comeco = proximo;
        if( aux == lista.fim ) lista.fim = NULL;
        else proximo->eloA = NULL;
    } else { // Casos 3 e 4
        anterior->eloP = aux->eloP;
        if( aux == lista.fim ) lista.fim = anterior;
        else proximo->eloA = anterior;
    }
    delete aux;
    return true;
}

//
// Libera toda a memória alocada para a lista fornecida
//
template <typename T>
void liberarLDE(LDE <T> &lista){
    No <T> *aux = lista.comeco;
    No <T> *aux2;

    while( aux != NULL ){
        aux2 = aux->eloP;
        delete aux;
        aux = aux2;
    }
}

