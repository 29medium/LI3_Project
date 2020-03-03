#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrclientes(char** arr)
{
  FILE *clientes;
  clientes = fopen("./Files/Clientes.txt", "r");
  char linha[8];
  int size, i=0, l;

  for(size=0; fgets(linha,9,clientes); size++)
  {
    linha[5] = '\0';

    if(!size)
    {
      arr = malloc(sizeof(char *));
      arr[0] = malloc(6*sizeof(char));
      strcpy(arr[i],linha);
    }

    else
    {
      arr = realloc(arr,(size+1) * sizeof(char*));
      arr[size] = malloc(6 * sizeof(char));

      for(i=0; strcmp(linha,arr[i])>0 && i<size; i++);

      for(l=size; l>i; l--)
        strcpy(arr[l],arr[l-1]);

      strcpy(arr[i],linha);
    }
  }

  for(int i = 0; i < 200000;i++) printf("%s\n",arr[i]);

  fclose(clientes);
}

void arrprodutos(char** arr)
{
  FILE *produtos = NULL;
  produtos = fopen("./Files/Produtos.txt", "r");
  char linha[9];
  int size, i=0, l;

  for(size=0; (fgets(linha,sizeof(linha),produtos)) && size<1000; size++)
  {
    linha[6] = '\0';

    if(!size)
    {
      arr = malloc(sizeof(char *));
      arr[0] = malloc(8*sizeof(char));
      strcpy(arr[i],linha);
    }

    else
    {
      arr = realloc(arr,(size+1)*sizeof(char *));
      arr[size] = malloc(8*sizeof(char));

      for (i=0; i<size && strcmp(linha,arr[i])>0; i++);

      for(l=size; l > i; l--)
        strcpy(arr[l],arr[l-1]);

      strcpy(arr[i],linha);
    }

  }

  //for(int i = 0; i < size;i++) printf("%s\n",arr[i]);

  fclose(produtos);
}
