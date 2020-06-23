/**
 * @file  querie.c
 * @brief Ficheiro que contém funções relativas ao módulo Querie
 */

#include "querie.h"

#define SIZE 26
#define SMAX 10



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief        função que devolve os produtos começados por um determinado char
 *@param sgv    estrutura de sistema e gestão de vendas
 *@param letter char que começa o nome dos produtos
 *@return       apontador para Q2
 */
Q2* getProductsStartedByLetter(SGV sgv, char letter) {
  int i, hash;
  void* prod = getSGVProd(sgv);
  Q2* querie2 = malloc(sizeof(Q2));

  hash = hashCat(letter);

  if(hash == -1)
    return NULL;

  querie2->size = getCatListSize(prod,hash);
  querie2->prods = malloc(sizeof(char*)*querie2->size);

  for(i=0; i<querie2->size; i++) {
    querie2->prods[i] = malloc(sizeof(char)*SMAX);
    strcpy(querie2->prods[i], getCatKey(prod,hash,i));
  }

  return querie2;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 3 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve a faturação de um determinado produto, por filial e mês
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param productID String que representa o produto
 *@param month     mês do qual se pretende obter a faturação
 *@param type      inteiro que indica se os resultados são globais ou por filial
 *@return          apontador para Q3
 */
Q3* getProductSalesAndProfit(SGV sgv, char* productID, int month, int type) {
  int i, pos, hash;

  void* prod = getSGVProd(sgv);
  void* fact = getSGVFact(sgv);

  Q3* querie3 = malloc(sizeof(Q3));

  hash= hashCat(productID[0]);
  pos = searchCat(productID, prod);
  if(hash == -1 || pos == -1 || month > 12 || month < 1)
    return NULL;

  if(type == 0) {
    querie3->size = 1;
    querie3->fat = malloc(sizeof(Q3fat));

    querie3->fat->fatN = 0;
    querie3->fat->fatP = 0;
    querie3->fat->nVendasN = 0;
    querie3->fat->nVendasP = 0;

    for(i=0; i<3; i++) {
      querie3->fat->fatN += getFatFaturacaoN(fact,hash,pos,month-1,i);
      querie3->fat->fatP += getFatFaturacaoP(fact,hash,pos,month-1,i);
      querie3->fat->nVendasN += getFatVendasN(fact,hash,pos,month-1,i);
      querie3->fat->nVendasP += getFatVendasP(fact,hash,pos,month-1,i);
    }
  }

  else {
    querie3->size = 3;
    querie3->fat = malloc(sizeof(Q3fat) * querie3->size);

    for(i=0; i<3; i++) {
      querie3->fat[i].fatN = getFatFaturacaoN(fact,hash,pos,month-1,i);
      querie3->fat[i].fatP = getFatFaturacaoP(fact,hash,pos,month-1,i);
      querie3->fat[i].nVendasN = getFatVendasN(fact,hash,pos,month-1,i);
      querie3->fat[i].nVendasP = getFatVendasP(fact,hash,pos,month-1,i);
    }
  }

  return querie3;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 4 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve o número de produtos não comprados
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param branch    inteiro que indica se os resultados são globais ou por filial
 *@return          apontador para Q4
 */
Q4* getProductsNeverBough(SGV sgv,int branch) {
  if(branch < 0 || branch > 3)
    return NULL;

  int i,i2, size;
  void* gfil = getSGVGFiliais(sgv);
  void* prod = getSGVProd(sgv);

  Q4 *querie4 = malloc(sizeof(Q4));
  querie4->size = 0;
  querie4->prods = NULL;

  if(branch == 0)
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < getGFilPListSize(gfil,0,i);i2++) {
        size = getGFilPSizeC(gfil, 0, i, i2) + getGFilPSizeC(gfil, 1, i, i2) +
               getGFilPSizeC(gfil, 2, i, i2);
        if(size == 0) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4->prods[querie4->size], getCatKey(prod, i, i2));
          querie4->size++;
        }
      }

  else {
    for(i = 0;i < SIZE;i++)
      for(i2 = 0;i2 < getGFilPListSize(gfil,branch-1,i);i2++) {
        size = getGFilPSizeC(gfil, branch-1, i, i2);
        if(size == 0) {
          querie4->prods = realloc(querie4->prods,sizeof(char*)*(querie4->size+1));
          querie4->prods[querie4->size] = malloc(sizeof(char) * 10);
          strcpy(querie4->prods[querie4->size], getCatKey(prod, i, i2));
          querie4->size++;
        }
      }
  }
  return querie4;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 5 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve os clientes que fizeram compras em todas as filiais
 *@return          apontador para Q5
 */
