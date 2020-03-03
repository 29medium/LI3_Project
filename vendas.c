#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"

int prodOK(char prod[]){
  int r=0;
  FILE* fprod = fopen("Produtos.txt", "r");
  char line[40];

  while(fgets(line, 41, fprod) && r==0){
    line[strlen(line)-2]='\0';
    if(strcmp(line,prod)==0)
      r=1;
  }

  fclose(fprod);

  return r;
}

int costOK(char cost[]){
  int r=0;
  FILE* fcost = fopen("Clientes.txt", "r");
  char line[40];

  while(fgets(line, 41, fcost) && r==0){
    line[strlen(line)-2]='\0';
    if(strcmp(line,cost)==0)
      r=1;
  }

  fclose(fcost);

  return r;
}

int salesOK(char sales[]){
  int i, r=1, val=0;
  double val2=0;
  char *s;

  for(i=0;(s = strsep(&sales, " ")) && r && i < 7;i++)
  {
    switch (i)
    {
      case 0:
        if(!prodOK(s))
          r=0;
        break;

      case 1:
        val2 = atof(s);
        if (val2==0)
          r=0;
        break;

      case 3:
        if(s[0]!='P' && s[0]!='N')
          r=0;
        break;

      case 4:
        if(!costOK(s))
          r=0;
        break;

      default:
        val = atoi(s);
        if (val==0)
          r=0;
        break;
    }
  }

  return r;
}

void toA() {
  printf("Done");
}

int salesToA(char* line, Sales* vendas)
{
  FILE* fsales = fopen("Vendas_1M.txt", "r");

  int i=0;

  while(fgets(line, 41, fsales))
  {
    line[strlen(line)-2]='\0';
    if(salesOK(line))
      toA();
    i++;
  }

  fclose(fsales);

  return 0;
}
