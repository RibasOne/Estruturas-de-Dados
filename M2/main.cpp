/*
-> Disciplina: Estruturas de Dados
-> Programa: Receber um texto qualquer, comprimir e descomprimir usando o Algoritmo de Huffman, verificando a fidelidade com o texto original.
-> Atividade M2
-> Alunos: - Cauã Ribas
           - Nilson Andrade
*/

#include <iostream>
#include <fstream>
#include "auxiliar.hpp"

using namespace std;

template <typename T>
void construirArvoreHuffman(LUE <T> &lista, string texto){
    int tabelaFrequencias[256] = {0}; // Inicializa uma tabela de frequências para cada caractere possível (0-255)

    // Contar a frequência de cada caractere no texto
    for(char c : texto){
        tabelaFrequencias[c]++; // A cada iteração, incrementa a contagem de frequência do caractere 'c' na tabela
    }

    // Inserir na LUE
    for(int i = 0; i < 256; i++){
        if(tabelaFrequencias[i] > 0){
            NoArvore <T> *raiz = new NoArvore <T>;
            raiz->infoA = char(i); // Atribui o caractere correspondente ao valor inteiro 'i' ao campo 'infoA'
            raiz->frequencia = tabelaFrequencias[i];
            inserirLUE(lista, raiz);
        }
    }

    // Agrupar Nós
    while(lista.comeco && lista.comeco->elo){ // Percorre a lista enquanto não estiver vazia e houver mais de um nó na lista
        NoArvore <T> *menorIndex1 = lista.comeco->info;
        NoArvore <T> *menorIndex2 = lista.comeco->elo->info;
        NoLUE <T> *aux1 = lista.comeco;
        NoLUE <T> *aux2 = lista.comeco->elo;

        if(lista.comeco->elo->elo){ // Verifica se há pelo menos dois elementos na lista
            lista.comeco = lista.comeco->elo->elo; // Se houver dois elementos, avança o ponteiro em duas posições
        }else{
            lista.comeco = NULL; // Se não houver pelo menos dois elementos, define o ponteiro como NULL para sair do loop
        }

        // Deleta os dois menores elementos da lista
        delete aux1;
        delete aux2;

        // Cria um novo nó que combina os dois elementos menores
        NoArvore <T> *novaRaiz = new NoArvore <T>;
        novaRaiz->infoA = '\0'; 
        novaRaiz->frequencia = menorIndex1->frequencia + menorIndex2->frequencia;
        novaRaiz->esq = menorIndex1;
        novaRaiz->dir = menorIndex2;

        // Insere o novo nó de volta na lista
        inserirLUE(lista, novaRaiz);
    }
}

template <typename T>
bool comprimirTexto(NoArvore <T> *raiz, char c, string &caminho){
    if(raiz == NULL){ // Se a raiz for nula, não há caminho a seguir
        caminho = ""; // Definimos o caminho como vazio e retornamos falso.
        return false;
    }
    if(raiz->infoA != '\0'){ // Se for uma folha (caractere), verifica se é o caractere desejado
        if(raiz->infoA == c)
            return true;
        return false;
    }
    if(comprimirTexto(raiz->esq, c, caminho)){ // Recursivamente busca à esquerda (0)
        caminho = "0" + caminho;
        return true;
    }
    if(comprimirTexto(raiz->dir, c, caminho)){ // Recursivamente busca à esquerda (0)
        caminho = "1" + caminho;
        return true;
    }
    return false;
}

template <typename T>
void gerarMapeamentoBits(LUE <T> lista, string &texto, string &codificado){ // codificado = mapa
    NoArvore <T> *arvore = lista.comeco->info; // Obtém a raiz da árvore de Huffman.
    codificado = "";
    for (char c : texto){ // Itera pelos caracteres do texto original.
        string binario = "";
        comprimirTexto(arvore, c, binario);
        codificado += binario;
    }
}

template <typename T>
string descomprimirTexto(NoArvore <T> *raiz, const string &textoComprimido){
    NoArvore <T> *arvore = raiz;
    string textoDescomprimido;

    for(char bit : textoComprimido){ // Itera pelos bits do texto codificado.
        if(bit == '0'){
            arvore = arvore->esq; 
        }else if(bit == '1'){
            arvore = arvore->dir;
        }
        
        if(arvore->esq == NULL && arvore->dir == NULL){
            textoDescomprimido += arvore->infoA; 
            arvore = raiz; // Reinicia a busca na raiz da árvore
        }
    }
    return textoDescomprimido;
}

int main(){

    LUE <char> lista;
    inicializarLUE(lista);

    int inputOpcao;
    string texto;

    do{
        system("cls");

        cout << "====================================================";
        cout << "\n\t\tHuffman-Coding-Program";
        cout << "\n\n1. Inserir um texto: ";
        cout << "\n2. Ler um arquivo: ";
        cout << "\n3. Sair";
        cout << "\n\n====================================================\n";

        cout << "Opcao: ";
        cin >> inputOpcao;

        if(inputOpcao == 1){

            cout << "Digite o texto de entrada: ";
            cin.ignore();
            getline(cin, texto);

            // Construir a Arvore de Huffman
            construirArvoreHuffman(lista, texto);

            // Gerar a Sequencia de Bits
            string codificado;
            gerarMapeamentoBits(lista, texto, codificado);

            cout << "\nSequencia de bits: ";
            cout << "\n" << codificado << endl;

            // Descomprimir texto original
            string textoDescomprimido = descomprimirTexto(lista.comeco->info, codificado);
            cout << "\nTexto descomprimido: \n" << textoDescomprimido << endl;

            texto = ""; // Esvazia a string

            cout << "\nPrecione Enter para continuar..." << endl;
            cin.get();
        }
        else if(inputOpcao == 2){
            string name;
            string linha;
            fstream arquivo;
    
            cout << "Por favor digite o nome do seu arquivo: ";
            cin.ignore();
            getline(cin, name);

            arquivo.open(name, fstream :: in | fstream :: app);

            if(arquivo.is_open()){
                while(getline(arquivo, linha)){
                texto += linha;
                }
            }

            cout << "\nTexto de entrada: \n";
            cout << texto << endl;

            // Construir a Arvore de Huffman
            construirArvoreHuffman(lista, texto);

            // Gerar a Sequencia de Bits
            string codificado;
            gerarMapeamentoBits(lista, texto, codificado);

            cout << "\nSequencia de bits: ";
            cout << "\n" << codificado << endl;

            // Descomprimir texto original
            string textoDescomprimido = descomprimirTexto(lista.comeco->info, codificado);
            cout << "\nTexto descomprimido: \n" << textoDescomprimido;

            texto = ""; // Esvazia a string

            cout << "\nPrecione Enter para continuar..." << endl;
            cin.get();
        }
        else if(inputOpcao == 3){
            cout << "Saindo...";
            liberarLUE(lista);
            liberarArvore(lista.comeco->info);
        }
        else{
            cout << "Opcao invalida!";
            cout << "\nPrecione Enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            
        }

    }while(inputOpcao != 3);

    return 0;
}