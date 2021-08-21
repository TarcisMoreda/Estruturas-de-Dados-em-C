/*================================
   Fila DINÂMICA.C
=================================*/
#include<stdlib.h>
#include"FilaDinamica.h"


/* DEFINIÇÕES
***************/
struct fila{
   struct elemento *inicio;
   struct elemento *fim;
};

struct elemento{
   struct aluno dados;
   struct elemento *prox;
};

typedef struct elemento Elem;


/* IMPLEMENTACOES
***************/
Fila* filaCria(){

   Fila* fi = (Fila*) malloc (sizeof(Fila));

   // Alocação bem sucedida?
   if(fi != NULL){
      fi->fim = NULL;
      fi->inicio = NULL;
   }

   return fi;

}//fim[filaCria]

void filaDestroi(Fila* fi){

   // Fila válida?
   if(fi != NULL){
      Elem* no;
      while(fi->inicio != NULL){ 
         no = fi->inicio;               // auxiliar aponto pro inicio;
         fi->inicio = fi->inicio->prox; // inicio avança pro...
                                        // ...próximo elemento;
         free(no);                      // destrói o elemento inicial;
      }
   }
   // destruir o restante...
 
}//fim[filaDestroi]

int filaTamanho(Fila *fi){

   // Fila válida?
   if(fi == NULL)
      return 0;

   int cont = 0;

   Elem* no = fi->inicio;
   while(no != NULL){
      cont++;
      no = no->prox;
   }
   return cont;

}//fim[filaTamanho]

int filaCheia(Fila *fi){

   // Em implementações dinâmicas, uma fila somente é cheia quado
   // não há memória disponível no computador
   return 0;

}//fim[filaCheia]

int filaVazia(Fila *fi){

   // Fila válida?
   if(fi == NULL)
      return 1;

   // Fila vazia?
   if(fi->inicio == NULL)
      return 1; // S1M

   return 0;    // NA0
}//fim[filaVazia]

int filaInsere(Fila *fi, struct aluno al){

   // Fila válida?
   if(fi == NULL)
      return 0;

   Elem* no = (Elem*) malloc(sizeof(Elem));

   if(no == NULL)
      return 0;

   no->dados = al;
   no->prox = NULL;

   //Fila vazia?
   if(fi->fim == NULL)
      fi->inicio = no;
   else
      fi->fim->prox = no;

   fi->fim = no;
   return 1;

}//fim[filaInsere]

int filaRemove(Fila *fi){

   // Fila válida?
   if(fi == NULL)
      return 0;

   // Fila vazia?
   if(fi->inicio == NULL)
      return 0;

   Elem *no = fi->inicio;
   fi->inicio = fi->inicio->prox;

   if(fi->inicio == NULL)
      fi->fim = NULL;

   free(no);
   return 1;

}//fim[filaRemove]

int filaConsulta(Fila *fi, struct aluno *al){

   // Fila válida?
   if(fi == NULL)
      return 0;

   // Fila vazia?
   if(fi->inicio == NULL)
      return 0;

   *al = fi->inicio->dados;
   return 1;
}//fim[filaConsulta]



