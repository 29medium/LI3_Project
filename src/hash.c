#include "headers.h"

// VERSAO DE TABELA DE HASH DO 4
int Hash4(char *nome,int tipo,int size) {
  int valor = size;

  unsigned long int sum = 5381;
  for(int i = 0; nome[i];i ++)
    sum = ((sum << 5) + sum) + nome[i];

/*
  valor /= 19;
  int chave = (nome[0] - 'A') * valor;
  valor /= 19;
  if (tipo == 1) {
    for(int i = 1; i < 6;i ++) {
      if(i == 1) {
        chave += (nome[1] - 'A') * valor;
        valor /= 10;
      }
      else {
        chave += (nome[1] - '0') * valor;
        valor /= 10;
      }
    }
  }
  else {
    for(int i = 1; i < 6;i ++)
      chave *= nome[1] - '0';
  }
*/
  return sum % size;
}

void TabelaHash4(ARR *a,THash4 *new,int tipo) {
  int c = 0;
  new -> size = a -> used * 2;
  new -> list = malloc((new -> size) * sizeof(Prod));
  for(int i = 0;i < new -> size; i ++) {
    new -> list[i].validade = 0;
    new -> list[i].nome = NULL;
  }
  int p;
  for(int i = 0; i < a -> used; i ++) {
    p = Hash4(a->list[i],tipo,new -> size);

    for(p;new->list[p].validade != 0;p = (p + 1) % new -> size,c++);

    //new->list[p].nome = malloc(SMAX * sizeof(char));
    //strcpy(new->list[p].nome,a -> list[i]);
    new->list[p].nome = a -> list[i];
    new->list[p].validade = 1;
  }
  printf("%d\n", c);
}

int procuraHT(THash4 *t,char *nome) {
  int p = Hash4(nome,1,t -> size);
  for(p;t->list[p].validade;p = (p + 1) % t -> size)
    if(!strcmp(t->list[p].nome,nome)) return 1;
  return 0;
}
