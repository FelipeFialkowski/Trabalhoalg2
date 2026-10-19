#ifndef FUNCOES
#define FUNCOES
#define N 853
#include <stdio.h>

typedef struct Prioridade{
    char Nome[50];
    int Prioridade; //a prioridade vai de 1 a 853 por que usamos como base o numero de acentos em um Airbus A380
}Passageiro;

void IniciaHeap(int *tam);
void InsereHeap(int vetor[N],int pos,int elemento,int *contador); //* adicionado para contar comparações de Heapfy
void RemoveHeap();
void Heapfy(int vetor[N],int *contador); //mostrar numero de comparações e trocas
void ChecaHeap();
void ImprimeHeap();
void SacodeHeap(int vetor[N],int m);
void HeapSort(int vetor[N],int *contador); //mostrar numero de comparações e trocas
void QuickSort(int vetor[N], int tam);
void InsertSort(int vetor[N]);

#endif