#include "headers.h"

void salesOK(SALES* s, ARR* cli, ARR* prod, char* buffer)
{
  char *aux = NULL, *p = NULL, *type = NULL, *c = NULL;
  float price;
  int uni, month, branch;

  aux = strsep(&buffer, " ");
  p = strdup(aux);
  aux = strsep(&buffer, " ");
  price = atof(aux);
  aux = strsep(&buffer, " ");
  uni = atoi(aux);
  aux = strsep(&buffer, " ");
  type = strdup(aux);
  aux = strsep(&buffer, " ");
  c = strdup(aux);
  aux = strsep(&buffer, " ");
  month = atoi(aux);
  aux = strsep(&buffer, " ");
  branch = atoi(aux);

  if((binarySearch(prod->list, p, 0, prod->used)!=(-1)) && (binarySearch(cli->list, c, 0, cli->used)!=(-1)))
  {
    s->list[s->used].p = p;
    s->list[s->used].price = price;
    s->list[s->used].uni = uni;
    s->list[s->used].type = type;
    s->list[s->used].c = c;
    s->list[s->used].month = month;
    s->list[s->used].branch = branch;

    s->used++;
  }
}

void salesToA(SALES* s, ARR* cli, ARR* prod)
{
  FILE* fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer = malloc(sizeof(char) * MAX);

  s->list = malloc(sizeof(SALE) * 891108);
  s->used = 0;

  while(fgets(buffer, MAX, fsales))
  {
    buffer = strsep(&buffer, "\r");

    salesOK(s, cli, prod, buffer);
  }

  printf("%d\n", s->used);

  fclose(fsales);
}

void salesToF(SALES* s) {}
