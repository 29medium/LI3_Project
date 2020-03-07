#include "headers.h"
int clienteValido(char *cliente) {
  if(strlen(cliente) < 5 || cliente[0] < 'A' || cliente[0] > 'Z' || cliente[1] < '1' || cliente[1] > '5') return 0;
  for(int i = 2;i < 5;i++)
    if(cliente[i] < '0' || cliente[i] > '9') return 0;

  return 1;
}

int produtoValido(char *produto) {
  if(strlen(produto) < 6 ) return 0;
  for(int i = 0;i < 6;i++) {
    if (i == 0 || i == 1) {
      if (produto[i] < 'A' || produto[i] > 'Z')  return 0;
    }
    else {
      if(produto[2] == '0' || produto[i] < '0' || produto[i] > '9') return 0;
    }
  }
  return 1;
}
// Abre o ficheiro dos clientes e passa-os todos para um array
void arrclientes(ARR* cli)
{
  FILE* fcli = fopen("../files/Clientes.txt", "r");
  char* buffer= malloc(sizeof(char) * SMAX);
  int used = 0;

  while(fgets(buffer,SMAX,fcli))
  {
    buffer = strsep(&buffer, "\r");

    if(clienteValido(buffer)) {
    cli->list = realloc(cli->list,sizeof(char*) * (used + 1));

    cli->list[used] = malloc(SMAX * sizeof(char));
    strcpy(cli->list[used],buffer);
    used++;
    }
  }

  cli->used = used;

  //quickSort(cli->list, 0, used - 1);

  fclose(fcli);
}

// Abre o ficheiro dos produtos e passa-os todos para um array
void arrprodutos(ARR* prod)
{
  FILE *fprod = fopen("../files/Produtos.txt", "r");
  char* buffer= malloc(sizeof(char) * SMAX);
  int used = 0;

  while(fgets(buffer,SMAX,fprod))
  {
    buffer = strsep(&buffer, "\r");

    if(produtoValido(buffer)) {
    prod->list = realloc(prod->list,sizeof(char*) * (used + 1));

    prod->list[used] = malloc(SMAX * sizeof(char));
    strcpy(prod->list[used],buffer);
    used++;
    }
  }

  prod->used = used;

  //quickSort(prod->list, 0, used - 1);

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
