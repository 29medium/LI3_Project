#include "headers.h"

ARR cli;
ARR prod;
SALES s;

int main()
{
  arrclientes(&cli);
  arrprodutos(&prod);

  salesToA(&s, &cli, &prod);

  salesToF(&s);

  return 0;
}
