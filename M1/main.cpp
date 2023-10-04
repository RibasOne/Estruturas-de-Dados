#include <iostream>
#include <math.h>
#include "fila.hpp"
#include "pilha.hpp"

using namespace std;
#define TAM 50

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return (c == '+' || c == '-' || c== '^' || c == '*' || c == '/');
}

//Função para calcular a notação polonesa
template <typename T>
bool calcularNPR(Fila <T> &f, Pilha <T> &p) {   
    char aux;
    retirarFila(f, aux);

    // if para insira na pilha diretamente caso for um digito
    if (isdigit(aux)) {
        inserirPilha(p, aux); 
        return true;
    } 
    // else if caso for uma variável (letra), insira seu valor na pilha
    else if (isalpha(aux)) {
        char valor;
        cout << "\nAdicione o valor de " << aux << ": ";
        cin >> valor;
        inserirPilha(p, valor); 
        return true;
    } 
    //else if para calcular e transforma char em int 
    else if (isOperator(aux)) {
        char auxOperating2;
        char auxOperating1;
        retirarPilha(p, auxOperating2); 
        retirarPilha(p, auxOperating1); 

        // Converte os operandos de char para int
        auxOperating2 = auxOperating2 - '0';
        auxOperating1 = auxOperating1 - '0';

        int resultado;
        // Realiza a operação de acordo com o operador
        if (aux == '+')
            resultado = auxOperating1 + auxOperating2;
        else if (aux == '-')
            resultado = auxOperating1 - auxOperating2;
        else if (aux == '*')
            resultado = auxOperating1 * auxOperating2;
        else if (aux == '/')
            resultado = auxOperating1 / auxOperating2;
        else if (aux == '^')
            resultado = pow(auxOperating1, auxOperating2);

        // if se o resultado tiver mais de dois digitos
        if (resultado >= 10) {
            string resultadoStr = to_string(resultado);
            for (char c : resultadoStr)
                inserirPilha(p, c);
        } 
        // else if Se o resultado for negativo
        else if (resultado < 0) {
            string resultadoStr = to_string(resultado);
            for (char c : resultadoStr)
                inserirPilha(p, c); 
        }
        //se o resultado tiver apenas um digito
         else {
            char converter = resultado + '0';
            inserirPilha(p, converter); 
        }

        return true;
    }
    return false; 
}

//Função bool para verificar se os parenteses estão corretos.
bool verificarParenteses(char a, char b){
    if(a == '(' && b == ')') return true;
    return false;
}

//Função para ordenar os caracteres e verificar os operadores
template <typename T>
int ordenarOp(T b, Pilha<T> p) {
    char a;
    retirarPilha(p, a); 
    int operadorA = 0;
    int operadorB = 0;

    // Determina o valor do operador A
    if (a == '^')
        operadorA = 3;
    else if (a == '*' || a == '/')
        operadorA = 2;
    else if (a == '+' || a == '-')
        operadorA = 1;

    // Determina o valor do operador B (o operador atual)
    if (b == '^')
        operadorB = 3;
    else if (b == '*' || b == '/')
        operadorB = 2;
    else if (b == '+' || b == '-')
        operadorB = 1;

    // Retorna true se o operador A for maior ou igual o operador B
    return operadorA >= operadorB;
}

//Função para converção de equação para anotação polonesa.
template <typename T>
T converterNPR(Fila <T> &f){
    
    Pilha <T> p;
    Fila  <T> f_auxiliar;

    char aux, aux_2;

   
    inicializarPilha(p);
    inicializarFila(f_auxiliar);

    // Loop para percorrer a fila de entrada
    while(retirarFila(f, aux)){
        // Se o caractere atual for '(', insira-o na pilha
        if(aux == '(')
            inserirPilha(p, aux);
        else if(aux == ')'){
            //if para Verificar se há um parêntese aberto correspondente na pilha
            if(pilhaVazia(p)){
                cout << "Ha mais parenteses fechados do que abertos \n";
                return 0;
            }
            else{
                //while para transferir elementos da pilha para a fila auxiliar até encontrar '(' 
                while(!pilhaVazia(p)){
                    retirarPilha(p, aux_2); 
                    inserirPilha(p, aux_2); 
                    //if para encontrar '(' e retirar da pilha e sai do loop.
                    if(aux_2 == '('){
                        
                        if(!verificarParenteses(aux_2, aux)){
                            cout << "Parenteses nao combinam. \n";
                            return 0;
                        }
                        else{
                            retirarPilha(p, aux_2);
                            break;
                        }
                    }
                    retirarPilha(p, aux_2); 
                    inserirFila(f_auxiliar, aux_2); 
                }
            }
        }
        else if(aux == '^' || aux == '*' || aux == '/' || aux == '+' || aux == '-'){
            // Loop Enquanto a pilha não estiver vazia e o operador for maior ou igual ao topo da pilha
            while(!pilhaVazia(p) && ordenarOp(aux, p)){
                char aux_3;
                retirarPilha(p, aux_3); 
                inserirFila(f_auxiliar, aux_3); 
            }
            inserirPilha(p, aux);
        }// else for um operando, insira na fila auxiliar
        else{
            inserirFila(f_auxiliar, aux); 
        }
    }

    // while para percorrer toda a fila e tranferir os operadores da pilha para a fila auxiliar
    while(!pilhaVazia(p)){
        char topo;
        retirarPilha(p, topo);
        if(topo != '(')
            inserirFila(f_auxiliar, topo);
        else{
            cout << "Ha mais parenteses abertos do que fechados. \n";
            return 0;
        }
    }

    // Exibe a notação polonesa reversa resultante
    cout << endl << "Notacao Polonesa: ";
    mostrarFila(f_auxiliar);
    cout << endl;

    // Inicialização de uma pilha para calcular o resultado
    Pilha <char> resultadoFinal;
    inicializarPilha(resultadoFinal);

    // Realiza o cálculo com a notação polonesa reversa
    while (!filaVazia(f_auxiliar)){
        calcularNPR(f_auxiliar, resultadoFinal);
    }

    // Exibe o resultado final
    cout << "\nResultado final: ";
    mostrarPilha(resultadoFinal);
    cout << "\n";

    return 1;
}

int main(){
   
    string equacao;
    string opcao;
    Fila <char> f;

    do{
        inicializarFila(f);
        cout << "====================================================";
        cout << "\n\t\tProgram-Infix-To-RPN";
        cout << "\n\n\n\nDigite uma expressao infixa (Ex: (4^2-a*b)/(c*1)): ";
        cout << "\n\n\n";
        cout << "\nou";
        cout << "\n\n\n\nDigite fim para sair: ";
        cout << "\n====================================================";
        cout << "\n";

        getline(cin, equacao);
        cout << endl;

        opcao = equacao;

        if(opcao == "fim" || opcao == "FIM")break;
        //For para separar a veriavel escrita em string para char +
        for( int i=0; i < equacao.length(); i++ ){
            inserirFila(f, equacao[i]);
        }

        cout <<"Fila Original: ";
        mostrarFila(f);
        cout << endl;

        converterNPR(f);

        system("pause");
        system("cls");


    }while(opcao != "fim" && opcao != "FIM");

    return 0;
}
