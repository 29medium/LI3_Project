#include "headers.h"

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(SALES* s, ARR* cli, ARR* prod, char* buffer)
{
  char *aux = NULL;

  s->listT = realloc(s->listT,sizeof(SALE) * (s->usedT + 1));

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].p = aux;

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].price = atof(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].uni = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].type = aux;

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].c = aux;

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].month = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].branch = atoi(aux);

  if((binarySearch(prod->list, s->listT[s->usedT].p, 0, prod->used)!=(-1)) && (binarySearch(cli->list, s->listT[s->usedT].c, 0, cli->used)!=(-1)))
  {
    s->listV = realloc(s->listV,sizeof(SALE) * (s->usedV + 1));

    s->listV[s->usedV].p = s->listT[s->usedT].p;
    s->listV[s->usedV].price = s->listT[s->usedT].price;
    s->listV[s->usedV].uni = s->listT[s->usedT].uni;
    s->listV[s->usedV].type = s->listT[s->usedT].type;
    s->listV[s->usedV].c = s->listT[s->usedT].c;
    s->listV[s->usedV].month = s->listT[s->usedT].month;
    s->listV[s->usedV].branch = s->listT[s->usedT].branch;
    s->usedV++;
  }
}

// Abre o array das vendas e passa-as para uma struct
void salesToS(SALES* s, ARR* cli, ARR* prod, ARR* sales)
{
  s->usedV = 0;
  s->usedT = 0;

  for(int i=0; i<sales->used; i++)
    saleS(s, cli, prod, sales->list[i]);
}

// Passa todas as vendas válidas do array para um ficheiro
void salesToF(SALES* s)
{
  FILE* fsalesv = fopen("../files/Vendas_1MValidas.txt", "w");

  for(int i=0; i<s->usedV; i++){
    fprintf(fsalesv, "%s %f %d %s %s %d %d\r\n",
    s->listV[i].p,
    s->listV[i].price,
    s->listV[i].uni,
    s->listV[i].type,
    s->listV[i].c,
    s->listV[i].month,
    s->listV[i].branch);
  }

  fclose(fsalesv);
}
