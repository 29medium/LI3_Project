#include "headers.h"

// Abre o ficheiro dos clientes e passa-os todos para um array
void arrclientes(ARR* cli)
{
  FILE* fcli = fopen("../files/Clientes.txt", "r");
  char* buffer= malloc(sizeof(char) * SMAX);
  int used;

  for(used=0; fgets(buffer,SMAX,fcli); used++)
  {
    buffer = strsep(&buffer, "\r");

    cli->list = realloc(cli->list,sizeof(char*) * (used + 1));

    cli->list[used] = malloc(SMAX * sizeof(char));
    strcpy(cli->list[used],buffer);
  }

  cli->used = used;

  quickSort(cli->list, 0, used - 1);

  fclose(fcli);
}

// Abre o ficheiro dos produtos e passa-os todos para um array
void arrprodutos(ARR* prod)
{
  FILE *fprod = fopen("../files/Produtos.txt", "r");
  char* buffer= malloc(sizeof(char) * SMAX);
  int used;

  for(used=0; fgets(buffer,SMAX,fprod); used++)
  {
    buffer = strsep(&buffer, "\r");

    prod->list = realloc(prod->list,sizeof(char*) * (used + 1));

    prod->list[used] = malloc(SMAX * sizeof(char));
    strcpy(prod->list[used],buffer);
  }

  prod->used = used;

  quickSort(prod->list, 0, used - 1);

  fclose(fprod);
}

// Abre o ficheiro das vendas e passa-as todos para um array
void arrsales(ARR* sales)
{
  FILE *fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer= malloc(sizeof(char) * MAX);
  int used;

  for(used=0; fgets(buffer,MAX,fsales); used++)
  {
    buffer = strsep(&buffer, "\r");

    sales->list = realloc(sales->list,sizeof(char*) * (used + 1));

    sales->list[used] = malloc(MAX * sizeof(char));
    strcpy(sales->list[used],buffer);
  }

  sales->used = used;

  fclose(fsales);
}
