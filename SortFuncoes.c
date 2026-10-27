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

int MaiorIgual(int a, int b, int *contador) {
    (*contador)++;
    return a >= b;
}

int MenorIgual(int a, int b, int *contador) {
    (*contador)++;
    return a <= b;
}

void particao(int vetor[Test], int esq,int dir,int *pos_pivo,int *comparacoes_quick, int *trocas_quick){
    //o codigo ficou tão menor depois de tirar a struct dele...
    int i,j,aux;
    int pivo; 

    int comeco = vetor[esq];
    int fim = vetor[dir];
    int meio = vetor[(esq + dir)/2]; //c ja da o floor automatico
    int mediana; //graças a contagem de comparações,tive que mudar os if e else
    
    //começo como mediana
    if ((MaiorIgual(comeco,fim,comparacoes_quick) && MenorIgual(comeco,meio,comparacoes_quick)) ||
        (MenorIgual(comeco,fim,comparacoes_quick) && MaiorIgual(comeco,meio,comparacoes_quick)))
        mediana = esq;
    //meio como mediana
    else if ((MaiorIgual(meio,fim,comparacoes_quick) && MenorIgual(meio,comeco,comparacoes_quick)) ||
         (MenorIgual(meio,fim,comparacoes_quick) && MaiorIgual(meio,comeco,comparacoes_quick))) //meio como mediana
        mediana = (esq+dir)/2;
    else //fim como mediana
        mediana = dir;
        
    //colocamos a mediana no começo para trabalharmos com o quicksort normal,como se o primeiro elemento fosse o pivo
    aux = vetor[mediana];
    vetor[mediana] = vetor[esq];
    vetor[esq] = aux;
    (*trocas_quick)++; //troca da mediana na esq

    pivo = vetor[esq];
    i = esq;
    j = dir;
    //tive que mudar o loop do while para poder contar as comparações
    while (1) {
    (*comparacoes_quick)++;
    if (i >= j)
        break;

    while (1) {
        (*comparacoes_quick)++;
        if (vetor[i] > pivo)
            break;

        (*comparacoes_quick)++;
        if (i >= dir)
            break;

        i++;
    }

    while (1) {
        (*comparacoes_quick)++;
        if (vetor[j] <= pivo)
            break;

        j--;
    }

    (*comparacoes_quick)++;
    if (i < j) {
        aux = vetor[j];
        vetor[j] = vetor[i];
        vetor[i] = aux;
        (*trocas_quick)++;
    }
}
    vetor[esq] = vetor[j];
    vetor[j] = pivo;
    (*trocas_quick)++;
    *pos_pivo = j;
}

void QuickSort(int vetor[Test], int esq, int dir, int *comparacoes_quick, int *trocas_quick){
    int pos_pivo;
    (*comparacoes_quick)++; 
    if (esq < dir){ //conta como uma comparação
        particao(vetor,esq,dir,&pos_pivo,comparacoes_quick,trocas_quick);
        QuickSort(vetor,esq,pos_pivo-1,comparacoes_quick,trocas_quick);
        QuickSort(vetor,pos_pivo+1,dir,comparacoes_quick,trocas_quick);
    }
}

void InsertSort(int vetor[Test], int *comparacoes_insert, int *trocas_insert){
    //tive que mudar o while um pouco por causa da contagem de comparaçẽos
    int i,j,aux;
    for (i = 2; i<= Test; i++){
        aux = vetor[i];
        j = i-1;
        vetor[0] = aux; //sentinela
        while (1){
            (*comparacoes_insert) ++; //o while faz a comparação
            if (aux >= vetor[j])
                break; //como tem break, o else fica desnessesaio
            vetor[j+1] = vetor[j];
            (*trocas_insert) ++;
            j--;
        }
        vetor[j+1] = aux;
    }
}

void InsereHeap2(int vetor[Test],int pos,int elemento){

}

void SacodeHeap2(int vetor[Test],int tam,int *comparacoes_heap,int *trocas_heap){

}

void HeapSort2(int vetor[Test], int *contador_heap, int *trocas_heap){
    int i,aux;
    heapfy2(vetor,*contador_heap,*trocas_heap);
    for (i = Test; i > 1; i--){
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        (*trocas_heap)++;
        SacodeHeap2(vetor, i-1,*contador_heap,*trocas_heap);
    }
}

int CriaVetorTest(int vetor[Test]){
    int i;
    int vetor[Test];
    
    for (i = 0; i < Test; i++)
        vetor[i] = (i + 1); //como o indice começa em 0, o +1 serve para dizer que o primeiro elemento é 1 e não 0 
    //vamos colocar todos os valores no vetor de forma ordenada e depois embaralhar ele
    int j;
    int aux;
    for (i = Test; i > 1; i--){
        j = rand() % (i + 1); //mesmo caso que o do vetor[i] = i + 1

        //embaralhamento
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
    return vetor[Test];
}