Q5* getClientsOfAllBranches(SGV sgv) {
    int i, j, size1, size2, size3;

    void* gfil = getSGVGFiliais(sgv);
    void* prod = getSGVProd(sgv);

    Q5* querie5 = malloc(sizeof(Q5));
    querie5->cli = NULL;
    querie5->size = 0;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getGFilCListSize(gfil,0,i); j++) {
        size1 = getGFilCsizeProds(gfil, 0, i, j);
        size2 = getGFilCsizeProds(gfil, 1, i, j);
        size3 = getGFilCsizeProds(gfil, 2, i, j);

        if(size1>0 && size2>0 && size3>0){
          querie5->cli = realloc(querie5->cli, sizeof(char*) * (querie5->size + 1));
          querie5->cli[querie5->size] = malloc(sizeof(char)*SMAX);
          strcpy(querie5->cli[querie5->size], getCatKey(prod, i, j));
          querie5->size++;
        }
      }
    return querie5;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 6 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve os cliente que não compraram e os produtos não comprados
 *@param sgv       estrutura de sistema e gestão de vendas
 *@return          apontador para Q6
 */
Q6* getClientsAndProductsNeverBoughtCount(SGV sgv) {
    int i, j;

    void* gfil = getSGVGFiliais(sgv);
    void* fact = getSGVFact(sgv);

    Q6* querie6 = malloc(sizeof(Q6));
    querie6->nCli = 0;
    querie6->nProd = 0;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getGFilCListSize(gfil, 0, i); j++)
        if(getGFilCsizeProds(gfil, 0, i, j)==0 &&
           getGFilCsizeProds(gfil, 1, i, j)==0 &&
           getGFilCsizeProds(gfil, 2, i, j)==0)
           querie6->nCli++;

    for(i=0; i<SIZE; i++)
      for(j=0; j<getFatListSize(fact, i); j++)
        if(!getFatOcup(fact, i, j))
          querie6->nProd++;

    return querie6;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 7 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve os produtos comprados por um determinado cliente
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param clientID  String que representa o cliente
 *@return          apontador para Q7
 */
