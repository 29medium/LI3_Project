#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"
#include "arr.h"

// Evitar scanf ou fscanf. Usar fgets e depois usar sscanf
// strtok ou strsep
// Iniciar sempre algum apontador com o seu valor ou com NULL

char*** clientes = NULL;
char** produtos;

int main(){
  char* line = malloc(sizeof(char) * 40);
  Sales* vendas = NULL;

  arrclientes(clientes);
  //for(int i = 0; i < 10000;i++) printf("%s\n",*clientes[i]);

  //arrprodutos(produtos);
  //for(int i = 0; i < 10;i++) printf("%s\n",produtos[i]);

  //salesToA(line);

  return 0;
}
