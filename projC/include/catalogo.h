#ifndef __clientes_h
#define __clientes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct catalogo Catalogo;

Catalogo* initCat();
int searchCat(char* key, Catalogo* cat);
int hashCat(char c);
int tblCat(Catalogo* tcli, char* filePath, char type, int* val, int* lida);
void freeCat(Catalogo* cli);
int getCatListSize(Catalogo* cat, int i);
char* getCatKey(Catalogo* cat, int i, int j);
int comparatorC(const void *p,const void *q);
int binarySearch(char** arr, char* code, int left, int right);

#endif
