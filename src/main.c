#include "headers.h"

ARR cli;
ARR prod;
ARR sales;
SALES s;
THash4 prods;
THash4 clis;

int main()
{
  arrclientes(&cli);
  arrprodutos(&prod);
  TabelaHash4(&cli,&clis,1);
  TabelaHash4(&prod,&prods,2);
  arrsales(&sales);
  salesToS(&s, &clis, &prods, &sales);
  salesToF(&s);

/*
  for(int i = 0; i < clis.size;i ++) {
    if (clis.list[i].validade)
      printf("%s\n", clis.list[i].nome);
    else printf(".\n" );
  }
*/

  //for(int i = 0; i < s.usedV;i ++) printf("%f\n", s.listV[i].price);
  //tests(&s, &cli, &prod, &sales);

  return 0;
}
