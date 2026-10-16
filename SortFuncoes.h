#ifndef FUNCOES
#define FUNCOES
#define N 853
#include <stdio.h>

struct Prioridade{
    char Nome[50];
    int Prioridade; //a prioridade vai de 1 a 853 por que usamos como base o numero de acentos em um Airbus A380
};

void IniciaHeap();
void InsereHeap(int vetor[N],int pos,int elemento);
void RemoveHeap();
void Heapfy(); //mostrar numero de comparações e trocas
void ChecaHeap();
void ImprimeHeap();
void SacodeHeap(int vetor[N],int m);
void HeapSort(int vetor[N]); //mostrar numero de comparações e trocas
void QuickSort();
void InsertSort();

#endif