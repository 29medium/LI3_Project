#ifndef __filial_h
#define __filial_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

typedef struct gfiliais GFiliais;


GFiliais* initGFil();
void loadGFilFromCat(GFiliais* gfil, Catalogo* prod, Catalogo* cli);
void addGFilP(GFiliais* gfil, int hash, int pos, char* cli, int branch, char type);
void addGFilC(GFiliais* gfil, int hash, int pos, char* prod, int branch, int month, float price, int uni);
void remRepC(GFiliais *gfil);
void remRepP(GFiliais *gfil);
void freeGFil(GFiliais* fil);


int getGFilPSizeC(GFiliais* gfil, int branch, int i, int j);
int getGFilPSizeP(GFiliais* gfil, int branch, int i, int j);
int getGFilPSizeN(GFiliais* gfil, int branch, int i, int j);
char* getGFilPCliP(GFiliais* gfil, int branch, int i, int j, int k);
char* getGFilPCliN(GFiliais* gfil, int branch, int i, int j, int k);
int getGFilPListSize(GFiliais* gfil, int branch, int i);
int getGFilCListSize(GFiliais* gfil, int branch, int i);
char* getGFilCprod(GFiliais*gfil,int branch,int i,int j,int k);
int getGFilCuni(GFiliais*gfil,int branch,int i,int j,int k,int m);
float getGFilCfat(GFiliais*gfil,int branch,int i,int j,int k);
int getGFilCsizeProds(GFiliais*gfil,int branch,int i,int j);
int getGFilComp(GFiliais*gfil);

#endif
