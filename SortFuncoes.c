#include "SortFuncoes.h"
#include "funcoes.h"

void IniciaHeap(int *tam){
    *tam = 0; //cria um vetor vazio
}

void InsereHeap(Passageiro vetor[N],int tam,Passageiro elemento, int *contador, int *trocas){
    int aux;
    int novo = tam+1;
    vetor[novo].Prioridade = elemento.Prioridade;
    while (novo > 1){
        (*contador) ++; //para a comparação do while
        if (vetor[novo/2].Prioridade < vetor[novo].Prioridade){
            (*contador ++); //para a comparação do if
            aux = vetor[novo].Prioridade;
            vetor[novo].Prioridade = vetor[novo/2].Prioridade;
            vetor[novo/2].Prioridade = aux;
            (*trocas)++; //as 3 operações acima contam para uma unica troca
            novo = novo/2;
        }
        else{
            (*contador) ++; //para a comparação do else
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
    int *contador;
    int *trocas;
    for (i = 1; i < N; i++)
        InsereHeap(vetor,i,vetor[i+1],*contador,*trocas);
    printf("O numero de comparações no Heapfy foi: %d\n", contador);
    printf("O numero de trocas no Heapfy foi: %d\n", trocas);
}

void ChecaHeap(Passageiro vetor[N]){
    int i;
    int eh_heap = 1; //o bool de c, assumo que é true até provar o contrario

    for (i = 1; i <= N / 2; i++) {
        int filho_esq = 2 * i;
        int filho_dir = 2 * i + 1;

        if (filho_esq <= N) {
            if (vetor[i].Prioridade < vetor[filho_esq].Prioridade) {
                eh_heap = 0;
                break;
            }
        }

        if (filho_dir <= N) {
            if (vetor[i].Prioridade < vetor[filho_dir].Prioridade) {
                eh_heap = 0;
                break;
            }
        }
    }
}

void ImprimeHeap(Passageiro vetor[N], int tam){
    /*função que imprime Nome e prioridade de um Heap que ainda devem ser embarcados, como essa função pode ser 
    chamada a qualque momento,colocamos o Heapfy nela para ordenar o Heap atual*/
    Heapfy(vetor,tam);
    int i;
    for (i = 1; i <= tam; i++){
        printf("Nome: %s", vetor[i].Nome);
        printf("Prioridade: $d", vetor[i].Prioridade);
    }
}

void SacodeHeap(Passageiro vetor[N],int tam){
    int aux;
    int i=2;
    while (i <= tam){
        if (i < tam)
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

void HeapSort(Passageiro vetor[N],int *contador, int *trocas){
    int i;
    int aux;
    Heapfy(vetor,i);
    for (i = N; i > 1; i--){
        aux = vetor[1].Prioridade;
        vetor[1].Prioridade = vetor[i].Prioridade;
        vetor[i].Prioridade = aux;
        SacodeHeap(vetor, i-1);
        printf("O numero de compações no Heapsort foi: %d\n", contador);
        printf("O numero de trocas no Heapsort foi: %d\n", trocas);
    }
}

void particao(int vetor[Test], int esq,int dir,int *pos_pivo){
    //o codigo ficou tão menor depois de tirar a struct dele...
    int i,j,aux;
    int pivo; 

    int comeco = esq;
    int fim = dir;
    int meio = (esq + dir)/2; //c ja da o floor automatico
    int mediana;
    
    if (((comeco >= fim) && (comeco <= meio)) || ((comeco <= fim) && (comeco >= meio))) //comeco como mediana
        mediana = comeco;
    else if (((meio >= fim) && (meio <= comeco)) || ((meio >= comeco) && (meio <= fim))) //meio como mediana
        mediana = meio;
    else //fim como mediana
        mediana = fim;
    //colocamos a mediana no começo para trabalharmos com o quicksort normal,como se o primeiro elemento fosse o pivo
    aux = vetor[mediana];
    vetor[mediana] = vetor[esq];
    vetor[esq] = aux;

    pivo = vetor[esq];
    i = esq;
    j = dir;
    while (i < j){
        while((vetor[i] <= pivo) && (i < dir))
            i++;
        while(vetor[j] > pivo)
            j--; //pior caso para no pivo
        if (i < j){
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }
    vetor[esq] = vetor[j];
    vetor[j] = pivo;
    *pos_pivo = j;
}

void QuickSort(int vetor[Test], int esq, int dir){
    int pos_pivo;
    if (esq < dir){
        particao(vetor,esq,dir,&pos_pivo);
        QuickSort(vetor,esq,pos_pivo-1);
        QuickSort(vetor,pos_pivo+1,dir);
    }
}

void InsertSort(int vetor[Test]){
    int i,j,aux;
    for (i = 2; i<= Test; i++){
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

void HeapSort2;