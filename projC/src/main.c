/**
 * @file  main.c
 * @brief Ficheiro que contém a função main do projeto
 */

#include "interface.h"
#include "interpretador.h"

SGV sgv;

int main() {
  sgv = NULL;

  interpretador(sgv);

  return 0;
}