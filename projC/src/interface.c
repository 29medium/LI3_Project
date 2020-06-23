/**
 * @file    interface.c
 * @brief   Ficheiro que contém funções relativas ao módulo SGV
 */

#include "interface.h"

#define MAX 60 

/**
 *@brief Estrutura com a informação do carregamento dos ficheiros
 */
typedef struct filesinfo {
    int prodV;
    int prodL;
    char* fileProd;
    int cliV;
    int cliL;
    char* fileCli;
    int saleV;
    int saleL;
    char* fileSale;
} FileInfo;

/**
 *@brief Estrutura do Sistema de Gestão de Vendas, com a informação necessária para a execução do programa
 */
struct sgv {
    Catalogo* cli;
    Catalogo* prod;
    THashFact* fact;
    GFiliais* gfil;
    FileInfo* info;
};

/**
 * @brief   Função que inicializa a estrutura FileInfo
 * @return  Apontador para FileInfo
 */
static FileInfo* initFileInfo() {
    FileInfo* f = malloc(sizeof(FileInfo));

    f->prodV = 0;
    f->prodL = 0;
    f->cliV = 0;
    f->cliL = 0;
    f->saleV = 0;
    f->saleL = 0;

    return f;
}

/**
 * @brief   Função que inicializa a estrutura SGV
 * @return  SGV inicializado
 */
static SGV initSGV() {
    SGV sgv = malloc(sizeof(struct sgv));

    sgv->prod = initCat();
    sgv->cli = initCat();
    sgv->fact = initFact();
    sgv->gfil = initGFil();
    sgv->info = initFileInfo();

    return sgv;
}

/**
 * @brief                   Função que adiciona os caminhos dos ficheiros à estrutura FileInfo
 * @param info              Apontador para FileInfo
 * @param clientsFilePath   Caminho para o ficheiro de Clientes
 * @param productsFilePath  Caminho para o ficheiro de Produtos
 * @param salesFilePath     Caminho para o ficheiro de Vendas
 */
static void addInfo(FileInfo* info, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
  info->fileCli = malloc(sizeof(char) * MAX);
  strcpy(info->fileCli, clientsFilePath);
  info->fileProd = malloc(sizeof(char) * MAX);
  strcpy(info->fileProd, productsFilePath);
  info->fileSale = malloc(sizeof(char) * MAX);
  strcpy(info->fileSale, salesFilePath);
}

/**
 * @brief                   Função carrega a estrutura SGV a partir de ficheiros
 * @param sgv               SGV a carregar
 * @param clientsFilePath   Caminho para o ficheiro de Clientes
 * @param productsFilePath  Caminho para o ficheiro de Produtos
 * @param salesFilePath     Caminho para o ficheiro de Vendas
 * @return                  SGV carregado
 */
SGV loadSGVFromFiles(SGV sgv, char* clientsFilePath, char* productsFilePath, char* salesFilePath) {
    sgv = initSGV();

    tblCat(sgv->prod, productsFilePath, 'p', &sgv->info->prodV, &sgv->info->prodL);
    tblCat(sgv->cli, clientsFilePath, 'c', &sgv->info->cliV, &sgv->info->cliL);
    loadFactFromCat(sgv->fact, sgv->prod);
    loadGFilFromCat(sgv->gfil, sgv->prod, sgv->cli);
    loadFromSales(sgv->prod, sgv->cli, sgv->fact, sgv->gfil, salesFilePath, &sgv->info->saleV, &sgv->info->saleL);
    addInfo(sgv->info, clientsFilePath, productsFilePath, salesFilePath);
    return sgv;
}

/**
 * @brief       Função que liberta o espaço de memória ocupado pelo FileInfo
 * @param info  Apontador para FileInfo
 */
static void freeFileInfo(FileInfo* info) {
  free(info->fileCli);
  free(info->fileProd);
  free(info->fileSale);
  free(info);
}

/**
 * @brief       Função que liberta o espaço de memória ocupado pelo SGV
 * @param sgv   SGV a destruir
 */
void destroySGV(SGV sgv) {
    freeCat(sgv->prod);
    freeCat(sgv->cli);
    freeFact(sgv->fact);
    freeGFil(sgv->gfil);
    freeFileInfo(sgv->info);
    free(sgv);
}

/**
 * @brief       Função que retorna o numero de Produtos Validados
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Produtos Validados
 */
int getSGVprodV(SGV sgv) {
    return sgv->info->prodV;
}

/**
 * @brief       Função que retorna o numero de Produtos Lidos
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Produtos Lidos
 */
int getSGVprodL(SGV sgv) {
    return sgv->info->prodL;
}

/**
 * @brief     Função que retorna o caminho do Ficheiro dos Produtos
 * @param sgv Estrutura SGV
 * @return    Caminho do Ficheiro dos Produtos 
 */
char* getSGVprodPath(SGV sgv) {
    return sgv->info->fileProd;
}

/**
 * @brief       Função que retorna o numero de Clientes Validados
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Clientes Validados
 */
int getSGVcliV(SGV sgv) {
    return sgv->info->cliV;
}

/**
 * @brief       Função que retorna o numero de Clientes Lidos
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Clientes Lidos
 */
int getSGVcliL(SGV sgv) {
    return sgv->info->cliL;
}

