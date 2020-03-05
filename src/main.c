#include "headers.h"

ARR cli;
ARR prod;
SALES val;
SALES nval;

int main()
{
  arrclientes(&cli);
  arrprodutos(&prod);

  salesToA(&val, &nval, &cli, &prod);

  salesToF(&val);

  tests(&val, &nval, &cli, &prod);

  return 0;
}
