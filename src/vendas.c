#include "headers.h"

int salesOK(char* buffer, char** clientes, int ncli, char** produtos, int nprod)
{
  int i, r=1, val=0;
  double val2=0;
  char* s;

  for(i=0;(s = strsep(&buffer, " ")) && r && i < 7;i++)
  {
    switch (i)
    {
      case 0:
        if(binarySearch(produtos, s, 0, nprod) >= 0)
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
        if(binarySearch(clientes, s, 0, ncli) >= 0)
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

void salesToA(Sales* s, char** clientes, int ncli, char** produtos, int nprod)
{
  FILE* fsales = fopen("Vendas_1M.txt", "r");
  char* buffer = malloc(sizeof(char) * 29);

  while(fgets(buffer, 30, fsales))
  {
    /*
    buffer[strlen(buffer)-2]='\0';

    if(salesOK(buffer, clientes, ncli, produtos, nprod))
      puts(".");
    */
  }

  fclose(fsales);
}