/**
 * @brief     Função que retorna o caminho do Ficheiro dos Clientes
 * @param sgv Estrutura SGV
 * @return    Caminho do Ficheiro dos Clientes 
 */
char* getSGVcliPath(SGV sgv) {
    return sgv->info->fileCli;
}

/**
 * @brief       Função que retorna o numero de Vendas Validadas
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Vendas Validadas
 */
int getSGVsaleV(SGV sgv) {
    return sgv->info->saleV;
}

/**
 * @brief       Função que retorna o numero de Vendas Lidas
 * @param sgv   Estrutura SGV
 * @return      Inteiro com o numero de Vendas Lidas
 */
int getSGVsaleL(SGV sgv) {
    return sgv->info->saleL;
}

/**
 * @brief     Função que retorna o caminho do Ficheiro das Vendas
 * @param sgv Estrutura SGV
 * @return    Caminho do Ficheiro das Vendas 
 */
char* getSGVsalePath(SGV sgv) {
    return sgv->info->fileSale;
}

/**
 * @brief       Função que retorna o tamanho de uma lista de um Catalogo, chamando a função getCatListSize
 * @param sgv   Apontador para SGV
 * @param hash  Argumento da função getCatListSize
 * @param type  Flag que representa se o catálogo é de produtos ou de clientes
 * @return      Tamanho de uma lista de um Catalogo
 */
int getCListsize(SGV sgv,int hash,int type) {
  if(type == 0)
    return getCatListSize(sgv->prod,hash);

  return getCatListSize(sgv->cli,hash);
}

/**
 * @brief       Função devolve uma chave de um Catalogo, chamando a função getCatKey
 * @param sgv   Apontador para o SGV
 * @param type  Flag que representa se o catálogo é de produtos ou de clientes
 * @param i     Argumento da função getCatListSize
 * @param j     Argumento da função getCatListSize
 * @return      Apontador para a Key
 */
char* getCKey(SGV sgv,int type,int i,int j) {
  if(type == 0)
    return getCatKey(sgv->prod,i,j);

  return getCatKey(sgv->cli,i,j);
}

/**
 * @brief         Função procura uma key num Catalogo
 * @param sgv     Estrutura SGV
 * @param type    Flag que representa se o catálogo é de produtos ou de clientes
 * @param key     Key a procurar  
 * @return        Inteiro com posição do objeto na Lista
 */
int getPos(SGV sgv,int type,char *key) {
  if(type == 0)
    return searchCat(key,sgv->prod);

  return searchCat(key,sgv->cli);
}

/**
 * @brief         Função retorna o numero de vendas do tipo N
 * @param sgv     Estrutura SGV
 * @param hash    Posição na Tabela de Hash
 * @param pos     Posição na Lista
 * @param branch  Posição Filial na Matriz
 * @param mes     Posição Mes na Matriz
 * @return        Inteiro com o numero de vendas do tipo N
 */
int getFVendasN(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatVendasN(sgv->fact,hash,pos,branch,mes);
}

/**
 * @brief         Função retorna o numero de vendas do tipo P
 * @param sgv     Estrutura SGV
 * @param hash    Posição na Tabela de Hash
 * @param pos     Posição na Lista
 * @param branch  Posição Filial na Matriz
 * @param mes     Posição Mes na Matriz
 * @return        Inteiro com o numero de vendas do tipo P
 */
int getFVendasP(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatVendasP(sgv->fact,hash,pos,branch,mes);
}

/**
 * @brief         Função retorna a faturação do tipo N
 * @param sgv     Estrutura SGV
 * @param hash    Posição na Tabela de Hash
 * @param pos     Posição na Lista
 * @param branch  Posição Filial na Matriz
 * @param mes     Posição Mes na Matriz
 * @return        Float com a faturação do tipo N 
 */
float getFFaturacaoN(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatFaturacaoN(sgv->fact,hash,pos,branch,mes);
}

/**
 * @brief         Função retorna a faturação do tipo P
 * @param sgv     Estrutura SGV
 * @param hash    Posição na Tabela de Hash
 * @param pos     Posição na Lista
 * @param branch  Posição Filial na Matriz
 * @param mes     Posição Mes na Matriz
 * @return        Float com a faturação do tipo P
 */
float getFFaturacaoP(SGV sgv,int hash,int pos,int branch,int mes) {
  return getFatFaturacaoP(sgv->fact,hash,pos,branch,mes);
}

/**
 * @brief       Função devolve um apontador para GFiliais
 * @param sgv   Estrutura SGV
 * @return      Apontador para GFiliais
 */
void* getSGVGFiliais(SGV sgv) {
  return sgv->gfil;
}

/**
 * @brief       Função devolve um apontador para Catalogo de Clientes
 * @param sgv   Estrutura SGV
 * @return      Apontador para Catalogo de Clientes
 */
void* getSGVCli(SGV sgv) {
  return sgv->cli;
}

/**
 * @brief       Função devolve um apontador para Fact
 * @param sgv   Estrutura SGV
 * @return      Apontador para Fact
 */
void* getSGVFact(SGV sgv) {
  return sgv->fact;
}

/**
 * @brief       Função devolve um apontador para Catalogo de Produtos
 * @param sgv   Estrutura SGV
 * @return      Apontador para Catalogo de Produtos
 */
void* getSGVProd(SGV sgv) {
  return sgv->prod;
}
