#include "headers.h"

// Corre uma venda e se for válida passa para a próxima posição livre do array
void salesOK(SALES* val, SALES* nval, ARR* cli, ARR* prod, char* buffer)
{
  char *aux = NULL, *p = NULL, *type = NULL, *c = NULL;
  float price;
  int uni, month, branch;

  aux = strsep(&buffer, " ");
  p = aux;
  printf("%s\n", p);

  aux = strsep(&buffer, " ");
  price = atof(aux);

  aux = strsep(&buffer, " ");
  uni = atoi(aux);

  aux = strsep(&buffer, " ");
  type = aux;

  aux = strsep(&buffer, " ");
  c = aux;

  aux = strsep(&buffer, " ");
  month = atoi(aux);

  aux = strsep(&buffer, " ");
  branch = atoi(aux);

  nval->list[nval->used].p = p;
  nval->list[nval->used].price = price;
  nval->list[nval->used].uni = uni;
  nval->list[nval->used].type = type;
  nval->list[nval->used].c = c;
  nval->list[nval->used].month = month;
  nval->list[nval->used].branch = branch;
  nval->used++;

  if((binarySearch(prod->list, p, 0, prod->used)!=(-1)) && (binarySearch(cli->list, c, 0, cli->used)!=(-1)))
  {
    val->list[val->used].p = p;
    val->list[val->used].price = price;
    val->list[val->used].uni = uni;
    val->list[val->used].type = type;
    val->list[val->used].c = c;
    val->list[val->used].month = month;
    val->list[val->used].branch = branch;
    val->used++;
  }
}

// Abre o ficheiro das vendas, corre todas as vendas e passa as vendas válidas para um array
void salesToA(SALES* val, SALES* nval, ARR* cli, ARR* prod)
{
  FILE* fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer = malloc(sizeof(char) * MAX);

  val->list = malloc(sizeof(SALE) * 891108);
  val->used = 0;

  nval->list = malloc(sizeof(SALE) * 1000000);
  nval->used = 0;

  while(fgets(buffer, MAX, fsales))
  {
    buffer = strsep(&buffer, "\r");

    salesOK(val, nval, cli, prod, buffer);
  }

  fclose(fsales);
}

// Passa todas as vendas válidas do array para um ficheiro
void salesToF(SALES* val)
{
  FILE* fsalesv = fopen("../files/Vendas_1MValidas.txt", "w");

  for(int i=0; i<val->used; i++){
    fprintf(fsalesv, "%s %f %d %s %s %d %d\r\n",
    val->list[i].p,
    val->list[i].price,
    val->list[i].uni,
    val->list[i].type,
    val->list[i].c,
    val->list[i].month,
    val->list[i].branch);
  }

  fclose(fsalesv);
}
