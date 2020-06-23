/**
 * @file  interpretador.c
 * @brief Ficheiro que contém funções relativas ao módulo Interface
 */

#include "interpretador.h"

#define MAX 100

/**
 *@brief   função que verifica se uma String tem ou nao o carater espaço
 *@param s String a ser verificada
 *@return  inteiro booleano que representa a existência ou não do carater espaço na String
 */
int temEspaco(char* s) {
  int r = 0, i;
  for(i=0; s[i] && !r; i++)
    if(s[i] == ' ') r = 1;

  return r;
}

/**
 *@brief função que define o interpretador
 *@param sgv sistema de gestão de vendas a ser interpretado
 */
void interpretador(SGV sgv) {
    int r=1, querie=0, load=0;
    char *buffer = malloc(MAX*sizeof(char)), *s;

    welcome();
    menu();

    while(r) {
        printf("\n\nIntroduza o seu comando: ");
        s = fgets(buffer, MAX, stdin);

        if(temEspaco(s))
            printf("Comando inválido\n");

        else {
            buffer = strtok(s, "\n");

            if(strcmp(s, "menu") == 0) {
              system("clear");
              menu();
            }

            else if(strcmp(s, "q")==0 || strcmp(s, "Q")==0)
              r=0;

            else if(atoi(s)!=1 && atoi(s)!=0 && load==0)
              printf("O SGV ainda não foi carregado\n");

            else switch((querie = atoi(s))) {
                  case 1:
                      sgv = runQuerie1e13(sgv, load);
                      if(sgv == NULL)
                        load = 0;
                      else
                        load = 1;
                      break;

                  case 2:
                      runQuerie2(sgv);
                      break;

                  case 3:
                      runQuerie3(sgv);
                      break;

                  case 4:
                      runQuerie4(sgv);
                      break;

                  case 5:
                      runQuerie5(sgv);
                      break;

                  case 6:
                      runQuerie6(sgv);
                      break;

                  case 7:
                      runQuerie7(sgv);
                      break;

                  case 8:
                      runQuerie8(sgv);
                      break;

                  case 9:
                      runQuerie9(sgv);
                      break;

                  case 10:
                      runQuerie10(sgv);
                      break;

                  case 11:
                      runQuerie11(sgv);
                      break;

                  case 12:
                      runQuerie12(sgv);
                      break;

                  default:
                      printf("Comando inválido\n");
                      break;
              }
        }
    }

    printf("\nA Sair do Programa\n\n");

    if(load == 1)
      destroySGV(sgv);

    free(buffer);
    buffer = NULL;
}
