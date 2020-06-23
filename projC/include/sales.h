#ifndef __sales_h
#define __sales_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "faturacao.h"
#include "filial.h"

int loadFromSales(Catalogo* prod, Catalogo* cli, THashFact* fact, GFiliais* gfil, char* filePath, int* val, int* lida);

#endif