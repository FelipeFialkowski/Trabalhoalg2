#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "funcoes.h"
#include "SortFuncoes.h"


int main(){

    int opcao = -1;
    int vetor_prioridades[N];
    int proximo, contador, trocas = 0;
    int tam = N;
    int resultado;
    int a;

    Passageiro heap[N+1]; 

    srand(time(NULL));

    IniciaHeap(&tam);
    aleatorizar_vetor(vetor_prioridades);
   
    while (opcao != 6){

        printf("__________________________________________________________\n");
        printf("Sair do programa                                      [0] \n"
               "Inserir passageiro                                    [1] \n"
               "Remover passageiro                                    [2] \n"
               "Imprimir passageiros que ainda vão embarcar           [3] \n"
               "Heapsort                                              [4] \n"
               "Imprimir passageiros por prioridade                   [5] \n"
               "Comparar 3 sorts diferentes para 1024 elementos       [6] \n"
               "O que você deseja fazer: ");
            

        
        do {
            resultado = scanf("%d", &opcao);
            while ((a = getchar()) != '\n' && a != EOF);
            if (resultado != 1) {
                printf("Entrada invalida! Digite apenas números de 0 a 6 por favor.\n");
                
                
            }
        } while (resultado != 1);
        printf("__________________________________________________________\n");

        switch(opcao){

            case 0:
              
                Passageiro p;

                //Usei fgets pra ler o nome do passageiro completo (caso tenha espaços)

                printf("Digite o nome do passageiro: ");
                fgets(p.Nome, sizeof(p.Nome), stdin);
                p.Nome[strcspn(p.Nome, "\n")] = 0; 

                p.Prioridade = vetor_prioridades[proximo];
                proximo++;

                printf("A prioridade de embarque de %s é %d\n", p.Nome, p.Prioridade);

                InsereHeap(heap, &tam, p, &contador, &trocas);


            case 6:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Por favor digite um numero de 0 a 6\n");
                break;
        }
    }

    return 0;
  
}