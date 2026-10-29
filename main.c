#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"
#include "SortFuncoes.h"

int main(){

    int opcao = -1;
    int vetor_prioridades[N+1];
    int comparacoes = 0;
    int trocas = 0;
    int proximo = 1;
    int tam = N;
    char buffer[100];

    Passageiro heap[N+1]; 

    srand(time(NULL));

    IniciaHeap(&tam);
    aleatorizar_vetor(vetor_prioridades);

    while (opcao != 6){

        printf("__________________________________________________________\n");
        printf("Inserir passageiro                                    [0] \n"
               "Remover passageiro (Embarcar no avião)                [1] \n"
               "Imprimir passageiros que ainda vão embarcar           [2] \n"
               "Heapsort                                              [3] \n"
               "Imprimir passageiros por prioridade                   [4] \n"
               "Comparar 3 sorts diferentes para 1024 elementos       [5] \n"
               "Sair do programa                                      [6] \n"
                " \n"
               "O que você deseja fazer: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &opcao) != 1) {
              printf("__________________________________________________________\n");
              printf("Entrada invalida! Por favor, digite apenas numeros.\n");
              continue;
            } 
        }
        
        printf("__________________________________________________________\n");
            
        switch (opcao){
            // Inserir passageiro
            case 0:
                //considerando que teremos que colocar 1 por 1,talvez tenha sido um erro ter mais de 800...
                //Então, acho que na hora de mandar pro professor a gente diminui ou faz alguma coisa pra não precisar colocar um por um
                Passageiro p;

                printf("Nome: ");
                fgets(p.Nome, sizeof(p.Nome), stdin);
                p.Nome[strcspn(p.Nome, "\n")] = '\0';        

                p.Prioridade = vetor_prioridades[proximo];
                proximo++;

                printf("A prioridade de embarque de %s é %d\n", p.Nome, p.Prioridade);

                InsereHeap(heap, &tam, p, &comparacoes, &trocas);

                break;

            case 1:
                printf("O passageiro %s embarcou no avião | Prioridade: %d\n", heap[1].Nome, heap[1].Prioridade);
                RemoveHeap(heap, &tam, &comparacoes, &trocas);
                break;

            case 2:
                ImprimeHeap(heap, tam, &comparacoes, &trocas);
                break;

            case 3:
                HeapSort(heap, tam, &comparacoes, &trocas);
                break;  

            case 4:
                Heapfy(heap, tam, &comparacoes, &trocas);
                ImprimeHeap(heap, tam, &comparacoes, &trocas);
                break;

            //Compara 3 sorts diferentes para 1024 elementos 
            //Ainda precisa conferir o que é considerado troca em cada sort, mas comparações já esta certo
            case 5:

                int vetor_comparacao[tamanho+1];
                int vetor_heap[tamanho+1];
                int vetor_quick[tamanho+1];
                int vetor_insert[tamanho+1];

                criar_vetor_aleatorio(vetor_comparacao);

                for(int i = 1; i <= tamanho; i++){
                    
                    vetor_heap[i] = vetor_comparacao[i];
                    vetor_quick[i] = vetor_comparacao[i];
                    vetor_insert[i] = vetor_comparacao[i];

                }

                int comparacoes_heap = 0;
                int trocas_heap = 0;

                HeapSortInt(vetor_heap, &comparacoes_heap, &trocas_heap);
                printf("O numero de comparações no Heapsort foi: %d\n", comparacoes_heap);
                printf("O numero de trocas no Heapsort foi: %d\n", trocas_heap);

                int comparacoes_quick = 0;
                int trocas_quick = 0;

                QuickSort(vetor_quick, 1, tamanho, &comparacoes_quick, &trocas_quick);
                printf("O numero de comparações no Quicksort foi: %d\n", comparacoes_quick);
                printf("O numero de trocas no Quicksort foi: %d\n", trocas_quick);

                int comparacoes_insert = 0;
                int trocas_insert = 0;

                InsertSort(vetor_insert, &comparacoes_insert, &trocas_insert);
                printf("O numero de comparações no Insertsort foi: %d\n", comparacoes_insert);
                printf("O numero de trocas no Insertsort foi: %d\n", trocas_insert);

                break;

            //Sai do programa
            case 6:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Por favor digite um número entre 0 e 6.\n");
                break;

        }
    }

    return 0;
}