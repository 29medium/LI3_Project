/**
 * @file  sales.c
 * @brief Ficheiro que contém as funções relativas ao carregamento das vendas
 */

#include "sales.h"

#define SMAX 10
#define MAX 64
#define SIZE 26


/**
 * @brief         Função verifica se a venda é válida
 * @param posp    Inteiro com o resultado da procura de um produto
 * @param posc    Inteiro com o resultado da procura de um cliente
 * @param preco   Float com o preço do produto
 * @param type    Char com o tipo de compra
 * @param mes     Inteiro com o mes da compra
 * @param branch  Inteiro com a filial da compra
 * @return        Inteiro usado como booleano
 */
int vendaVal(int posp, int posc, float preco, int uni, char type, int mes, int branch) {
  int r;

  if(posp!=(-1) && posc!=(-1) && preco >= 0.0 && preco < 1000.0
    && uni > 0 && uni <= 200 && (type == 'N' || type == 'P')
    && mes > 0 && mes <= 12 && branch > 0 && branch <= 3)
    r = 1;
  else
    r = 0;

  return r;
}


/**
 * @brief         Função separa uma venda em tokens e adiciona-os à estrutura de Faturação e Gestão de Filiais
 * @param tprod   Apontador para Catalogo de Produtos
 * @param tcli    Apontador para Catalogo de Clientes
 * @param fact    Apontador para THashFact
 * @param gfil    Apontador para GFiliais
 * @param buffer  String com a venda
 * @param val     Apontador para inteiro que contem o numero de vendas validadas
 * @param lida    Apontador para inteiro que contem o numero de vendas lidas
 */
void saleS(Catalogo* tprod, Catalogo* tcli, THashFact* fact, GFiliais* gfil, char* buffer, int* val, int* lida) {
  char *aux = NULL, *prod = NULL, *cli = NULL, *type = NULL;
  int hashp, hashc, posp=0, posc=0;
  int uni, month, branch;
  float price;

  aux = strtok(buffer, " ");
  prod = aux;

  aux = strtok(NULL, " ");
  price = atof(aux);

  aux = strtok(NULL, " ");
  uni = atoi(aux);

  aux = strtok(NULL, " ");
  type = aux;

  aux = strtok(NULL, " ");
  cli = aux;

  aux = strtok(NULL, " ");
  month = atoi(aux);

  aux = strtok(NULL, "\r\n");
  branch = atoi(aux);

  hashc = hashCat(cli[0]);
  hashp = hashCat(prod[0]);

  posc = searchCat(cli, tcli);

  if(posc != (-1))
    posp = searchCat(prod, tprod);

  if(vendaVal(posp,posc,price,uni,type[0],month,branch)) {
    addFact(fact, hashp, posp, month, branch, type[0], price, uni);
    addGFilP(gfil, hashp, posp, cli, branch, type[0]);
    addGFilC(gfil, hashc, posc, prod, branch, month, price, uni);

    (*val)++;
  }

  (*lida)++;
}


/**
 * @brief           Função le um ficheiro, valida e adiciona as vendas a THashFact e GFiliais
 * @param tprod     Apontador para Catalogo de Produtos
 * @param tcli      Apontador para Catalogo de Clientes
 * @param fact      Apontador para THashFact
 * @param gfil      Apontador para GFiliais
 * @param filePath  Caminho para o ficheiro
 * @param val       Apontador para inteiro que contem o numero de vendas validadas
 * @param lida      Apontador para inteiro que contem o numero de vendas lidas
 * @return          Inteiro usado com Booleano
 */
int loadFromSales(Catalogo* tprod, Catalogo* tcli, THashFact* fact, GFiliais* gfil, char* filePath, int* val, int* lida) {
  FILE *fsales = fopen(filePath, "r");
  char* buffer= malloc(sizeof(char) * MAX);

  while(fgets(buffer,MAX,fsales)) {
    saleS(tprod, tcli, fact, gfil, buffer, val, lida);
  }
  remRepC(gfil);
  remRepP(gfil);

  fclose(fsales);

  free(buffer);
  buffer = NULL;

  return 0;
}
