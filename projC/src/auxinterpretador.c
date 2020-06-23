/**
 * @file  auxinterpretador.c
 * @brief Ficheiro que contém funções relativas ao módulo Auxinterpretador
 */

#include "auxinterpretador.h"

#define MAX 100
#define SMAX 30



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 1 E 13 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica as querie 1 e 13
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas as queries 1 e 13
 *@param load   flag que indica se o sgv ja foi inicializado
 */
SGV runQuerie1e13(SGV sgv, int load) {
    clock_t start_t, end_t;
    char buffer[MAX], c1[SMAX], c2[SMAX], c3[SMAX], *s;

    printf("\nIntroduza o caminho para os três ficheiros:\n");
    s = fgets(buffer, MAX, stdin);

    if(s[0]=='\n') {
      strcpy(c1, "./files/Clientes.txt");
      strcpy(c2, "./files/Produtos.txt");
      strcpy(c3, "./files/Vendas_1M.txt");
    }

    else
      sscanf(s, "%s %s %s", c1, c2, c3);

    if(fopen(c1, "r")==NULL) {
      perror(c1);
      return NULL;
    }

    else if(fopen(c2, "r")==NULL) {
      perror(c2);
      return NULL;
    }

    else if(fopen(c3, "r")==NULL) {
      perror(c3);
      return NULL;
    }

    if(load==1)
      destroySGV(sgv);

    start_t = clock();
    sgv = loadSGVFromFiles(sgv, c1, c2, c3);
    end_t = clock();

    Q13* querie13 = getCurrentFilesInfo(sgv);

    printQ1(start_t, end_t);
    printQ13(querie13);

    free(querie13);
    querie13 = NULL;

  return sgv;
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 2
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 2
 */
void runQuerie2(SGV sgv) {
    char c1[2], buffer[MAX], *s;
    int res;
    int i;

    printf("\nIntroduza o carater inicial do Produto (Maiúsculo):\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s", c1);

    if(res != 1) {
      printf("\nArgumento inválido\n");
      return;
    }

    Q2* querie2 = getProductsStartedByLetter(sgv, c1[0]);
    printQ2(querie2, c1[0]);

    if(querie2 != NULL) {
      for(i=0; i<querie2->size; i++) {
        free(querie2->prods[i]);
        querie2->prods[i] = NULL;
      }
      free(querie2->prods);
      querie2->prods = NULL;
      free(querie2);
      querie2 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 3 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 3
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 3
 */
void runQuerie3(SGV sgv){
    char c[SMAX];
    int mes, type, res;
    char buffer[MAX], *s;

    printf("\nIntroduza um produto, um mes e um 0/1 (0-Resultados Globais / 1-Resultados por Filial):\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s %d %d", c, &mes, &type);

    if(res != 3) {
      printf("\nArgumentos inválidos\n");
      return;
    }

    Q3* querie3 = getProductSalesAndProfit(sgv, c, mes, type);
    printQ3(querie3, c, mes);

    if(querie3 != NULL) {
      free(querie3->fat);
      querie3->fat = NULL;
      free(querie3);
      querie3 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 4 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 4
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 4
 */
void runQuerie4(SGV sgv) {
  int i, filial, res;
  char buffer[MAX], *s;

  printf("\nIntroduza uma filial (1 a 3) ou 0 se pretender os resultados globais:\n");
  s = fgets(buffer, MAX, stdin);
  res = sscanf(s, "%d", &filial);

  if(res != 1) {
      printf("\nArgumento inválido\n");
      return;
    }

  Q4* querie4 = getProductsNeverBough(sgv, filial);
  printQ4(querie4);

  if(querie4 != NULL) {
    for(i=0; i<querie4->size; i++) {
        free(querie4->prods[i]);
        querie4->prods[i] = NULL;
    }
    free(querie4->prods);
    querie4->prods = NULL;
    free(querie4);
    querie4 = NULL;
  }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 5 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 5
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 5
 */
void runQuerie5(SGV sgv) {
  int i;

  Q5* querie5 = getClientsOfAllBranches(sgv);
  printQ5(querie5);

  for(i=0; i<querie5->size; i++) {
    free(querie5->cli[i]);
    querie5->cli[i] = NULL;
  }
  free(querie5->cli);
  querie5->cli = NULL;
  free(querie5);
  querie5 = NULL;
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 6 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 6
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 6
 */
void runQuerie6(SGV sgv) {
    clock_t start_t, end_t;

    start_t = clock();
    Q6* querie6 = getClientsAndProductsNeverBoughtCount(sgv);
    end_t = clock();

    printQ6(querie6, start_t, end_t);

    free(querie6);
    querie6 = NULL;
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 7 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 7
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 7
 */
void runQuerie7(SGV sgv) {
    char c1[SMAX], buffer[MAX], *s;
    int res;
    clock_t start_t, end_t;

    printf("\nIntroduza um código de Cliente:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s", c1);

    if(res != 1) {
      printf("\nArgumento inválido\n");
      return;
    }

    start_t = clock();
    Q7* querie7 = getProductsBoughtByClient(sgv, c1);
    end_t = clock();

    printQ7(querie7, start_t, end_t);

    if(querie7 != NULL) {
      free(querie7);
      querie7 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 8 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 8
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 8
 */
void runQuerie8(SGV sgv) {
    char buffer[MAX], *s;
    int minMonth=0, maxMonth=0, res;
    clock_t start_t, end_t;

    printf("\nIntroduza um mes mínimo e um mes máximo:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%d %d", &minMonth, &maxMonth);

    if(res != 2) {
      printf("\nArgumento inválido\n");
      return;
    }

    start_t = clock();
    Q8* querie8 = getSalesAndProfit(sgv, minMonth, maxMonth);
    end_t = clock();

    printQ8(querie8, start_t, end_t);

    if(querie8 != NULL) {
      free(querie8);
      querie8 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 9 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 9
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 9
 */
void runQuerie9(SGV sgv) {
    char c1[SMAX], buffer[MAX], *s;
    int filial, res;
    clock_t start_t, end_t;

    printf("\nIntroduza um código de Produto e uma Filial:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s %d", c1, &filial);

    if(res != 2) {
      printf("\nArgumentos inválidos\n");
      return;
    }

    start_t = clock();
    Q9* querie9 = getProductBuyers(sgv, c1, filial);
    end_t = clock();

    printQ9(querie9, filial, start_t, end_t);

    if(querie9 != NULL) {
      free(querie9->lista);
      querie9->lista = NULL;
      free(querie9);
      querie9 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 10 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 10
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 10
 */
void runQuerie10(SGV sgv) {
    char c1[SMAX], buffer[MAX], *s;
    int res, mes;
    clock_t start_t, end_t;

    printf("\nIntroduza um código de Cliente e um mes:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s %d", c1, &mes);

    if(res != 2) {
      printf("\nArgumentos inválidos\n");
      return;
    }

    start_t = clock();
    Q10* querie10 = getClientFavouriteProducts(sgv,c1,mes);
    end_t = clock();

    printQ10(querie10, start_t, end_t);

    if(querie10 != NULL) {
      free(querie10->produtos);
      querie10->produtos = NULL;
      free(querie10);
      querie10 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 11 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 11
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 11
 */
void runQuerie11(SGV sgv) {
    clock_t start_t, end_t;
    char buffer[MAX], *s;
    int limit, res;

    printf("\nIntroduza o número limite de Produtos a apresentar:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%d", &limit);

    if(res != 1) {
      printf("\nArgumento inválido\n");
      return;
    }

    start_t = clock();
    Q11* querie11 = getTopSelledProducts(sgv, limit);
    end_t = clock();

    printQ11(querie11, start_t, end_t);

    if(querie11 != NULL){
      free(querie11->produtos);
      querie11->produtos = NULL;
      free(querie11);
      querie11 = NULL;
    }
}



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ EXECUTA QUERIE 12 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que aplica a querie 12
 *@param sgv    sistema de gestão de vendas ao qual vão ser aplicadas a querie 12
 */
void runQuerie12(SGV sgv) {
    char c1[SMAX], buffer[MAX], *s;
    int res, limit;
    clock_t start_t, end_t;

    printf("\nIntroduza um código de Cliente e o número máximo de produtos a apresentar:\n");
    s = fgets(buffer, MAX, stdin);
    res = sscanf(s, "%s %d", c1, &limit);

    if(res != 2) {
      printf("\nArgumento inválido\n");
      return;
    }

    start_t = clock();
    Q12* querie12 = getClientTopProfitProducts(sgv, c1, limit);
    end_t = clock();
    printQ12(querie12, start_t, end_t);

    if(querie12 != NULL){
      free(querie12->prods);
      querie12->prods = NULL;
      free(querie12);
      querie12 = NULL;
    }
}
