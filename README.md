16/10/2026

Kojima - Implementação das funções basicas vistas em sala de aula para o funcionamento do programa pedidas no trabalho além
da implemetação do Insert Sort
Felipe - Implementação do randomizer para a fila de prioridade

19/10/2026
Esse programa considera um mundo ideal onde todos os acentos de um avião serão ocupados
Kojima - Implementação do pivo escolhendo o valor mediano no quicksort,além da implementação do numero de comparações no Heapsort e a função IniciaHeap e o começo da RemoveHeap,onde removera os elementos pela menor(mais perto de 1) prioridade.Ainda faltam as funções ChecaHeap e ImprimeHeap.

21/10/2026

Kojima-Percebi que estava trabalhando com uma struct ao invez de simplismente um vetor e tive que trocar algumas das funções.

23/10/2026

Felipe - Implementação das prioridades para cada passageiro usando a função aleatorizar_vetor no main , e inicio de um menu de opções (tem que melhorar ainda), criação de função para fazer comparação entre metodos de ordenação.

Kojima - implementação do checaHeap, além de acabar o quicksort e fazer a implementação da partição do quicksort(parte que levou tempo pra caramba por causa da mediana como pivo ao invez de um elemento inicial)

25/10/2026

kojima - percebi que a implementação tanto do quick quanto do insert é para serem feitas em um vetor paralelo
então eu me bati com a struct de vetor em ambos os codigos a toa(la se foi basicamente o dia 23 todo por causa do vetor de struct no quicksort)...também tive que implementao o heapsort para o vetor de comparação ao invez de uma struct, além disso fiz algumas modificações no menu de opções, quick e select ainda faltou fazer o heapsort para os 1024 elementos,faltou adicionar numero de comparações e trocas no quick e select

26/10/2026

kojima - fiz a função que cria o vetor de 1024 elementos, assim como a modificação dos codigos de insert e quicksort para contar as comparações

27/09/2026

kojima - finalização da montagem do insert e do quick sort adaptados para contar trocas e comparações

**Funcionamente do programa**

**main.c**
    Dentro da main temos apenas o menu de opções assim como a inicialização de um vetor Heap de tamanho vazio utilizando da função InciaHeap,além também da criação deuma ordem aleatória para todos os elementos dos indices de N que vão de 1 até 853, esse numero foi escolhido pois é o mesmo numero de acentos do maior avião ja registrado.
    Dentro do menu de execução do programa temos um while que termina quando o usuario escolhe a opção de sair, as opções do menu foram feitas usando um case of que vai de 0 até 7(7 sai do programa encerrando o while) <br>

0 - Inserir Passageiro: Cria uma struct passageiro que recebe o nome e a prioridade aleatória e que é colocado como parâmetro no insere heap. <br>

1 - Remover Passageiro: Verifica se o heap é vazio, caso não seja o primeiro elemento é removido do vetor(explicação do por que esta no RemoveHeap abaixo). <br>

2 - Imprimir passageiros: Imprime os passageiros que ainda devem embarcar, ordenados em Heap.

3 - Imprime por prioridade: Cria uma copia do heap e deixa ele ordenado com HeapSort, logo em seguida o imprime, além disso é imprimido as comparações e trocas do heapfy e do heap sort.

4 - Checa heap: verifica se o Heap atual é valido ou não.

5 - Comparar Sorts: Compara o Heapsort,QuickSort e InsertSort, devolvendo o numero de comparações e trocas dos 3, também informa quem fez menos comparações e menos trocas.

6 - Cria um vetor com todos os lugares preenchidos e aplica Heapfy neles(explicação abaixo do que o Heapfy faz).

7 - Ele sai do programa encerrando o while.

**SortFuncoes.c**
    Dentro da SortFuncoes temos quase todoas as funções que são utilizadas ao longo do programa

IniciaHeap - Cria um vetor vazio(tamanho atual = 0)

InsereHeap - A aplicação do insere foi feita baseada no codigo visto em sala de aula, com algumas modificações para poder trabalhar com uma struct ao invez de apenas um elemento e a adição da contagem de Trocas e comparações feitas na inserção.
Para realizar a Inserção nós começamos aumentando o tamanho atual do vetor e inserimos um elemento nessa nova posição do manaho(struct nome e prioridade),como ela é uma função Heap ao final da inserção nós realizamos trocas de posições entre os elementos até o vetor atual voltar a obedecer a ordem (vetor[tam/2] > vetor[tam])

RemoveHeap - Como essa foi uma das funções que não foi vista em sala de aula, para a implementação da RemoveHeap resolvemos remover sempre o elemento de maior prioridade(ou seja o primeiro elemento do Heap), ja que no contexto do exercicio o Remove é utilizado para os passageiros que embarcaram e estamos embarcando primeiro os de maior prioridade ja que estamos usando um MaxHeap.Ao final da execução nós realizamos um SacodeHeap(função vista em aula) para reorganizar a ordem do Heap após a remoção do elemento pai