Q7* getProductsBoughtByClient(SGV sgv, char* clientID) {
    int i, j, k, hash, pos;

    void* cli = getSGVCli(sgv);
    void* gfil = getSGVGFiliais(sgv);

    Q7* querie7 = malloc(sizeof(Q7));

    hash = hashCat(clientID[0]);
    pos = searchCat(clientID, cli);

    if(hash == -1 || pos == -1)
      return NULL;

    for(i=0; i<12; i++)
      for(j=0; j<3; j++)
        querie7->tabela[i][j] = 0;

    for(j=0; j<3; j++)
      for(k=0; k<getGFilCsizeProds(gfil, j, hash, pos); k++)
        for(i=0; i<12; i++)
          querie7->tabela[i][j] += getGFilCuni(gfil, j, hash, pos, k, i);

    return querie7;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 8 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve o total de vendas e o total faturado num determinado espaço de tempo
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param minMonth  mês que representa o limite inferior do espaço temporal
 *@param maxMonth  mês que representa o limite superior do espaço temporal
 *@return          apontador para Q8
 */
Q8* getSalesAndProfit(SGV sgv,int minMonth,int maxMonth) {
  if(minMonth < 1 || maxMonth > 12)
    return NULL;

  int i,i2,i3,i4;
  void* fact = getSGVFact(sgv);
  Q8* querie8 = malloc(sizeof(Q8));
  querie8->vendas = 0;
  querie8->fact = 0.0;

  for(i = 0;i < SIZE;i++)
    for(i2 = 0;i2 < getFatListSize(fact,i);i2++)
      for(i3 = minMonth-1;i3 < maxMonth;i3++)
        for(i4 = 0;i4 < 3;i4++) {
          querie8->vendas += getFatVendasN(fact,i,i2,i3,i4) +
                             getFatVendasP(fact,i,i2,i3,i4);
          querie8->fact += getFatFaturacaoN(fact,i,i2,i3,i4) +
                           getFatFaturacaoP(fact,i,i2,i3,i4);
        }

  return querie8;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 9 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve a lista de clientes para um determinado produto numa determinada filial
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param prodID    String que representa o produto
 *@param branch    inteiro que representa a filial
 *@return          apontador para Q9
 */
Q9* getProductBuyers(SGV sgv,char *prodID,int branch) {
    int pos, hash, i,sizeN,sizeP,p = 0;
    void* gfil = getSGVGFiliais(sgv);
    void* prod = getSGVProd(sgv);

    hash = hashCat(prodID[0]);
    pos = searchCat(prodID, prod);

    if(hash == -1 || pos == -1 || branch < 1 || branch > 3)
      return NULL;

    Q9* querie9 = malloc(sizeof(Q9));
    sizeN = getGFilPSizeN(gfil, branch-1, hash, pos);
    sizeP = getGFilPSizeP(gfil, branch-1, hash, pos);
    querie9->lista = malloc(sizeof(Cl)*(sizeN + sizeP));
    querie9->sizeList = sizeN + sizeP;

    for(i = 0; i<sizeN ;i++,p++) {
      querie9->lista[p].tipocompra = 1;
      strcpy(querie9->lista[p].cliente, getGFilPCliN(gfil, branch-1, hash, pos, i));
    }

    for(i = 0; i<sizeP ;i++,p++) {
      querie9->lista[p].tipocompra = 2;
      strcpy(querie9->lista[p].cliente, getGFilPCliP(gfil, branch-1, hash, pos, i));
    }

    querie9->total = getGFilPSizeC(gfil, branch-1, hash, pos);

    return querie9;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 10 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * @brief   Função troca o apontador de duas Structs P
 * @param a Apontador para P
 * @param b Apontador para P
 */
void swapP(P *a, P *b)
{
    P aux = *a;
    *a = *b;
    *b = aux;
}

/**
 *@brief   Função de comparação usada no qsort de P, por produto
 *@param p Apontador para estrutura
 *@param q Apontador para estrutura
 *@return  Inteiro para comparação no qsort
 */
int comparatorPL(const void *p,const void *q) {
  P *a = (P *)p;
  P *b = (P *)q;
  return strcmp(a->prod,b->prod);
}

/**
 *@brief   Função de comparação usada no qsort de P, por quantidade
 *@param p Apontador para estrutura
 *@param q Apontador para estrutura
 *@return  Inteiro para comparação no qsort
 */
int comparatorQP(const void *p,const void *q) {
  P *a = (P *)p;
  P *b = (P *)q;
  return (b->quantidade - a->quantidade);
}


/**
 *@brief           função que devolve por ordem decrescente de quantidade os produtos que um determinado cliente comprou
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param cliID     String que representa o cliente
 *@param month     String que representa o mês
 *@return          apontador para Q10
 */
Q10* getClientFavouriteProducts(SGV sgv, char *cliID, int month) {
  int pos, hash, i, i2, c;

  void* cli = getSGVCli(sgv);
  void* gfil = getSGVGFiliais(sgv);

  pos = searchCat(cliID, cli);
  hash = hashCat(cliID[0]);

  if(hash == -1 || pos == -1 || month > 12 || month < 1)
    return NULL;

  Q10 *querie10 = malloc(sizeof(Q10));
  querie10->size = 0;
  querie10->produtos = NULL;

  for(i2 = 0; i2<3; i2++){
    for(i = 0; i<getGFilCsizeProds(gfil, i2, hash, pos) ;i++) {
      if(getGFilCuni(gfil, i2, hash, pos, i, month-1)){
        querie10->produtos = realloc(querie10->produtos, sizeof(P)*(querie10->size + 1));
        querie10->produtos[querie10->size].quantidade = getGFilCuni(gfil, i2, hash, pos, i, month-1);
        strcpy(querie10->produtos[querie10->size].prod, getGFilCprod(gfil, i2, hash, pos, i));
        querie10->size++;
      }
    }
  }

  qsort(querie10->produtos,querie10->size,sizeof(P),comparatorPL);

  for(i = 0,c = 1;c < querie10->size;i++) {
    for(i2 = c;i2 < querie10->size && !strcmp(querie10->produtos[i2].prod,querie10->produtos[i].prod);i2++)
      querie10->produtos[i].quantidade += querie10->produtos[i2].quantidade;

    if(i2 != i + 1 && i2 < querie10->size)
      swapP(&querie10->produtos[i + 1],&querie10->produtos[i2]);

    c = i2 + 1;
    if(i2 == querie10 -> size)i--;
  }

  querie10->size = i + 1;

  qsort(querie10->produtos,querie10->size,sizeof(P),comparatorQP);

  return querie10;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 11 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief   Função de comparação usada no qsort de PP, por unidades de produto globais
 *@param p Apontador para estrutura
 *@param q Apontador para estrutura
 *@return  Inteiro para comparação no qsort
 */
int comparatorT(const void *p,const void *q) {
  PP *a = (PP *)p;
  PP *b = (PP *)q;
  return (b->total - a->total);
}

/**
 *@brief           função que devolve por ordem decrescente o número de produtos mais vendido em todo o ano, indicando o número total de clientes e unidades vendidas por filial
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param limit     inteiro que representa o limite de produtos a serem devolvidos
 *@return          apontador para Q11
 */
Q11* getTopSelledProducts(SGV sgv, int limit) {
  if(limit < 0)
    return NULL;

  int i, j, k, l, hash, pos;
  void* fact = getSGVFact(sgv);
  void* prod = getSGVProd(sgv);
  void* gfil = getSGVGFiliais(sgv);


  Q11* querie11 = malloc(sizeof(Q11));
  querie11->produtos = NULL;
  querie11->size = 0;

  for(i=0; i < SIZE; i++) {
    for(j=0; j < getFatListSize(fact, i); j++) {
      if(getFatOcup(fact, i, j)) {
        querie11->produtos = realloc(querie11->produtos, sizeof(PP)*(querie11->size+1));
        querie11->produtos[querie11->size].total = 0;
        strcpy(querie11->produtos[querie11->size].prod, getCatKey(prod, i, j));

        for(k=0; k<3; k++) {
          querie11->produtos[querie11->size].unidades[k] = 0;
          for(l=0; l<12; l++) {
            querie11->produtos[querie11->size].unidades[k] += getFatUnidades(fact, i, j, l, k);
          }
          querie11->produtos[querie11->size].total += querie11->produtos[querie11->size].unidades[k];
        }
        querie11->size++;
      }
    }
  }

  qsort(querie11->produtos,querie11->size,sizeof(PP),comparatorT);

  if(limit < querie11->size) {
    querie11->produtos=realloc(querie11->produtos, sizeof(PP)*limit);
    querie11->size = limit;
  }

  for(i=0; i<querie11->size; i++) {
    pos = searchCat(querie11->produtos[i].prod, prod);
    hash = hashCat(querie11->produtos[i].prod[0]);
    querie11->produtos[i].clientes[0] = getGFilPSizeC(gfil, 0, hash, pos);
    querie11->produtos[i].clientes[1] = getGFilPSizeC(gfil, 1, hash, pos);
    querie11->produtos[i].clientes[2] = getGFilPSizeC(gfil, 2, hash, pos);
  }

  return querie11;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 12 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 * @brief   Função troca o apontador de duas Structs PF
 * @param a Apontador para PF
 * @param b Apontador para PF
 */
void swapPF(PF *a, PF *b)
{
    PF aux = *a;
    *a = *b;
    *b = aux;
}

/**
 *@brief   Função de comparação usada no qsort de PF, por faturação
 *@param p Apontador para estrutura
 *@param q Apontador para estrutura
 *@return  Inteiro para comparação no qsort
 */
int comparatorF(const void *p,const void *q) {
  PF *a = (PF *)p;
  PF *b = (PF *)q;
  return (b->faturacao - a->faturacao);
}

/**
 *@brief   Função de comparação usada no qsort de PF, por produto
 *@param p Apontador para estrutura
 *@param q Apontador para estrutura
 *@return  Inteiro para comparação no qsort
 */
int comparatorPF(const void *p,const void *q) {
  PF *a = (PF *)p;
  PF *b = (PF *)q;
  return strcmp(a->prod,b->prod);
}

/**
 *@brief           função que devolve os n produtos mais comprados por um determinado cliente durante o ano
 *@param sgv       estrutura de sistema e gestão de vendas
 *@param clientID  String que representa o cliente
 *@param limit     inteiro que representa o limite de produtos a serem devolvidos
 *@return          apontador para Q12
 */
Q12* getClientTopProfitProducts(SGV sgv, char* clientID, int limit) {
  int pos, hash, i=0, i2, i3, c;

  void* cli = getSGVCli(sgv);
  void* gfil = getSGVGFiliais(sgv);

  pos = searchCat(clientID, cli);
  hash = hashCat(clientID[0]);

  if(hash == -1 || pos == -1 || limit < 0)
    return NULL;

  Q12 *querie12 = malloc(sizeof(Q12));
  querie12->size = 0;
  querie12->prods = NULL;

  querie12->size = getGFilCsizeProds(gfil, 0, hash, pos)
                 + getGFilCsizeProds(gfil, 1, hash, pos)
                 + getGFilCsizeProds(gfil, 2, hash, pos);
  querie12->prods = malloc(sizeof(P) * querie12->size);

  for(i2=0; i2<3; i2++){
    for(i3 = 0; i3<getGFilCsizeProds(gfil, i2, hash, pos) ; i++, i3++) {
      querie12->prods[i].faturacao = getGFilCfat(gfil, i2, hash, pos, i3);
      strcpy(querie12->prods[i].prod, getGFilCprod(gfil, i2, hash, pos, i3));
    }
  }

  qsort(querie12->prods,querie12->size,sizeof(PF),comparatorPF);

  for(i = 0,c = 1;c < querie12 -> size;i++) {
    for(i2 = c;i2 < querie12 -> size && !strcmp(querie12->prods[i2].prod,querie12->prods[i].prod);i2++)
        querie12->prods[i].faturacao += querie12->prods[i2].faturacao;
    if(i2 != i + 1 && i2 < querie12 -> size)
      swapPF(&querie12->prods[i + 1],&querie12->prods[i2]);

    c = i2 + 1;
    if(i2 == querie12 -> size)i--;
  }
  querie12 -> size = i + 1;

  qsort(querie12->prods,querie12->size,sizeof(PF),comparatorF);

  if(limit < i) {
    querie12->prods = realloc(querie12->prods, sizeof(PF)*limit);
    querie12->size = limit;
  }

  return querie12;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ QUERIE 13 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/**
 *@brief           função que devolve os resultados da leitura dos ficheiros da querie 1, bem como o ficheiro lido e usado e o número total de linhas lidas e validadas
 *@param sgv       estrutura de sistema e gestão de vendas
 *@return          apontador para Q13
 */
Q13* getCurrentFilesInfo(SGV sgv) {
    Q13* querie13 = malloc(sizeof(Q13));

    querie13->cliL = getSGVcliL(sgv);
    querie13->cliV = getSGVcliV(sgv);
    strcpy(querie13->pathCli, getSGVprodPath(sgv));
    querie13->prodL = getSGVprodL(sgv);
    querie13->prodV = getSGVprodV(sgv);
    strcpy(querie13->pathProd, getSGVcliPath(sgv));
    querie13->salesL = getSGVsaleL(sgv);
    querie13->salesV = getSGVsaleV(sgv);
    strcpy(querie13->pathSales, getSGVsalePath(sgv));

    return querie13;
}
