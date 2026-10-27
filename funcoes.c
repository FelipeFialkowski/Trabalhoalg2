#include <stdlib.h>
#include <stdio.h>

#include "funcoes.h"
#include "SortFuncoes.h"

void vetor_aleatorio_1024(int vetor_comparacao[]){

    for (int i = 0; i < 1024; i ++){
        vetor_comparacao[i] = rand() % 1024;
    }
}

void aleatorizar_vetor(int vetor_prioridades[]){

    // Preenche o vetor com numeros de 1 até N
    for (int i = 0; i < N; i ++){
        vetor_prioridades[i] = i + 1;
    }

    // Embaralha o vetor de maneira aleatória
    for (int i = N - 1; i > 0; i --){

        int pos = rand () % (i + 1);

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