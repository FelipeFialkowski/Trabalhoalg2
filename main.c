#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"
#include "SortFuncoes.h"


int main(){

    // KOJIMA NÃO ESQUECE DE MUDAR OS PARAMETROS DO PROTOTIPO DA FUNÇÃO TAMBÉM, SE NÃO EU FICO QUE NEM CORNO PROCURANDO O ERRO QUE IMPEDE DE COMPILAR KKKKKKKKKKKKK

    int opcao = -1;
    int vetor_prioridades[N];
    int proximo, contador, trocas = 0;
    int tam = N;
    

    Passageiro heap[N + 1]; 

    srand(time(NULL));

    IniciaHeap(&tam);
    Aleatorizar_vetor(vetor_prioridades);
   
    

    //Menu de opções (Tá em teste por enquanto)

    while (opcao != 0){

        printf("__________________________________________________________\n");
        printf("Sair do programa                                      [0] \n"
               "Inserir passageiro                                    [1] \n"
               "O que você deseja fazer: ");
            

        
        scanf("%d" , &opcao);
        printf("__________________________________________________________\n");

        switch(opcao){

            case 0:
                printf("Saindo do programa...\n");
                break;

            case 1:

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