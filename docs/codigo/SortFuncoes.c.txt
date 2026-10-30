#include <stdlib.h>
#include <stdio.h>

#include "SortFuncoes.h"
#include "funcoes.h"

void IniciaHeap(int *tam){
    *tam = 0; //cria um vetor vazio
}

void InsereHeap(Passageiro vetor[N],int *tam,Passageiro elemento, int *comparacoes, int *trocas){

    int novo = ++(*tam);
    vetor[novo] = elemento;
    while (novo > 1){
        (*comparacoes) ++; //para a comparação do while
        if (vetor[novo/2].Prioridade < vetor[novo].Prioridade){
            //(*comparacoes) ++; //para a comparação do if
            Passageiro aux = vetor[novo];
            vetor[novo] = vetor[novo/2];
            vetor[novo/2] = aux;

            (*trocas)++; //as 3 operações acima contam para uma unica troca
            novo = novo/2;
        }
        else{
           (*comparacoes) ++; //para a comparação do else
            break; //heap correto
        }
    }
}

Passageiro RemoveHeap(Passageiro vetor[N],int *tam, int *comparacoes, int *trocas) {
    //como estamos trabalhando com um MaxHeap,para retirar o elemento de maior prioridade removemos o elemento do topo do Heap
    if (*tam == 0) { //verifiação basica se o vetor é vazio,talvez trocar para um TAD separado depois
        Passageiro vazio = {" ", -1};
        return vazio;
    }

    else{
        Passageiro removido = vetor[1];
        vetor[1] = vetor[*tam];
        (*tam)--;
        SacodeHeap(vetor, 1, *tam, comparacoes, trocas);
        return removido; //mostra quem saiu
    }
}

void Heapfy(Passageiro vetor[N], int tam, int *comparacoes, int *trocas) {
    for (int i = tam / 2; i >= 1; i--) {
        SacodeHeap(vetor, i, tam, comparacoes, trocas);
    }
}

int ChecaHeap(Passageiro vetor[], int tam){
    int i;

    for (i = 1; i <= tam / 2; i++) {
        int filho_esq = 2 * i;
        int filho_dir = 2 * i + 1;

        if (filho_esq <= tam) {
            if (vetor[i].Prioridade < vetor[filho_esq].Prioridade) {
                return 0;
            }
        }

        if (filho_dir <= tam) {
            if (vetor[i].Prioridade < vetor[filho_dir].Prioridade) {
                return 0;
            }
        }
    }
    return 1;
}

/*função que imprime Nome e prioridade de um Heap que ainda devem ser embarcados*/
void ImprimeHeap(Passageiro vetor[N], int tam) {
    int i;
    for (i = 1; i <= tam; i++){
        printf("Nome: %s | Prioridade: %d\n", vetor[i].Nome, vetor[i].Prioridade);
    }
}

void SacodeHeap(Passageiro vetor[N], int raiz, int tam, int *comparacoes, int *trocas) {
    int filho;
    Passageiro aux;
    while (raiz * 2 <= tam) {
        filho = raiz * 2;

        if (filho < tam) {
            (*comparacoes)++;
            if (vetor[filho].Prioridade < vetor[filho + 1].Prioridade) {
                filho++;
            }
        }
        (*comparacoes)++;
        if (vetor[raiz].Prioridade < vetor[filho].Prioridade) {
            aux = vetor[raiz];
            vetor[raiz] = vetor[filho];
            vetor[filho] = aux;

            (*trocas)++;
            raiz = filho;
        } else {
            break;
        }
    }
}

void HeapSort(Passageiro vetor[N], int tam, int *comparacoes, int *trocas) {
    Passageiro aux;

    Heapfy(vetor, tam, comparacoes, trocas);
    printf("Heapfy: %d comparações e %d trocas.\n", *comparacoes, *trocas);

    for (int i = tam; i > 1; i--) {
        aux = vetor[1];
        vetor[1] = vetor[i];
        vetor[i] = aux;
        (*trocas)++;

        SacodeHeap(vetor, 1, i - 1, comparacoes, trocas);
    }

    printf("O numero de comparacoes no Heapsort foi: %d\n", *comparacoes);
    printf("O numero de trocas no Heapsort foi: %d\n", *trocas);
    printf("___________________________________________________________\n");
}

int MaiorIgual(int a, int b, int *comparacoes) {
    (*comparacoes)++;
    return a >= b;
}

int MenorIgual(int a, int b, int *comparacoes) {
    (*comparacoes)++;
    return a <= b;
}

void particao(int vetor[Test], int esq,int dir,int *pos_pivo,int *comparacoes_quick, int *trocas_quick){
    int i, j, aux;
    int pivo;

    int comeco = esq;
    int fim = dir;
    int meio = (esq + dir) / 2;
    int mediana;

    // Escolhe a mediana entre o primeiro, o do meio e o último
    if ((MaiorIgual(vetor[comeco], vetor[fim], comparacoes_quick) && MenorIgual(vetor[comeco], vetor[meio], comparacoes_quick)) ||
        (MenorIgual(vetor[comeco], vetor[fim], comparacoes_quick) && MaiorIgual(vetor[comeco], vetor[meio], comparacoes_quick)))
        mediana = comeco;
    else if ((MaiorIgual(vetor[meio], vetor[fim], comparacoes_quick) && MenorIgual(vetor[meio], vetor[comeco], comparacoes_quick)) ||
             (MenorIgual(vetor[meio], vetor[fim], comparacoes_quick) && MaiorIgual(vetor[meio], vetor[comeco], comparacoes_quick)))
        mediana = meio;
    else
        mediana = fim;

    // Coloca a mediana na primeira posição (só conta troca se as posições forem diferentes)
    if (mediana != esq) {
        aux = vetor[mediana];
        vetor[mediana] = vetor[esq];
        vetor[esq] = aux;
        (*trocas_quick)++;
    }

    pivo = vetor[esq];
    i = esq;
    j = dir;

    while (1) {
        if (i >= j)
            break;

        while (1) {
            (*comparacoes_quick)++;      // vetor[i] <= pivo ?
            if (!(vetor[i] <= pivo))
                break;

            (*comparacoes_quick)++; //i < dir
            if (!(i < dir))
                break;
            i++;
        }

        while (1) {
            (*comparacoes_quick)++;      // vetor[j] > pivo ?
            if (!(vetor[j] > pivo))
                break;
            j--;
        }

        if (i < j) {
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
            (*trocas_quick)++;
        }
    }

    // Coloca o pivô na posição final (só conta troca se ele realmente mudar de lugar)
    if (j != esq) {
        vetor[esq] = vetor[j];
        vetor[j] = pivo;
        (*trocas_quick)++;
    }
    *pos_pivo = j;
}

void QuickSort(int vetor[Test], int esq, int dir, int *comparacoes_quick, int *trocas_quick){
    int pos_pivo;
    if (esq < dir){
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
