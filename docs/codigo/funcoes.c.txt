#include <stdlib.h>
#include <stdio.h>

#include "funcoes.h"
#include "SortFuncoes.h"

void criar_vetor_aleatorio(int vetor_comparacao[]){

    for (int i = 1; i <= 1024; i ++){
        vetor_comparacao[i] = rand() % 1024;
    }
}

void aleatorizar_vetor(int vetor_prioridades[]){

    // Preenche o vetor com numeros de 1 até N
    for (int i = 1; i <= N; i ++){
        vetor_prioridades[i] = i;
    }

    // Embaralha o vetor de maneira aleatória
    for (int i = N ; i > 1; i --){

        int pos = 1 + rand () % i;

        int aux = vetor_prioridades[i];
        vetor_prioridades[i] = vetor_prioridades[pos];
        vetor_prioridades[pos] = aux;

    }

}

void SacodeHeapInt(int vetor[tamanho], int raiz, int tam, int *contador, int *trocas) {
    int filho;
    int aux;

    while (raiz * 2 <= tam) {
        filho = raiz * 2;

        // Escolhe o maior filho
        if (filho < tam) {
            (*contador)++;

            if (vetor[filho] < vetor[filho + 1]) {
                filho++;
            }
        }

        // Compara o pai com o maior filho
        (*contador)++;

        if (vetor[raiz] < vetor[filho]) {
            aux = vetor[raiz];
            vetor[raiz] = vetor[filho];
            vetor[filho] = aux;

            (*trocas)++;
            raiz = filho;
        } else {
            break;
        }
    }
}

void HeapfyInt(int vetor[tamanho], int tam, int *contador, int *trocas) {
    for (int i = tam / 2; i >= 1; i--) {
        SacodeHeapInt(vetor, i, tam, contador, trocas);
    }
}

void HeapSortInt(int vetor[tamanho], int *contador, int *trocas) {
    
    int aux;

    HeapfyInt(vetor, tamanho, contador, trocas);

    for (int i = tamanho; i > 1; i--) {
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;

        (*trocas)++;

        SacodeHeapInt(vetor, 1, i - 1, contador, trocas);
    }
}

void menos_trocas(int trocas_heap, int trocas_quick, int trocas_insert){
     if (trocas_heap <= trocas_quick && trocas_heap <= trocas_insert) {
        printf("Quem fez menos trocas foi o Heapsort\n");
    } else if (trocas_quick <= trocas_heap && trocas_quick <= trocas_insert) {
        printf("Quem fez menos trocas foi o Quicksort\n");
    } else {
        printf("Quem fez menos trocas foi o Insertsort\n");
    }
}

void menos_comparacoes(int comparacoes_heap, int comparacoes_quick, int comparacoes_insert){
    if (comparacoes_heap <= comparacoes_quick && comparacoes_heap <= comparacoes_insert) {
        printf("Quem fez menos comparacoes foi o Heapsort\n");
    } else if (comparacoes_quick <= comparacoes_heap && comparacoes_quick <= comparacoes_insert) {
        printf("Quem fez menos comparacoes foi o Quicksort\n");
    } else {
        printf("Quem fez menos comparacoes foi o Insertsort\n");
    }
}