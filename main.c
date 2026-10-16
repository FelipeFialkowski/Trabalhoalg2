#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"



int main(){

    int max = 853;
    int vetor[max];

    srand(time(NULL));
    printf("O numero é %d",aleatorio(max, vetor));
  
}