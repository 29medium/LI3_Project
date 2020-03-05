#include "headers.h"

void salesOK(char* buffer, ARR* cli, ARR* prod)
{
  char* s = NULL;
  char p[SMAX], type[2], c[SMAX];
  float price;
  int uni, month, branch;

  s = strsep(&buffer, " ");
  strcpy(p, s);
  s = strsep(&buffer, " ");
  price = atof(s);
  s = strsep(&buffer, " ");
  uni = atoi(s);
  s = strsep(&buffer, " ");
  strcpy(type, s);
  s = strsep(&buffer, " ");
  strcpy(c, s);
  s = strsep(&buffer, " ");
  month = atoi(s);
  s = strsep(&buffer, " ");
  branch = atoi(s);


  if(binarySearch(prod->list, p, 0, prod->used) && binarySearch(cli->list, c, 0, cli->used))
    printf("%s %f %d %s %s %d %d\n", p, price, uni, type, c, month, branch);
}

void salesToA(SALES* s, ARR* cli, ARR* prod)
{
  FILE* fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer = malloc(sizeof(char) * MAX);
  int i = 0;

  while(fgets(buffer, MAX, fsales) && i<100)
  {
    buffer = strsep(&buffer, "\r");

    salesOK(buffer, cli, prod);

    i++;
  }

  fclose(fsales);
}
