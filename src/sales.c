#include "headers.h"

// Corre uma venda e se for válida passa para a próxima posição livre do array
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

// Abre o ficheiro das vendas, corre todas as vendas e passa as vendas válidas para um array
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

  fclose(fsales);
}

// Passa todas as vendas válidas do array para um ficheiro
void salesToF(SALES* s)
{
  FILE* fsalesv = fopen("../files/Vendas_1MValidas.txt", "w");

  for(int i=0; i<s->used; i++){
    fprintf(fsalesv, "%s %f %d %s %s %d %d\r\n",
    s->list[i].p,
    s->list[i].price,
    s->list[i].uni,
    s->list[i].type,
    s->list[i].c,
    s->list[i].month,
    s->list[i].branch);
  }

  fclose(fsalesv);
}
