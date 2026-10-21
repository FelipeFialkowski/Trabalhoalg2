#ifndef FUNCOES
#define FUNCOES
#define N 853
#include <stdio.h>

typedef struct Prioridade{
    char Nome[50];
    int Prioridade; //a prioridade vai de 1 a 853 por que usamos como base o numero de acentos em um Airbus A380
}Passageiro;

void IniciaHeap(int *tam);
void InsereHeap(Passageiro vetor[N],int tam,Passageiro elemento, int *contador); //* adicionado para contar comparações de Heapfy
Passageiro RemoveHeap(Passageiro vetor[N],int *tam);
void Heapfy(Passageiro vetor[N],int tam); //mostrar numero de comparações e trocas
void ChecaHeap(Passageiro vetor[N]);
void ImprimeHeap(Passageiro vetor[N], int tam);
void SacodeHeap(Passageiro vetor[N],int tam);
void HeapSort(Passageiro vetor[N],int *contador); //mostrar numero de comparações e trocas
void QuickSort(Passageiro vetor[N], int tam);
void InsertSort(Passageiro vetor[N]);

#endif