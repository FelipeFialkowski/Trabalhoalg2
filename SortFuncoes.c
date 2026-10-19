#include "SortFuncoes.h"
#include "funcoes.h"

void IniciaHeap(int *tam){
    *tam = 0; //cria um vetor vazio
}

void InsereHeap(int vetor[N],int tam,int elemento, int *contador){
    int aux;
    int novo = tam+1;
    vetor[novo] = elemento;
    while (novo > 1){
        (*contador ++); //para a comparação do while
        if (vetor[novo/2] < vetor[novo]){
            (*contador ++); //para a comparação do if
            aux = vetor[novo];
            vetor[novo] = vetor[novo/2];
            vetor[novo/2] = aux;
            novo = novo/2;
        }
        else{
            (*contador ++); //para a comparação do else
            break; //heap correto
        }
    }
}

Passageiro RemoveHeap(Passageiro vetor[N],int *tam){
    //como estamos trabalhando com um MaxHeap,para retirar o elemento de maior prioridade removemos o elemento do topo do Heap
    Passageiro removido = vetor[1];
    vetor[1] = vetor[*tam];
    (*tam)--;
    Heapfy(vetor, *tam);
    return removido; //mostra quem saium
    //não ah verificação caso o tamanho seja igual a 0,arrumar isso depois
}

void Heapfy(int vetor[N],int tam){
    int i;
    int *comparacoes;
    for (i = 1; i < N; i++)
        InsereHeap(vetor,i,vetor[i+1],*comparacoes);
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

void HeapSort(int vetor[N],int *contador){
    int i;
    int aux;
    Heapfy(vetor,*contador);
    for (i = N; i > 1; i--){
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        SacodeHeap(vetor, i-1);
        printf("O numero de compações foi: %d", contador);
    }
}

void QuickSort(int vetor[N], int tam){
    int pivo; //como o pivo é a mediana pegamos 3 valores e pegamos o do meio
    int comeco = vetor[1]; //guardamos o 0 para o sentinela
    int fim = vetor[tam];
    int meio = vetor[(tam+1)/2]; //c ja da o floor do valor
    //O codigo abaixo talvez não esteja otimizado e possa ser melhorado
    if (((comeco >= fim) && (comeco <= meio)) || ((comeco <= fim) && (comeco >= meio))) //comeco como mediana
        pivo = comeco;
    else if (((meio >= fim) && (meio <= comeco)) || ((meio >= comeco) && (meio <= fim)))
        pivo = meio;
    else
        pivo = fim;
    
    //terminar o quick sort depois...
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