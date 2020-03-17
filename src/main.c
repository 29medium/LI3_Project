#include <stdio.h>
#include "clientes.h"
#include "produtos.h"
#include "sales.h"

THashP prod;
THashC cli;
ARR sales;
SALES s;

int main()
{
  tblProd(&prod);
  tblCli(&cli);

  /*
  for(int i=0; i<TSIZEC; i++)
    for(int j=0; i<cli.tbl[i].size; j++)
      printf("%s\n", cli.tbl[i].list[j]);
  */

  salesToStructs(&sales, &s, &prod, &cli);

  return 0;
}
