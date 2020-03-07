#include "headers.h"

// Troca duas posições de um array
void swap(char** a, char** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}

// Algoritmo de ordenação quicksort para os arrays de produtos e clientes
void quickSort(char** arr, int low, int high)
{
    if (low < high)
    {
      char* pivot = arr[high];
      int i = (low - 1);

      for (int j=low; j<=high-1; j++)
      {
          if (strcmp(arr[j], pivot) < 0)
          {
              i++;
              swap(&arr[i], &arr[j]);
          }
      }
      swap(&arr[i + 1], &arr[high]);

      int pi = i + 1;

      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
    }
}

// Procura binária para um produto ou cliente
int binarySearch(char** arr, char* code, int left, int right)
{
  int mid, res=(-1);

  while (left<=right && res==(-1))
  {
    mid = left + (right-left)/2;

    if (strcmp(arr[mid], code) == 0)
        res = mid;

    if (strcmp(arr[mid], code) < 0)
        left = mid + 1;

    else right = mid - 1;
  }

  return res;
}

int Hash(char *nome,int tipo,int size) {
  int valor = 20000;
  int chave = (nome[0] - 'A') * valor;
  valor /= 19;
  if (tipo == 1) {
    for(int i = 1; i < 6;i ++) {
      if(i == 1) {
        chave += (nome[1] - 'A') * valor;
        valor /= 19;
      }
      else {
        chave += (nome[1] - '0') * valor;
        valor /= 10;
      }
    }
  }
  else {
    for(int i = 1; i < 6;i ++)
      chave *= nome[1] - '0';
  }
  return chave % size;
}

void TabelaHash(ARR *a,THash *new,int tipo) {
  //new -> size = malloc(sizeof(int));
  new -> size = a -> used * 2;
  new -> list = malloc((new -> size) * sizeof(Prod));
  for(int i = 0;i < new -> size; i ++) {
    new -> list[i].validade = 0;
    new -> list[i].nome = NULL;
  }
  int p;
  for(int i = 0; i < a -> used; i ++) {
    p = Hash(a->list[i],tipo,new -> size);

    for(p;new->list[p].validade != 0;p = (p + 1) % new -> size);

    //new->list[p].nome = malloc(SMAX * sizeof(char));
    //strcpy(new->list[p].nome,a -> list[i]);
    new->list[p].nome = a -> list[i];
    new->list[p].validade = 1;
  }

}
