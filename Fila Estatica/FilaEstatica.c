/*================================
   Fila ESTÁTICA.C
=================================*/
#include<stdlib.h>
#include"FilaEstatica.h"


/* DEFINIÇÕES
***************/
struct fila{
   int inicio, final, qtd;
   struct aluno dados[MAX];
};


/* IMPLEMENTACOES
***************/

Fila* filaCria(){

   Fila* fi = (Fila*) malloc(sizeof(struct fila));

   // Alocação bem sucedida?
   if(fi != NULL){
      fi->inicio = 0;
      fi->final = 0;
      fi->qtd = 0;
   }
   return fi;

}//fim[filaCria]

void filaDestroi(Fila* fi){
   free(fi);

}//fim[filaDestroid]

int filaTamanho(Fila *fi){

   // Fila válida?
   if(fi == NULL)
      return -1;

   return fi->qtd;

}//fim[filaTamanho]

int filaCheia(Fila *fi){

   // Fila válida?
   if(fi == NULL)
      return -1;

   if(fi->qtd == MAX)
      return 1;   // S1M
   else
      return 0;   // NA0

}//fim[filaCheia]

int filaVazia(Fila *fi){

   // Fila vazia?
   if(fi == NULL)
      return -1;

   if(fi->qtd == 0)
      return 1;   // S1M
   else
      return 0;   // NA0

}//fim[filaVazia]

int filaInsere(Fila *fi, struct aluno al){

   // Fila válida?
   if(fi == NULL)
     return 0;

   // Fila está cheia?
   if(filaCheia(fi))
     return 0;

   fi->dados[fi->final] = al;       // copiando dados;
   fi->final = (fi->final+1) % MAX; // atualizando o final...
                                    // ...(pode voltar no inicio)
   fi->qtd++;                       // aumentando quantidade
   return 1;

}//fim[filaInsere]

int filaRemove(Fila *fi){

   // Válida?
   // Vazia?
   if(fi == NULL || filaVazia(fi))
      return 0;

   // atualizando o inicio (pode chegar ao final)
   fi->inicio = (fi->inicio+1) % MAX; 
   fi->qtd--;
   return 1;

}//fim[filaRemove]

int filaConsulta(Fila *fi, struct aluno *al){

   // Válida?
   // Vazia?
   if(fi == NULL || filaVazia(fi))
      return 0;

   *al = fi->dados[fi->inicio];
   return 1;

}//fim[filaConsulta]






