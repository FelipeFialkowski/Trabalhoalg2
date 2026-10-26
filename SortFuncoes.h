#ifndef FUNCOES
#define FUNCOES
#define N 853
#define Test 1024
#include <stdio.h>
#include <string.h>

typedef struct Prioridade{
    char Nome[50]; //Se o nome passar de 50 caracteres,pedir para usuario escolher um Nome menor?
    int Prioridade; //a prioridade vai de 1 a 853 por que usamos como base o numero de acentos em um Airbus A380
}Passageiro;

void IniciaHeap(int *tam);
void InsereHeap(Passageiro vetor[N],int tam,Passageiro elemento, int *contador, int *trocas); //* adicionado para contar comparações de Heapfy
Passageiro RemoveHeap(Passageiro vetor[N],int *tam);
void Heapfy(Passageiro vetor[N],int tam); //mostrar numero de comparações e trocas
void ChecaHeap(Passageiro vetor[N]);
void ImprimeHeap(Passageiro vetor[N], int tam);
void SacodeHeap(Passageiro vetor[N],int tam);
void HeapSort(Passageiro vetor[N],int *contador, int *trocas); //mostrar numero de comparações e trocas(verificar depois se esta certo)
void particao(int vetor[Test], int esq,int dir,int *pos_pivo);
void QuickSort(int vetor[Test], int esq, int dir);
void InsertSort(int vetor[Test]);

#endif