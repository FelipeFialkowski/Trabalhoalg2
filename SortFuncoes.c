#include "SortFuncoes.h"
#include "funcoes.h"
#include <string.h>

void IniciaHeap(int *tam){
    *tam = 0; //cria um vetor vazio
}

void InsereHeap(Passageiro vetor[N],int tam,Passageiro elemento, int *contador){
    int aux;
    int novo = tam+1;
    vetor[novo].Prioridade = elemento.Prioridade;
    while (novo > 1){
        (*contador ++); //para a comparação do while
        if (vetor[novo/2].Prioridade < vetor[novo].Prioridade){
            (*contador ++); //para a comparação do if
            aux = vetor[novo].Prioridade;
            vetor[novo].Prioridade = vetor[novo/2].Prioridade;
            vetor[novo/2].Prioridade = aux;
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
    if (*tam == 0) //verifiação basica se o vetor é vazio,talvez trocar para um TAD separado depois
        return;
    else{
        Passageiro removido = vetor[1];
        vetor[1] = vetor[*tam];
        (*tam)--;
        Heapfy(vetor, *tam);
        return removido; //mostra quem saiu
    }
}

void Heapfy(Passageiro vetor[N],int tam){
    int i;
    int *comparacoes;
    for (i = 1; i < N; i++)
        InsereHeap(vetor,i,vetor[i+1],*comparacoes);
}

void ChecaHeap(){
    //função que checa se um vetor é Heap ou não
}

void ImprimeHeap(Passageiro vetor[N], int tam){
    /*função que imprime Nome e prioridade de um Heap que ainda devem ser embarcados, como essa função pode ser 
    chamada a qualque momento,colocamos o Heapfy nela para ordenar o Heap*/
    Heapfy(vetor,tam);
    int i;
    for (i = 1; i <= tam; i++){
        printf("Nome: %s", vetor[i].Nome);
        printf("Prioridade: $d", vetor[i].Prioridade);
    }
}

void SacodeHeap(Passageiro vetor[N],int m){
    int aux;
    int i=2;
    while (i <= m){
        if (i < m)
            if (vetor[i].Prioridade < vetor[i+1].Prioridade)
                i++;
        if (vetor[i/2].Prioridade >= vetor[i].Prioridade)
            break; //Ta tudo certo
        else{
            aux = vetor[i/2].Prioridade;
            vetor[i/2].Prioridade = vetor[i].Prioridade;
            vetor[i].Prioridade = aux;
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