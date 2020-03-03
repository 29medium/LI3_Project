// Include

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs

typedef struct sales{
  char* prod;
  float preco;
  int uni;
  char tipo;
  char* cli;
  int mes;
  int filial;
} Sales;


// Functions

void quickSort(char* arr[], int low, int high);

void arrclientes (char** arr);
void arrprodutos(char** arr);

int salesToA();
