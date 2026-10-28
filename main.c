#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"
#include "SortFuncoes.h"


int main(){

    // KOJIMA NÃO ESQUECE DE MUDAR OS PARAMETROS DO PROTOTIPO DA FUNÇÃO TAMBÉM, SE NÃO EU FICO QUE NEM CORNO PROCURANDO O ERRO QUE IMPEDE DE COMPILAR KKKKKKKKKKKKK
    //da seus pulos felipe, não sei o que é prototipo não kkkk
    //além disso lembre que nosso vetor ta guardando 0 como sentinela, nosso vetor vai sempre de 1 a N, não de 0 a N-1
    // ata vlw

    int opcao = -1;
    int vetor_prioridades[N+1];
    int comparacoes, trocas = 0;
    int proximo = 1;
    int tam = N;

    Passageiro heap[N+1]; 

    srand(time(NULL));

    IniciaHeap(&tam);
    aleatorizar_vetor(vetor_prioridades);
   
    

    //Menu de opções (Tá em teste por enquanto) 
    //K:achei meio bizarro a primeira opção ser pra sair do programa, mas isso é só implicancia mesmo
    //F: kkkkkk por isso teste

    while (opcao != 6){

        printf("__________________________________________________________\n");
        printf("Inserir passageiro                                    [0] \n"
               "Remover passageiro (Embarcar no avião)                [1] \n"
               "Imprimir passageiros que ainda vão embarcar           [2] \n"
               "Heapsort                                              [3] \n"
               "Imprimir passageiros por prioridade                   [4] \n"
               "Comparar 3 sorts diferentes para 1024 elementos       [5] \n"
               "Sair do programa                                      [6] \n"

               "O que você deseja fazer: ");
            

        
        scanf("%d" , &opcao);
        printf("__________________________________________________________\n");

        switch(opcao){

            // Inserir passageiro
            case 0:
                //considerando que teremos que colocar 1 por 1,talvez tenha sido um erro ter mais de 800...
                //Então, acho que na hora de mandar pro professor a gente diminui ou faz alguma coisa pra não precisar colocar um por um
                Passageiro p;

                printf("Nome: ");
                scanf("%49s", p.Nome);            

                p.Prioridade = vetor_prioridades[proximo];
                proximo++;

                printf("A prioridade de embarque de %s é %d\n", p.Nome, p.Prioridade);

                InsereHeap(heap, &tam, p, &comparacoes, &trocas);

                break;

            case 1:
                RemoveHeap(heap, &tam);
                break;

            case 2:
                ImprimeHeap(heap, tam);
                break;

            case 3:
                HeapSort(heap, &comparacoes, &trocas);
                break;  

            case 4:
                Heapfy(heap, tam);
                ImprimeHeap(heap, tam);
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

        }
    }

    return 0;
  
}