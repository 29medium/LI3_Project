#ifndef __querie_h
#define __querie_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "faturacao.h"

typedef struct q2 {
    int size;
    char** prods;
} Q2;

typedef struct q3fat {
    int nVendasN;
    int nVendasP;
    float fatN;
    float fatP;
} Q3fat;

typedef struct q3 {
    int size;
    Q3fat* fat;
} Q3;

typedef struct q4 {
    int size;
    char**prods;
} Q4;

typedef struct q5 {
    int size;
    char** cli;
} Q5;

typedef struct q6 {
    int nProd;
    int nCli;
} Q6;

typedef struct q7 {
    int tabela[12][3];
} Q7;

typedef struct q8 {
    int vendas;
    float fact;
} Q8;

typedef struct cl9
{
    int tipocompra; 
    char cliente[10];
} Cl;

typedef struct q9 {
    int sizeList;
    int total;
    Cl *lista;
} Q9;

typedef struct p
{
    int quantidade;
    char prod[10];
} P;

typedef struct q10
{
    int size;
    P *produtos;
} Q10;

typedef struct pp
{
  int unidades[3];
  int clientes[3];
  int total;
  char prod[10];
} PP;

typedef struct q11
{
  int size;
  PP *produtos;
} Q11;

typedef struct pf
{
    float faturacao;
    char prod[10];
} PF;

typedef struct q12{
  int size;
  PF* prods;
} Q12;

typedef struct q13 {
    int prodL;
    int prodV;
    char pathProd[64];
    int cliL;
    int cliV;
    char pathCli[64];
    int salesL;
    int salesV;
    char pathSales[64];
} Q13;

Q2* getProductsStartedByLetter(SGV sgv, char letter);
Q3* getProductSalesAndProfit(SGV sgv, char* productID, int month, int type);
Q4* getProductsNeverBough(SGV sgv,int branch);
Q5* getClientsOfAllBranches(SGV sgv);
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv);
Q7* getProductsBoughtByClient(SGV sgv, char* clientID);
Q8* getSalesAndProfit(SGV sgv,int minMonth,int maxMonth);
Q9* getProductBuyers(SGV sgv,char *prodID,int branch);
Q10* getClientFavouriteProducts(SGV sgv,char *cliID,int month);
Q11* getTopSelledProducts(SGV sgv, int limit);
Q12* getClientTopProfitProducts(SGV sgv, char* clientID, int limit);
Q13* getCurrentFilesInfo(SGV sgv);

#endif
