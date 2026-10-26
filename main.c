#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"
#include "SortFuncoes.h"


int main(){

    // KOJIMA NÃO ESQUECE DE MUDAR OS PARAMETROS DO PROTOTIPO DA FUNÇÃO TAMBÉM, SE NÃO EU FICO QUE NEM CORNO PROCURANDO O ERRO QUE IMPEDE DE COMPILAR KKKKKKKKKKKKK
    //da seus pulos felipe, não sei o que é prototipo não kkkk
    //além disso lembre que nosso vetor ta guardando 0 como sentinela, nosso vetor vai sempre de 1 a N, não de 0 a N-1

    int opcao = -1;
    int vetor_prioridades[N];
    int proximo, contador, trocas = 0;
    int tam = N;
    

    Passageiro heap[N + 1]; 

    srand(time(NULL));

    IniciaHeap(&tam);
    Aleatorizar_vetor(vetor_prioridades);
   
    

    //Menu de opções (Tá em teste por enquanto) 
    //K:achei meio bizarro a primeira opção ser pra sair do programa, mas isso é só implicancia mesmo

    while (opcao != 0){

        printf("__________________________________________________________\n");
        printf("Sair do programa                                      [0] \n"
               "Inserir passageiro                                    [1] \n"
               "Remover passageiro                                    [2] \n"
               "Imprimir passageiros que ainda vão embarcar           [3] \n"
               "Heapsort                                              [4] \n"
               "Imprimir passageiros por prioridade                   [5] \n"
               "Comparar 3 sorts diferentes para 1024 elementos       [6] \n"
               "O que você deseja fazer: ");
            

        
        scanf("%d" , &opcao);
        printf("__________________________________________________________\n");

        switch(opcao){

            case 0:
                printf("Saindo do programa...\n");
                break;

            case 1:
                //considerando que teremos que colocar 1 por 1,talvez tenha sido um erro ter mais de 800...
                Passageiro p;

                printf("Nome: ");
                scanf("%49s", p.Nome);            

                p.Prioridade = vetor_prioridades[proximo];
                proximo++;

                printf("A prioridade de embarque de %s é %d\n", p.Nome, p.Prioridade);

                InsereHeap(heap, &tam, p, &contador, &trocas);


            case 2:

        
        }
    }

    return 0;
  
}