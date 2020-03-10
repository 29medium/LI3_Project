// INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// DEFINE
#define MAX 64
#define SMAX 10

// STRUCTS
// Struct para array de vendas, produtos ou clientes
typedef struct arr{
  int used;
  char** list;
} ARR;

// Structs para tabelas de hash do 4
typedef struct produto{
  int validade;
  char *nome;
}Prod;

typedef struct tHash4{
  int size;
  Prod *list;
}THash4;

// Struct que suporta uma venda
typedef struct selling{
  char* p;
  float price;
  int uni;
  char* type;
  char* c;
  int month;
  int branch;
} SALE;

// Struct que suporta duas listas de vendas
typedef struct sellings{
  int usedV;
  int usedT;
  SALE* listV;
  SALE* listT;
} SALES;


// FUNCTIONS
// sort.c
void quickSort(char* arr[], int low, int high);
int binarySearch(char** arr, char* code, int low, int high);

// arr.c
void arrclientes(ARR* cli);
void arrprodutos(ARR* prod);
void arrsales(ARR* sales);

// hash.c
void TabelaHash4(ARR *a,THash4 *t,int tipo);
int procuraHT(THash4 *t,char *nome);

// sales.c
void salesToS(SALES* s, THash4* cli, THash4* prod, ARR* sales);
void salesToF(SALES* val);

// teste.c
void tests(SALES* s, ARR* cli, ARR* prod, ARR* sales);
