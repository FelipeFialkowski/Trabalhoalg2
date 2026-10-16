#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "funcoes.h"

int aleatorio(int max, int vetor[]){

    int i;

    for (i = 1; i <= max; i ++){
        vetor[i] = i;
    }

    for (int i = max; i > 0; i --){

        int pos = rand () % (i + 1);

        int aux = vetor[i];
        vetor[i] = vetor[pos];
        vetor[pos] = aux;

    }

    int numero = vetor[1];
    return numero;

}