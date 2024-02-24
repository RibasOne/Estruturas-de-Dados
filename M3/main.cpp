/*
-> Disciplina: Estruturas de Dados
-> Programa: Analise Comparativa de Estrategias de Ordenacao
-> Atividade M3
-> Alunos: - Cauã Ribas
           - Nilson Andrade
*/
#include <iostream>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <float.h>

using namespace std;

void bubblesort(int v[], int tam){
    int temp;

    for(int i = 0; i < tam - 1; i++){
        for(int j = 1; j < tam; j++){
            if( v[j-1] > v[j] ){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }
}

void insertionsort(int v[], int tam){
    int chave, i;
    for(int j = 1; j <= tam - 1; j++){
        chave = v[j];
        i = j - 1;
        while(i >= 0 && v[i] > chave){
            v[i + 1] = v[i];
            i = i - 1;
        }
        v[i+1] = chave;
    }
}

void merge(int vetor[], int comeco, int meio, int fim){
    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int *vetAux = new int[tam];

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    for(comAux = comeco; comAux <= fim; comAux++){
        vetor[comAux] = vetAux[comAux-comeco];
    }
    delete []vetAux;
}

void mergesort(int v[], int inicio, int fim){
    if(inicio == fim) return;

    int meio = (inicio + fim) / 2;
    mergesort(v, inicio, meio);
    mergesort(v, meio + 1, fim);
    merge(v, inicio, meio, fim);
}

void selectionsort(int v[], int tam){
    int pos_menor, temp;

    for(int i = 0; i < tam - 1; i++){
        pos_menor = i;
        for(int j = i + 1; j < tam; j++){
            if(v[j] < v[pos_menor]) pos_menor = j;
        }
        temp = v[i];
        v[i] = v[pos_menor];
        v[pos_menor] = temp;
    }
}

void Shell(int v[], int r, int s, int n){
    int i, j, k, temp;
    bool achei;

    for(i = s + r; i < n; i += r){
        j = s;
        achei = false;
        while(j < i && !achei){
            if(v[i] < v[j]) achei = true;
            else j = j + r;
        }
        if(achei){
            temp = v[i];
            k = i - r;
            while(k > j - r){
                v[k + r] = v[k];
                k = k - r;
            }
            v[j] = temp;
        }
    }
}
void shellsort(int v[], int tam, int grupo){
    int part = 0;
    if(grupo == 4 || grupo == 6) 
        part = 2;
    else if(grupo == 8) 
        part = 3;

    if(grupo == 6) {
        int inc = 6;
        do{
            for(int j = 0; j <= inc; j++) {
                Shell(v, inc, j, tam);
            }
            inc /= 2;
        }while (inc != 0);
    }else {
        for(int i = part; i >= 0; i--) {
            int inc = pow(2,i);
            for(int j = 0; j <= inc; j++) {
                Shell(v, inc, j, tam);
            }
        }
    }
}

int calcular_mediana(int vetor[], int esq, int dir, int meio){
    if((vetor[esq] <= vetor[meio] && vetor[meio] <= vetor[dir]) || (vetor[dir] <= vetor[meio] && vetor[meio] <= vetor[esq]))
        return meio;
    else if((vetor[meio] <= vetor[esq] && vetor[esq] <= vetor[dir]) || (vetor[dir] <= vetor[esq] && vetor[esq] <= vetor[meio]))
        return esq;
    else
        return dir;
}

int escolher_pivo(int vetor[], int esq, int dir, string pivo){
    int meio = (esq + dir) / 2;
    if(pivo == "meio")
        return vetor[meio];
    else if(pivo == "primeiro")
        return vetor[esq];
    else if(pivo == "ultimo")
        return vetor[dir];
    else if(pivo == "mediana")
        return vetor[calcular_mediana(vetor, esq, dir, meio)];
    else
        return vetor[meio];
}

void quicksort(int vetor[], int esq, int dir, string pivo){
    int x, i, j, aux;
    i = esq;
    j = dir;
    x = escolher_pivo(vetor, esq, dir, pivo);

    do{
        while (x > vetor[i])
            i = i + 1;

        while (x < vetor[j])
            j = j - 1;

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while (i <= j);
    if (esq < j)
        quicksort(vetor, esq, j, pivo);
    if (dir > i)
        quicksort(vetor, i, dir, pivo);
}

void preencher_aleatorio(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
        vetor[i] = rand() % tam;
}

void preencher_decrescente(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++) {
        vetor[i] = (tam - 1) - i;
    }
}

void preencher_crescente(int vetor[], int tam)
{
    for(int i = 0; i < tam; i++)
        vetor[i] = i;
}

void ordenar(int vetor[], int numero_execucoes, int numero_particoes, int tam, char opcao_ordenacao, string caso, string pivo){
    chrono::high_resolution_clock::time_point inicio, fim;
    chrono::duration<double> duracao;
    double total = 0;
    double melhor_caso = DBL_MAX;
    double pior_caso = DBL_MIN;

    for(int i = 0; i < numero_execucoes; i++){
        int vetor_copia[tam];
        copy(vetor, vetor + tam, vetor_copia);

        inicio = chrono::high_resolution_clock::now();

        // Chama a função de ordenação correspondente

        switch (opcao_ordenacao)
        {
            case 'B':
                bubblesort(vetor_copia, tam);
                break;
            case 'I':
                insertionsort(vetor_copia, tam);
                break;
            case 'S':
                shellsort(vetor_copia, tam, numero_particoes);
                break;
            case 'M':
                mergesort(vetor_copia, 0, tam - 1);
                break;
            case 'Q':
                quicksort(vetor_copia, 0, tam - 1, pivo);
                break;
            case '2':
                selectionsort(vetor_copia, tam);
                break;
            default:
                exit(0);
        }

        fim = chrono::high_resolution_clock::now();
        duracao = chrono::duration_cast<std::chrono::duration<double>>(fim - inicio);
        total += duracao.count();

        // Atualiza o melhor e pior caso
        if(duracao.count() < melhor_caso){
            melhor_caso = duracao.count();
        }
        if(duracao.count() > pior_caso){
            pior_caso = duracao.count();
        }
    }

    double media = total / numero_execucoes;

    cout << fixed << setprecision(15);
    if(caso == "melhor"){
        cout << melhor_caso << endl;
    }else if(caso == "medio"){
        cout << media << endl;
    }else{
        cout << pior_caso << endl;
    }
}

int main()
{
    int numero_execucoes, numero_particoes, tam, input_opcao;
    string pivo;

    while(true)
    {
        system("cls");

        cout << "<============================================================>";
        cout << "\nPrograma de Analise Comparativa de Estrategias de Ordenacao";
        cout << "\n\n|-->(1) Bubble Sort";
        cout << "\n|-->(2) Insertion Sort";
        cout << "\n|-->(3) Shellsort";
        cout << "\n|-->(4) Mergesort";
        cout << "\n|-->(5) Quicksort";
        cout << "\n|-->(6) Selection Sort";
        cout << "\n\n<============================================================>\n";
        cout << "Opcao: ";
        cin >> input_opcao;

        do{
            cout << "Digite o tamanho do vetor: ";
                cin >> tam;
        }while(tam < 10);

        do{
            cout << "Digite o numero de execucoes dos algoritmos: ";
            cin >> numero_execucoes;
        }while(numero_execucoes < 1);

        cout << "\nInicializando....Executando...." << endl;
        
        int vetor[tam];

        // Bubble Sort
        if(input_opcao == 1){
            cout << "\nFuncao: Bubble Sort\n";

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'B', "melhor", "\0");

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'B', "medio", "\0");

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'B', "pior", "\0");

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        }

        // Insertion Sort
        if(input_opcao == 2){
            cout << "\nFuncao: Insertion Sort\n";

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'I', "melhor", "\0");

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'I', "medio", "\0");

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'I', "pior", "\0");

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        }

        // Shellsort
        if(input_opcao == 3){
            cout << "\nFuncao: Shell Sort\n";

            do{
                cout << "\nDigite o numero de particoes do algoritmo shellsort[4-6-8]: ";
                cin >> numero_particoes;
            }while(numero_particoes != 4 && numero_particoes != 6 && numero_particoes != 8);

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, numero_particoes, tam, 'S', "melhor", "\0");

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, numero_particoes, tam, 'S', "medio", "\0");

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, numero_particoes, tam, 'S', "pior", "\0");

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        }

        // Mergesort
        if(input_opcao == 4){
            cout << "\nFuncao: Merge Sort\n";

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'M', "melhor", "\0");

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'M', "medio", "\0");

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'M', "pior", "\0");

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        }

        // Quicksort
        if(input_opcao == 5){
            do{
                cout << "\nDigite qual elemento voce deseja usar como pivo para o algoritmo quicksort[meio-primeiro-ultimo-mediana]: ";
                cin >> pivo;
            }while(pivo != "meio" && pivo != "primeiro" && pivo != "ultimo" && pivo != "mediana");

            cout << "\nFuncao: Quicksort\n";

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'Q', "melhor", pivo);

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'Q', "medio", pivo);

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, 'Q', "pior", pivo);

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        }

        // Selection Sort
        if(input_opcao == 6){
            cout << "\nFuncao: Selection Sort\n";

            preencher_crescente(vetor, tam);
            cout << "\nMelhor caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, '2', "melhor", "\0");

            preencher_aleatorio(vetor, tam);
            cout << "Media dos casos: ";
            ordenar(vetor, numero_execucoes, 0, tam, '2', "medio", "\0");

            preencher_decrescente(vetor, tam);
            cout << "Pior caso: ";
            ordenar(vetor, numero_execucoes, 0, tam, '2', "pior", "\0");

            cin.ignore();
            cout << "\nPrecione a tecla Enter para continuar...\n";
            cin.get();
        } 
    }
    return 0;
}