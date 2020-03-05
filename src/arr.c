#include "headers.h"

void arrclientes(ARR* cli)
{
  FILE* fcli = fopen("../files/Clientes.txt", "r");
  char* buffer= malloc(sizeof(char) * 8);
  int used;

  cli->list = malloc(sizeof(char*) * 16384);

  for(used=0; fgets(buffer,9,fcli); used++)
  {
    buffer = strsep(&buffer, "\r");

    cli->list[used] = malloc(6 * sizeof(char));
    strcpy(cli->list[used],buffer);
  }

  cli->used = used;

  quickSort(cli->list, 0, used - 1);

  fclose(fcli);
}

void arrprodutos(ARR* prod)
{
  FILE *fprod = fopen("../files/Produtos.txt", "r");
  char* buffer= malloc(sizeof(char) * SMAX);
  int used;

  prod->list = malloc(sizeof(char*) * 171008);

  for(used=0; fgets(buffer,SMAX,fprod); used++)
  {
    buffer = strsep(&buffer, "\r");

    prod->list[used] = malloc(8 * sizeof(char));
    strcpy(prod->list[used],buffer);
  }

  prod->used = used;

  quickSort(prod->list, 0, used - 1);

  fclose(fprod);
}
