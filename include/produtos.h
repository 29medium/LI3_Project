#include "sort.h"

typedef struct prod {
  int size;
  char** list;
} Prod;

typedef struct thashprod {
  int sizet;
  Prod tbl[26];
} THashP;

int hashP(char c);
void tblProd(THashP* tprod);
