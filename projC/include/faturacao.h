#ifndef __faturacao_h
#define __faturacao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

typedef struct thashfact THashFact;

THashFact* initFact();
void loadFactFromCat(THashFact* fact, Catalogo* prod);
void addFact(THashFact* fact, int hash, int pos, int month, int branch, char type, float price, int uni);
void freeFact(THashFact* fact);


int getFatVendasN(THashFact* fact, int i, int j, int month, int branch);
int getFatVendasP(THashFact* fact, int i, int j, int month, int branch);
float getFatFaturacaoN(THashFact* fact, int i, int j, int month, int branch);
float getFatFaturacaoP(THashFact* fact, int i, int j, int month, int branch);
int getFatUnidades(THashFact* fact, int i, int j, int month, int branch);
int getFatListSize(THashFact* fact, int i);
int getFatOcup(THashFact* fact, int i, int j);

#endif
