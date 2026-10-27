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

int mediana(int vetor[], int inicio, int fim){

    int meio = inicio + (fim - inicio) / 2;

    if ((vetor[inicio] > vetor[meio]) != (vetor[inicio] > vetor[fim-1])) {
        return 0;
    } else if ((vetor[meio] > vetor[inicio]) != (vetor[meio] > vetor[fim-1])) {
        return meio;
    } else {
        return fim-1;
    }
}


void InsereHeapInt(int vetor[], int tam, int valor, int *contador, int *trocas) {
    vetor[tam] = valor;
    int i = tam;

    while (i > 1) {
        (*contador)++;

        if (vetor[i/2] < vetor[i]) {
            int aux = vetor[i/2];
            vetor[i/2] = vetor[i];
            vetor[i] = aux;

            (*trocas)++;
            i = i / 2;
        } else {
            break;
        }
    }
}
void SacodeHeapInt(int vetor[], int tam, int *contador, int *trocas) {
    int i = 2;
    int aux;

    while (i <= tam) {
        if (i < tam) {
            (*contador)++;
            if (vetor[i] < vetor[i+1]) {
                i++;
            }
        }
        (*contador)++;

        if (vetor[i/2] < vetor[i]) {
            aux = vetor[i/2];
            vetor[i/2] = vetor[i];
            vetor[i] = aux;
            (*trocas)++;
            i = i * 2;
        } 
        else {
            break;
        }
    }
}

void HeapfyInt(int vetor[tamanho],int tam, int *contador, int *trocas){
    int i;
    for (i = 2; i <= tam; i++)
        InsereHeapInt(vetor, i, vetor[i], contador, trocas);
}

void HeapSortInt(int vetor[], int *contador, int *trocas) {
    int i;
    int aux;

    HeapfyInt(vetor, N, contador, trocas);

    for (i = N; i > 1; i--) {
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        (*trocas)++;
        SacodeHeapInt(vetor, i-1, contador, trocas);
    }
}