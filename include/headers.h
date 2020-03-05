// Include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define

#define MAX 64
#define SMAX 10

// Structs

typedef struct arr{
  int used;
  char** list;
} ARR;

typedef struct sale{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} SALE;

typedef struct sales{
  int used;
  SALE* list;
} SALES;

// Functions

void quickSort(char* arr[], int low, int high);
int binarySearch(char** arr, char* code, int low, int high);

int salesBranch1(SALES* val);

void arrclientes(ARR* cli);
void arrprodutos(ARR* prod);

void salesToA(SALES* val, SALES* nval, ARR* cli, ARR *prod);
void salesToF(SALES* val);
