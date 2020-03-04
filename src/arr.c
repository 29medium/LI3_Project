#include "headers.h"

int arrclientes(char** arr)
{
  FILE* clientes = fopen("../files/Clientes.txt", "r");

  char* buffer = malloc(sizeof(char) * 8);
  int used;

  for(used=0; fgets(buffer,9,clientes); used++)
  {
    buffer[strlen(buffer)-2] = '\0';

    arr[used] = malloc(6 * sizeof(char));
    strcpy(arr[used],buffer);
  }

  quickSort(arr, 0, used-1);

  fclose(clientes);

  return used;
}

int arrprodutos(char** arr)
{
  FILE *produtos = fopen("../files/Produtos.txt", "r");

  char* buffer = malloc(sizeof(char) * 8);
  int used;

  for(used=0; fgets(buffer,9,produtos); used++)
  {
    buffer[strlen(buffer)-2] = '\0';

    arr[used] = malloc(8 * sizeof(char));
    strcpy(arr[used],buffer);
  }

  quickSort(arr, 0, used-1);

  fclose(produtos);

  return used;
}