Heapfy - Outra função vista em sala de aula, que aplica o SacodeHeap em todos os elementos da metade inferior do tamanho atual do vetor

ChecaHeap - Função que verifica se um vetor atual é heap ou não, vendo se um elemento pai é maior que seus elementos filhos

ImrpimeHeap - um loop utilizado para imprimir os passageiros que ainda devem embarcar

SacodeHeap - Função utilizada para Reorganizar um Heap após alguma alteração(inserção,remoção,etc...)pegando um elemento, verificando seus filhos vendo se algum deles é mairo que o elemento e qual dos dois filhos(se houverem dois) é o maior e se o filho for maior que o pai, troca os dois, repetindo isso sempre dobrando o indice do elemento até que o indice seja maior que o tamanho atual, acabando a execução

Heapsort - No Heapsort primeiramente utilizamos Heapfy para fazer o vetor atual se tornar um Heap e após isso fazemos um loop, colocando o primeiro elemento do Heap(vetor[1]) no final do vetor e depois utilizando o SacodeHeap para arrumar o heap restante, repetindo isso até que o vetor Heap tenha se tornado um vetor ordenado, isso funciona devido ao fato de estarmos utilizando um MaxHeap, como o maior elemento sempre sera o (vetor[1]) então a ordenação do vetor sempre sera do maior para o menor até acabar o Heap

MaiorIgual, MenorIgual - Funções auxiliares utilizadas para facilitar a contagem de comparações na função partição devido ao && dentro do if para encontrar a mediana

Particao - Assim como pedido no enunciado, para acharmos o pivo da partição pegamos os valores dos elementos na primeira,ultima e posição do meio, após isso utilizamos de um if para descobrir qual dentre os 3 é o valor da mediana, por exemplo:

vetor[esq] = 54
vetor[meio] = 37
vetor[dir] = 98

Nessa situação após a comparação entre os 3 elementos, o pivo escolhido seria o esq visto que ele é o valor do meio

após isso para a continuação da partição, trocamos o elemento mais a esquerda com o pivo para termos o pivo no começo e possamos trabalhar com um codigo parecido com o que foi visto em sala de aula,porém algumas alterações na estrutura tiveram que ser feitar para acomodar a contagem de comparações, o que não era possivel na estrutura original

para finalizar a partição, todos os elemento menor que o pivo são arrastados para sua esquerda,mantendo sua ordem original enquanto os maiores ou iguais são arrastados para a direita do pivo

Quicksort - Essa função apenas é utilizada para o teste com o vetor de 1024 elementos. Função que a partir do pivo, cria dois subvetores diferentes, um menor que o pivo e outro maior que o pivo e após isso chama recursivamente o quicksort para os subvetores da esquerda e direita, repetindo isso até que todos os elementos estejam em seu devido lugar(como o pivo manda todos os menores e maiores para lados diferentes, o pivo fica no lugar certo quando a partição é feita)

InsertSort- Essa função apenas é utilizada para o teste com o vetor de 1024 elementos.assim como visto em sala, o InserSort começa com 1 elemento e a cada iteração de um loop um novo elemento é adicionado  e após isso,comparado com o resto dos elementos do vetor, sendo arrastado para a esquerda até achar algum elemento menor que ele.

HeapsortIni - para a realização do teste com o vetor de 1024 elementos, tivemos que criar um segundo Heapsort ja que o primeiro era utilizado em uma struct ja esse é apenas em um vetor, tendo sua propria versão do Sacode, Heapfy e Heapsort que possuem a mesma funcionalidade do Heapsort apresentado anteriormente, apenas para vetor ao invez de struct

**log dos testes executados**

Começando com os testes observados no Menu

1 - Se o vetor de passageiros ja esta cheio e um novo passageiro tenta ser inserido,o programa recusa. Caso contrario ele aceita normalmente

2 - Na hora de remover um elemento, ele verifica se um vetor esta vazio, caso esteja ele da uma mensagem dizendo que a fila esta vazia,caso contrario remove o passageiro de maior prioridade

3 - Na hora de imprimir passageiros, se o tamanho atual do vetor for = 0 ele dira que a fila esta vazia, caso contrario ele imprime a fila no formato de arvore binaria

4 - após a realização de diversos testes para termos um grande conjunto de amostras para escolher, foi visto que em questão de comparações a ordem ficou 
    ComparaçõesIsert > ComparaçõesQuick > ComparaçõesHeap
    ou seja o HeapSort realizou o menor numero de comparações
porém na hora de realizar a comparação de trocas, as coisas mudaram
    TrocasInsert > TrocasHeap > TrocasQuick
    sendo o Quicksort o que realizou o menor numero de trocas, porém algo que sempre continuou igual foi o fato de que o InsertSort sempre foi o pior dos 3 sorts