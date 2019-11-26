#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void criaArquivo(int tamanho,char *nome){
    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    //abrindo o arquivo
    printf("arquivo %s com %d numeros foi gerado.\n",nome,tamanho);
    pont_arq = fopen(nome, "a");
    //colocando os aleatorios
    for(int j=0;j<tamanho;j++){
        int ale = rand() % tamanho;
        fprintf (pont_arq, "%d\n",ale);
    }
    // fechando arquivo
    fclose(pont_arq);
}

void criaOrdenado(int tamanho,int *vet, char *algoritmo){
    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    //abrindo o arquivo
    pont_arq = fopen(algoritmo, "a");
    //colocando os aleatorios
    for(int j=0;j<tamanho;j++){
        fprintf (pont_arq, "%d\n",vet[j]);
    }
    // fechando arquivo
    fclose(pont_arq);
}
//selection_sort
void selection_sort(int *a,int tam)
{
printf("\n===SELECTION SORT===\n");
 int i, j, k, tmp, troca;
 int qtroca=0;
 int qcomparacao=0;
 clock_t tic = clock();
 for(i = 0; i < tam-1; i++)
 {
  troca = 0;
  k = i;
  tmp = a[i];
  for(j = i+1; j < tam; j++)
  {
   if(a[j] < tmp)
   {
    k = j;
    tmp = a[j];
    troca = 1;
    qcomparacao++;
   }}
  if(troca)
  {
   a[k] = a[i];
   a[i] = tmp;
   qtroca++;
  }
}
clock_t toc = clock();
printf("TROCAS: %d\n",qtroca);
printf("COMPARACOES: %d\n",qcomparacao);
printf("TEMPO: %f milisegundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}
//fim
//insertionSort
void insertionSort(int arr[], int n)
{
    int qtroca=0;
    int qcomparacao=0;
    clock_t tic = clock();
    printf("\n===INSERTION SORT===\n");
    int i, key, j;
    for (i = 1; i < n; i++) {
        qtroca++;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            qcomparacao++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    clock_t toc = clock();
    printf("TROCAS: %d\n",qtroca);
    printf("COMPARACOES: %d\n",qcomparacao);
    printf("TEMPO: %f milisegundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}
//fim
//bubble_sort
void bubble_sort (int vetor[], int n) {
    int qtroca=0;
    int qcomparacao=0;
    clock_t tic = clock();
    printf("\n===BUBBLE SORT===\n");
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
                qtroca++;
                qcomparacao++;
            }
        }
    }
    clock_t toc = clock();
    printf("TROCAS: %d\n",qtroca);
    printf("COMPARACOES: %d\n",qcomparacao);
    printf("TEMPO: %f milisegundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);
}
//fim
//radix sort
int radixtroca=0;
int radixcomp=0;

int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
      radixcomp+=1;
  return max;
}
void countingSort(int array[], int size, int place)
{
  int output[size + 1];
  int max = (array[0] / place) % 10;
  for (int i = 1; i < size; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
      radixcomp++;
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
    radixtroca++;
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    radixtroca++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
    radixtroca++;
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
    radixtroca++;
  }
  for (int i = 0; i < size; i++)
    array[i] = output[i];
    radixcomp++;
    radixtroca++;
}
void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
//fim radix sort
//quick Sort;
int quickcomp = 0;
int quicktroca = 0;
void quicksort(int *number,int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      quickcomp++;
      quicktroca+=2;
      while(i<j){
         quickcomp++;
         while(number[i]<=number[pivot]&&i<last){
            quickcomp++;
            i++;}
         while(number[j]>number[pivot]){
            j--;
            quickcomp++;}
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
            quickcomp++;
            quicktroca+=2;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicktroca+=2;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
//fim
//merge sort
int mergecomp = 0;
int mergetroca = 0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        mergecomp++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            mergetroca++;
            mergecomp++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            mergetroca++;
            mergecomp++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        mergetroca++;
        mergecomp++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        mergetroca++;
        mergecomp++;
    }
}
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        mergecomp++;
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
//fim merge sort

//inicio heap sort
int heapcomp=0;
int heaptroca=0;

void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
		heapcomp++;
	}

	for (i = n-1; i >= 1; i--) {
        heapcomp++;
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
        heaptroca++;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
			heapcomp++;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
			heaptroca++;
		}
		else {
			filhoMax = raiz * 2 + 1;
			heaptroca++;
		}

	if (vet[raiz] < vet[filhoMax]) {
        heapcomp++;
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
        heaptroca++;
    }
	else {
      pronto = 1;
	}
  }
}
//fim heap sort

//busca binária
int PesquisaBinaria( int * k, int chave , int N)
{
 int inf,sup,meio;
 inf=0;
 sup=N-1;
 while (inf<=sup)
 {
      meio=(inf+sup)/2;
      if (chave==k[meio])
           return meio;
      else if (chave<k[meio])
           sup=meio-1;
      else
           inf=meio+1;
 }
 return -1;   /* não encontrado */
}

// sequencial
int sequencial(int valor,int *vetor){
for(int i=0;i<10;i++)
{
if (vetor[i]==valor)
{
    return (i);
}
}
return(-1);
}

//le arquivo gera vetor
int * lerArquivo(char *arquivo,int tam){
  int temp;
  int cont = 0;
  FILE *pont_arq;
  char *texto_str[tam];
  int * vet = (int *)calloc(tam,sizeof(int));
  //abrindo o arquivo
  pont_arq = fopen(arquivo, "r");
  while(fgets(texto_str, 20, pont_arq) != NULL){
    sscanf(texto_str,"%d",&temp);
    vet[cont] = temp;
    cont++;
  }
  fclose(pont_arq);
  return(vet);
}

