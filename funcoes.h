#ifndef Funcoes_h
#define Funcoes_h

#define tamanho 1024

void aleatorizar_vetor(int vetor_prioridades[]);    //Função que preenche um vetor com números de 1 a N aleatoriamente sem repetição

void criar_vetor_aleatorio(int vetor_comparacao[]);  //Função que preenche um vetor com números de 0 a 1023 aleatoriamente sem com repetição

void SacodeHeapInt(int vetor[tamanho], int raiz, int tam, int *contador, int *trocas);

void HeapfyInt(int vetor[tamanho],int tam, int *contador, int *trocas);

void HeapSortInt(int vetor[tamanho],int *contador, int *trocas);


#endif