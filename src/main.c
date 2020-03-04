#include "headers.h"

char** clientes = NULL;
char** produtos = NULL;
Sales* s = NULL;

int main()
{
  int ncli, nprod;

  clientes = malloc(sizeof(char*) * 16383);
  produtos = malloc(sizeof(char*) * 171008);

  ncli = arrclientes(clientes);
  nprod = arrprodutos(produtos);

  salesToA(s, clientes, ncli, produtos, nprod);

  return 0;
}
