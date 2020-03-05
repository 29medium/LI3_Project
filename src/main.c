#include "headers.h"

ARR cli;
ARR prod;
SALES s;

int main()
{
  arrclientes(&cli);
  arrprodutos(&prod);

  salesToA(&s, &cli, &prod);

  return 0;
}
