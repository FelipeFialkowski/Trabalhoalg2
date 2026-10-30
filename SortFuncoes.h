#ifndef SortFuncoes_h
#define SortFuncoes_h
#define N 853
#define Test 1024
#include <stdio.h>
#include <string.h>

typedef struct {
    char Nome[50]; //Se o nome passar de 50 caracteres,pedir para usuario escolher um Nome menor?
    int Prioridade; //a prioridade vai de 1 a 853 por que usamos como base o numero de acentos em um Airbus A380
}Passageiro;

void IniciaHeap(int *tam);

void InsereHeap(Passageiro vetor[N],int *tam,Passageiro elemento, int *comparacoes, int *trocas); //* adicionado para contar comparações de Heapfy

Passageiro RemoveHeap(Passageiro vetor[N],int *tam, int *comparacoes, int *trocas);

void Heapfy(Passageiro vetor[N],int tam, int *comparacoes, int *trocas); //mostrar numero de comparações e trocas

int ChecaHeap(Passageiro vetor[], int tam);

void ImprimeHeap(Passageiro vetor[N], int tam);

void SacodeHeap(Passageiro vetor[N], int raiz, int tam, int *comparacoes, int *trocas); //mostrar numero de comparações e trocas

void HeapSort(Passageiro vetor[N], int tam, int *comparacoes, int *trocas); //mostrar numero de comparações e trocas(verificar depois se esta certo)

void particao(int vetor[Test], int esq, int dir, int *pos_pivo, int *comparacoes_quick, int *trocas_quick);

void QuickSort(int vetor[Test], int esq, int dir, int *comparacoes_quick, int *trocas_quick);

void InsertSort(int vetor[Test], int *comparacoes_insert, int *trocas_insert);

#endif