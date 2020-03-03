#include "headers.h"

char** clientes = NULL;
char** produtos = NULL;
char* buffer = NULL;
Sales* vendas = NULL;

int main()
{
  //arrclientes(clientes);
  arrprodutos(produtos);

  //for(int i = 0; i < 16383;i++) printf("%s\n",clientes[i]);

  for(int i = 0; i < 171008;i++)
    printf("%s\n",produtos[i]);

  //salesToA(buffer, vendas, clientes, produtos);

  return 0;
}
