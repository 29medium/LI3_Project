#include "sort.h"

typedef struct cli {
  int size;
  char** list;
} Cli;

typedef struct thashcli {
  int sizet;
  Cli tbl[26];
} THashC;

int hashC(char c);
void tblCli(THashC* tcli);
