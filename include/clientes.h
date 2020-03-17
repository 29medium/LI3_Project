#include "sort.h"

#ifndef __clientes_h
#define __clientes_h
typedef struct cli {
  int size;
  char** list;
} Cli;

typedef struct thashcli {
  int sizet;
  Cli tbl[26];
} THashC;
#endif

int hashC(char c);
void tblCli(THashC* tcli);
