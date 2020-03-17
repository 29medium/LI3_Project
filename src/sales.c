#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sales.h"

#define MAX 64

// Corre uma venda, passa para a struct total e se for válida passa a struct valida
void saleS(SALES* s, char* buffer, THashP* tprod, THashC* tcli)
{
  char *aux = NULL;
  int p, c;

  s->listT = realloc(s->listT,sizeof(SALE) * (s->usedT + 1));

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].p = aux;
  p = hashP(aux[0]);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].price = atof(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].uni = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].type = aux;

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].c = aux;
  c = hashC(aux[0]);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].month = atoi(aux);

  aux = strsep(&buffer, " ");
  s->listT[s->usedT].branch = atoi(aux);

  if((binarySearch(tprod->tbl[p].list, s->listT[s->usedT].p, 0, tprod->tbl[p].size)!=(-1))
  &&(binarySearch(tcli->tbl[c].list, s->listT[s->usedT].c, 0, tcli->tbl[c].size)!=(-1)))
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

  s ->usedT++;
}

// Passa todas as vendas para um array
void salesToA(ARR* sales)
{
  FILE *fsales = fopen("../files/Vendas_1M.txt", "r");
  char* buffer= malloc(sizeof(char) * MAX);
  int used;

  for(used=0; fgets(buffer,MAX,fsales); used++)
  {
    buffer = strsep(&buffer, "\r");

    sales->list = realloc(sales->list,sizeof(char*) * (used + 1));

    sales->list[used] = malloc(MAX * sizeof(char));
    strcpy(sales->list[used],buffer);
  }

  sales->used = used;

  fclose(fsales);
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

// Abre o array das vendas e passa-as para uma struct
void salesToStructs(ARR* sales,SALES*s, THashP* tprod, THashC* tcli)
{
  s->usedV = 0;
  s->usedT = 0;

  salesToA(sales);

  for(int i=0; i<sales->used; i++)
    saleS(s, sales->list[i], tprod, tcli);

  salesToF(s);

}
