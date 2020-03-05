#include "headers.h"

int salesBranch1(SALES* val)
{
  int i, count=0;

  for(i=0; i < val->used; i++)
    if (val->list[i].branch == 1)
      count ++;

  printf("%d\n", count);

  return count;
}

int tests(SALES* val, SALES* nval, ARR* cli, ARR* prod)
{
  //salesBranch1(val);
}
