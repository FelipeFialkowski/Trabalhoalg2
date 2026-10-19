#include "SortFuncoes.h"

void IniciaHeap(){}

void InsereHeap(int vetor[N],int tam,int elemento){
    int aux;
    int novo = tam+1;
    vetor[novo] = elemento;
    while (novo > 1)
        while (vetor[novo/2] < vetor[novo]){
            aux = vetor[novo];
            vetor[novo] = vetor[novo/2];
            vetor[novo/2] = aux;
            novo = novo/2;
        }
}

void RemoveHeap(){}

void Heapfy(int vetor[N]){
    int i;
    for (i = 1; i < N; i++)
        InsereHeap(vetor,i,vetor[i+1]);
}

void ChecaHeap(){}

void ImprimeHeap(){}

void SacodeHeap(int vetor[N],int m){
    int aux;
    int i=2;
    while (i <= m){
        if (i < m)
            if (vetor[i]<vetor[i+1])
                i++;
        if (vetor[i/2] >= vetor[i])
            break; //Ta tudo certo
        else{
            aux = vetor[i/2];
            vetor[i/2] = vetor[i];
            vetor[i] = aux;
            i = i*2;
        }
    }
}

void HeapSort(int vetor[N]){
    int i;
    int aux;
    Heapfy(vetor);
    for (i = N; i > 1; i--){
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        SacodeHeap(vetor, i-1);
    }
}

void QuickSort(){
}

void InsertSort(int vetor[N]){
    int i;
    int j;
    int aux;
    for (i = 2; i <= N; i++){ //i começa em 2 por que vetor de 1 elemento ja esta ordenado
        aux = vetor[i];
        j = i-1;
        vetor[0] = aux; //sentinela
        while (aux < vetor[j]){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}