int * ordenaArquivo(char *arquivo,int tam){
  int temp;
  int cont = 0;
  FILE *pont_arq;
  char *texto_str[tam];
  int * vet = (int *)calloc(tam,sizeof(int));
  int * vet2 = (int *)calloc(tam,sizeof(int));
  //abrindo o arquivo
  pont_arq = fopen(arquivo, "r");
  while(fgets(texto_str, 20, pont_arq) != NULL){
    sscanf(texto_str,"%d",&temp);
    vet[cont] = temp;
    cont++;
  }
  fclose(pont_arq);
  //ordenando selection
  memcpy(vet2,vet,tam*sizeof(int));
  selection_sort(vet2,tam);
  criaOrdenado(tam,vet2,"SelectionSort.txt");

  //insertion
  memcpy(vet2,vet,tam*sizeof(int));
  insertionSort(vet2,tam);
  criaOrdenado(tam,vet2,"InsertionSort.txt");

  //bubble
  memcpy(vet2,vet,tam*sizeof(int));
  bubble_sort(vet2,tam);
  criaOrdenado(tam,vet2,"BubbleSort.txt");

  //radix sort
  memcpy(vet2,vet,tam*sizeof(int));
  radixsort(vet2,tam);
  clock_t tic = clock();
  printf("\n===RADIX SORT===\n");
  criaOrdenado(tam,vet2,"RadixSort.txt");
  clock_t toc = clock();
  printf("TROCAS: -\n",radixtroca);
  printf("COMPARACOES: -\n",radixcomp);
  printf("TEMPO: %f milisegundos\n", (double)(toc - tic) / CLOCKS_PER_SEC);

  //quick sort recursive por isso ficou assim
  memcpy(vet2,vet,tam*sizeof(int));
  int qtroca=0;
  int qcomparacao=0;
  clock_t tic3 = clock();
  printf("\n===QUICK SORT===\n");
  quicksort(vet2,0,tam-1);
  clock_t toc3 = clock();
  printf("TROCAS: %d\n",quicktroca);
  printf("COMPARACOES: %d\n",quickcomp);
  printf("TEMPO: %f milisegundos\n", (double)(toc3 - tic3) / CLOCKS_PER_SEC);

  criaOrdenado(tam,vet2,"QuickSort.txt");
  //merge sort
  clock_t tic2 = clock();
  printf("\n===MERGE SORT===\n");
  memcpy(vet2,vet,tam*sizeof(int));
  mergeSort(vet2,0,tam-1);
  criaOrdenado(tam,vet2,"MergeSort.txt");
  clock_t toc2 = clock();
  printf("TROCAS: %d\n",mergetroca);
  printf("COMPARACOES: %d\n",mergecomp);
  printf("TEMPO: %f milisegundos\n", (double)(toc2 - tic2) / CLOCKS_PER_SEC);

  //Heap sort
  //merge sort
  clock_t tic4 = clock();
  printf("\n===HEAP SORT===\n");
  memcpy(vet2,vet,tam*sizeof(int));
  heapsort(vet2,tam);
  criaOrdenado(tam,vet2,"HeapSort.txt");
  clock_t toc4 = clock();
  printf("TROCAS: %d\n",heaptroca);
  printf("COMPARACOES: %d\n",heapcomp);
  printf("TEMPO: %f milisegundos\n\n", (double)(toc4 - tic4) / CLOCKS_PER_SEC);
  free(vet);
  free(vet2);
  return(vet);
}


int main(void)
{
int escolha = 3;
int tam;
int escolha2,escolha3,valor;
while(escolha!=0){
    printf("=== PROJETO ORDENACAO ===\n");
    printf("1 - GERAR ARQUIVO\n");
    printf("2 - ORDENAR ARQUIVO\n");
    printf("3 - BUSCAS\n");
    printf("0 - SAIR\n");
    printf("Opcao:");
    scanf("%i",&escolha);
    switch (escolha){
    case 1:
        remove("Aleatorio.txt");
        printf("Tam. do arquivo:");
        scanf("%d",&tam);
        criaArquivo(tam,"Aleatorio.txt");
        break;
    case 2:
        printf("== Processando Arquivos == \n");
        ordenaArquivo("Aleatorio.txt",tam);
        printf("Arquivos gerados com sucesso :)\n\n");
        break;
    case 3:
        printf("== SELECIONE O TIPO DE BUSCA ==\n");
        printf("1- Binaria\n");
        printf("2- Sequencial\n");
        printf("3- Voltar\n");
        scanf("%d",&escolha3);
        if(escolha3==1){
            printf("== BUSCA BINARIA ==\n");
            printf("Valor Buscado:");
            scanf("%d",&valor);


            int * vet = lerArquivo("HeapSort.txt",tam);
            int pos = PesquisaBinaria(vet,valor,tam);
            if(pos == -1){
                printf("O valor procurado nao se encontra no arquivo :(\n");
            }else{
                printf("Numero encontrado na linha %d :)\n",pos);
            }

            }
        if(escolha3==2){
            printf("== BUSCA SEQUENCIAL ==\n");
            printf("Valor Buscado:");
            scanf("%d\n",&valor);
            int * vet = lerArquivo("Aleatorio.txt",tam);
            int pos = sequencial(valor,vet);
            if(pos == -1){
                printf("O valor procurado nao se encontra no arquivo :(\n");
            }else{
                printf("Numero encontrado na linha %d :)\n\n",pos);
            }
        }
        break;
    }
  }

  return 0;
}
