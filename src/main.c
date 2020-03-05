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

  //for(int i = 0;i < val.used; i++) printf("%f\n", val.list[i].price);

  salesToF(&val);

  tests(&val, &nval, &cli, &prod);

  return 0;
}
