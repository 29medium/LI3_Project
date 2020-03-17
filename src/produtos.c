#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define MAX 10
#define SIZE 26

int hashP(char c)
{
  return c - 65;
}

void initTblP(THashP* tprod)
{
  int i;

  tprod = malloc(sizeof(THashP));

  tprod->sizet = 0;

  for(i=0; i<SIZE; i++)
    tprod->tbl[i].size = 0;
}

int prodVal(char *prod)
{
  int i;

  if(strlen(prod) < 5 || prod[0] < 'A' || prod[0] > 'Z' || prod[1] < '1' || prod[1] > '5')
    return 0;

  for(i = 2; i < 5; i++)
    if(prod[i] < '0' || prod[i] > '9')
      return 0;

  return 1;
}

void tblProd(THashP* tprod)
{
  FILE* fcli = fopen("../files/Produtos.txt", "r");
  char* buffer= malloc(sizeof(char) * MAX);
  int i, pos, used = 0;

  initTblP(tprod);

  while(fgets(buffer,MAX,fcli))
  {
    buffer = strsep(&buffer, "\r");

    if(prodVal(buffer))
    {
      i = hashP(buffer[0]);
      pos = tprod->tbl[i].size;

      tprod->tbl[i].list = realloc(tprod->tbl[i].list,sizeof(char*) * (used + 1));

      tprod->tbl[i].list[pos] = malloc(sizeof(char) * MAX);
      strcpy(tprod->tbl[i].list[pos],buffer);

      tprod->tbl[i].size ++;
      tprod->sizet ++;
    }
  }

  fclose(fcli);

  for(i=0; i<SIZE; i++)
    quickSort(tprod->tbl[i].list, 0, tprod->tbl[i].size - 1);
}
