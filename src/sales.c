#include "headers.h"

void salesOK(SALES* s, ARR* cli, ARR* prod, char* buffer)
{
  char* aux = NULL;
  char p[SMAX], type[2], c[SMAX];
  float price;
  int uni, month, branch;

  aux = strsep(&buffer, " ");
  strcpy(p, aux);
  aux = strsep(&buffer, " ");
  price = atof(aux);
  aux = strsep(&buffer, " ");
  uni = atoi(aux);
  aux = strsep(&buffer, " ");
  strcpy(type, aux);
  aux = strsep(&buffer, " ");
  strcpy(c, aux);
  aux = strsep(&buffer, " ");
  month = atoi(aux);
  aux = strsep(&buffer, " ");
  branch = atoi(aux);


  if((binarySearch(prod->list, p, 0, prod->used)!=(-1)) && (binarySearch(cli->list, c, 0, cli->used)!=(-1)))
  {
    s->list[s->used].p = malloc(sizeof(char) * SMAX);
    s->list[s->used].type = malloc(sizeof(char) * 2);
    s->list[s->used].c = malloc(sizeof(char) * 2);

    strcpy(s->list[s->used].p, p);
    s->list[s->used].price = price;
    s->list[s->used].uni = uni;
    strcpy(s->list[s->used].type, type);
    strcpy(s->list[s->used].c, c);
    s->list[s->used].month = month;
    s->list[s->used].branch = branch;

    s->used++;
  }
}

void salesToA(SALES* s, ARR* cli, ARR* prod)
{
  FILE* fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer = malloc(sizeof(char) * MAX);
  int i = 0;

  s->list = malloc(sizeof(SALE) * 891108);
  s->used = 0;

  while(fgets(buffer, MAX, fsales))
  {
    buffer = strsep(&buffer, "\r");

    salesOK(s, cli, prod, buffer);
  }

  fclose(fsales);
}
