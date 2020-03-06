#include "headers.h"

ARR cli;
ARR prod;
ARR sales;
SALES s;

int main()
{
  arrclientes(&cli);
  arrprodutos(&prod);
  arrsales(&sales);

  salesToS(&s, &cli, &prod, &sales);
  salesToF(&s);

  tests(&s, &cli, &prod, &sales);

  return 0;
}
