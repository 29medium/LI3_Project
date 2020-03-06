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

typedef struct selling{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} SALE;

typedef struct sellings{
  int usedV;
  int usedT;
  SALE* listV;
  SALE* listT;
} SALES;

// Functions

void tests(SALES* s, ARR* cli, ARR* prod, ARR* sales);

void quickSort(char* arr[], int low, int high);
int binarySearch(char** arr, char* code, int low, int high);

void arrclientes(ARR* cli);
void arrprodutos(ARR* prod);
void arrsales(ARR* sales);

void salesToS(SALES* s, ARR* cli, ARR* prod, ARR* sales);
void salesToF(SALES* val);
