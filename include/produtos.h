#include "sort.h"

#ifndef __produtos_h
#define __produtos_h
typedef struct prod {
  int size;
  char** list;
} Prod;

typedef struct thashprod {
  int sizet;
  Prod tbl[26];
} THashP;
#endif

int hashP(char c);
void tblProd(THashP* tprod);
