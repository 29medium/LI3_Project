#include "produtos.h"
#include "clientes.h"
#include "sort.h"

// Struct array
typedef struct arr{
  int used;
  char** list;
} ARR;

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

void salesToStructs(ARR* sales, SALES* s, THashP* prod, THashC* cli);
