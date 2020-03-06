#include "headers.h"

// Calcula o comprimento da maior venda
// NOT DONE
char* longestS(ARR* sales)
{
  int i, size, max=0, k=0;

  printf("%s\n", sales->list[k]);
  for(i=0; i<sales->used; i++)
  {
    size = strlen(sales->list[i]);
    if(max<size) {
      max = size;
      k = i;
    }
  }

  printf("%s\n", sales->list[k]);
  return sales->list[k];
}

// Devolve o tamanho do array
int nArr(ARR* a)
{
  return a->used;
}

// Devolve o tamanho das vendas válidas
int nSales(SALES* a)
{
  return a->usedV;
}

// Devolve o apontador para o ultimo cliente
char* lastCli(SALES* s)
{
  return s->listV[s->usedV - 1].c;
}

// Devolve o numero de vendas registadas para o ultimo cliente
int nlCli(SALES*s)
{
  int i, count=0;
  char* lcli = s->listV[s->usedV - 1].c;

  for(i=0; i<s->usedV; i++)
    if(strcmp(lcli, s->listV[i].c)==0)
      count++;

  return count;
}

// Devolve o numero de vendas de uma filial
int salesBranch(SALES* s, int x)
{
  int i, count=0;

  for(i=0; i < s->usedV; i++)
    if (s->listV[i].branch == x)
      count ++;

  return count;
}

// Devolve o numero de clientes com o numero de codigo a começar por um determinado char
int nChar(ARR* cli, char letter)
{
  int i, count = 0;

  for(i=0; i<cli->used; i++)
  {
    if(cli->list[i][0] == letter)
      count++;
  }

  return count;
}

// Faturação total registada??

// Função de teste
void tests(SALES* s, ARR* cli, ARR* prod, ARR* sales)
{
  int x=0;
  //char* aux= NULL;

  //aux = longestS(sales);
  //x = nArr(prod);
  //x = nArr(cli);
  //x = nSales(s);
  //aux = lastCli(s);
  x = nlCli(s);
  //x = salesBranch(s, 1);
  //x = nChar(cli, 'B');

  printf("%d\n", x);
  //printf("%s\n", aux);
}
