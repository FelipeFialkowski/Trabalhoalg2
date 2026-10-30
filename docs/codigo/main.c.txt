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

    while (opcao != 7){

        printf("__________________________________________________________\n");
        printf("Inserir passageiro                                    [0] \n"
               "Remover passageiro (Embarcar no avião)                [1] \n"
               "Imprimir passageiros que ainda vão embarcar           [2] \n"
               "Imprimir passageiros por prioridade (Heapsort)        [3] \n"
               "Checa se heap é valido                                [4] \n"
               "Comparar 3 sorts diferentes para 1024 elementos       [5] \n"
               "Preenche avião automaticamente (Heapfy)               [6] \n"
               "Sair do programa                                      [7] \n"
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
            case 0: {
                
                if (proximo > N) {
                    printf("O Avião está cheio. Não é possível embarcar mais passageiros.\n");
                    break;
                }

                Passageiro p;

                printf("Nome: ");
                fgets(p.Nome, sizeof(p.Nome), stdin);
                p.Nome[strcspn(p.Nome, "\n")] = '\0';        

                p.Prioridade = vetor_prioridades[proximo];
                proximo++;

                printf("A prioridade de embarque de %s é %d\n", p.Nome, p.Prioridade);

                InsereHeap(heap, &tam, p, &comparacoes, &trocas);

                break;
            }
            // Remover passageiro
            case 1: {

                // Verifica se o heap está vazio 
                if (tam == 0) {
                    printf("Nenhum passageiro na fila de embarque.\n");
                    break; 
                }

                Passageiro r = RemoveHeap(heap, &tam, &comparacoes, &trocas);
                printf("O passageiro %s embarcou | Prioridade: %d\n", r.Nome, r.Prioridade);

                break;

            }
            // Imprime passageiros que ainda vão embarcar
            case 2: {
                if (tam == 0) {
                    printf("Nenhum passageiro na fila de embarque.\n");
                    break; 
                }

                ImprimeHeap(heap, tam);
                break;
            }
            // Imprime passageiros por prioridade (Heapsort)
            case 3: {
                if (tam == 0) {
                    printf("Nenhum passageiro na fila de embarque.\n");
                    break; 
                }

                Passageiro copia[N+1];
                
                for (int i = 1; i <= tam; i++) {
                    copia[i] = heap[i];
                }

                int comp = 0;
                int tr = 0;

                HeapSort(copia, tam, &comp, &tr); 
                for (int i = tam; i >= 1; i--)
                    printf("Nome: %s | Prioridade: %d\n", copia[i].Nome, copia[i].Prioridade);
                break; 

            }

            // Checa se é um heap
            case 4: {
                if (ChecaHeap(heap, tam)) {
                    printf("O vetor é um heap.\n");
                } else {
                    printf("O vetor não é um heap.\n");
                }
                break;
            }

            // Compara 3 sorts diferentes para 1024 elementos 
            case 5: {

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
                printf("O numero de trocas no Heapsort foi: %d\n\n", trocas_heap);

                int comparacoes_quick = 0;
                int trocas_quick = 0;

                QuickSort(vetor_quick, 1, tamanho, &comparacoes_quick, &trocas_quick);
                printf("O numero de comparações no Quicksort foi: %d\n", comparacoes_quick);
                printf("O numero de trocas no Quicksort foi: %d\n\n", trocas_quick);

                int comparacoes_insert = 0;
                int trocas_insert = 0;

                InsertSort(vetor_insert, &comparacoes_insert, &trocas_insert);
                printf("O numero de comparações no Insertsort foi: %d\n", comparacoes_insert);
                printf("O numero de trocas no Insertsort foi: %d\n\n", trocas_insert);

                menos_comparacoes(comparacoes_heap, comparacoes_quick, comparacoes_insert);
                menos_trocas(trocas_heap, trocas_quick, trocas_insert);

                break;
            }
           
            //Preenche todos os lugares do avião com heapfy
            case 6: {
                int livres = N - (proximo - 1);   

                if (livres <= 0) {
                    printf("O Avião está cheio. Não há assentos livres.\n");
                    break;
                }

                for (int i = 0; i < livres; i++) {
                    Passageiro p;
                    sprintf(p.Nome, "%d", proximo);
                    p.Prioridade = vetor_prioridades[proximo];
                    proximo++;

                    tam++;
                    heap[tam] = p;               
                }

                int comp = 0;
                int tr = 0;
                Heapfy(heap, tam, &comp, &tr);

                printf("%d passageiros adicionados. Heap com %d passageiros.\n", livres, tam);
                printf("Heapfy: %d comparações e %d trocas.\n", comp, tr);
                printf("O vetor é um heap válido? %s\n", ChecaHeap(heap, tam) ? "Sim" : "Não");
                break;
            }

            // Sai do programa
            case 7:{
                printf("Saindo do programa\n");
                break;
            }
            // Caso usuário digite uma opção inválida
            default:{
                printf("Opção inválida. Por favor digite um número entre 0 e 7.\n");
                break;
            }
        }
    }

    return 0;
}