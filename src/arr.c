#include "headers.h"

void arrclientes(char** arr)
{
  FILE* clientes = fopen("../files/Clientes.txt", "r");

  char linha[8];
  int used, size=0;

  for(used=0; fgets(linha,9,clientes); used++)
  {
    linha[5] = '\0';

    if(used == size){
      arr = realloc(arr,((size+1)*2) * sizeof(char*));
      size = (size+1)*2;
    }

    arr[used] = malloc(6 * sizeof(char));
    strcpy(arr[used],linha);
  }

  quickSort(arr, 0, used-1);

  fclose(clientes);
}

void arrprodutos(char** arr)
{
  FILE *produtos = fopen("../files/Produtos.txt", "r");

  char linha[9];
  int used, size=0;

  for(used=0; fgets(linha,9,produtos); used++)
  {
    linha[6] = '\0';

    if(used == size){
      arr = realloc(arr,((size+1)*2) * sizeof(char*));
      size = (size+1)*2;
    }

    arr[used] = malloc(8 * sizeof(char));
    strcpy(arr[used],linha);
  }

  quickSort(arr, 0, used-1);

  fclose(produtos);
}
