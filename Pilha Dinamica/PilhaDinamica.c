/*================================
   PILHA DINÂMICA.C
=================================*/
#include<stdlib.h>
#include"PilhaDinamica.h"


/* DEFINIÇÕES
***************/

struct elemento{
   struct aluno dados;    // dado armazenado
   struct elemento *prox; // ponteiro pro próximo elemento
};

// Simplificando
typedef struct elemento Elem;

/* IMPLEMENTACOES
***************/

Pilha* pilhaCria(){

   // criando o topo da pilha
   Pilha* pi = (Pilha*) malloc (sizeof(Pilha));

   // Alocação bem sucedida?
   if(pi != NULL)
      *pi = NULL;

   return pi;

}//fim[pilhaCria]

void pilhaDestroi(Pilha* pi){

   // Pilha válida?
   if(pi != NULL){

      // Varrendo a pilha e desalocando cada elemento
      Elem* no;
      while((*pi) != NULL){
         no = *pi;           // auxiliar recebe topo;
         *pi = (*pi)->prox;  // topo avança pro próximo;
         free(no);           // destrói o nó.
      }
      free(pi);              // libera a pilha
   }

}//fim[pilhaDestroi]

int pilhaTamanho(Pilha *pi){

   // Pilha válida?
   if(pi == NULL) return 0;

   int cont = 0;
   Elem* no = *pi;
   while(no != NULL){
      cont++;
      no = no->prox;
   }
   return cont;

}//fim[pilhaTamanho]

int pilhaCheia(Pilha *pi){

   // A pilha é dinâmica.
   // Desse modo, não existe pilha cheia;
   // Somente quando não restar memória no computador
   return 0;

}//fim[pilhaCheia]

int pilhaVazia(Pilha *pi){

   // Se for inválida?
   if(pi == NULL) return 1;

   // Se topo aponta pra NULL
   if(*pi == NULL)
      return 1;

   return 0;

}//fim[pilhaVazia]


int pilhaInsere(Pilha *pi, struct aluno al){

   // Pilha válida? 
   if(pi == NULL)
      return 0;

   Elem* no = (Elem*) malloc(sizeof(Elem));

   // Novo nó válido?
   if(no == NULL)
      return 0;

   no->dados = al;   // copiando dados

   no->prox = (*pi); // no aponta pro antigo topo
   *pi = no;         // topo aponta 
   return 1;

}//fim[pilhaInsere]

int pilhaRemove(Pilha *pi){

   // Pilha válida?
   if(pi == NULL)
      return 0;

   // Pilha vazia?
   if((*pi) == NULL)
      return 0;

   Elem *no = *pi;  // auxiliar aponto pro topo;
   *pi = no->prox;  // o topo aponto pro próximo, após o topo
   free(no);        // destrói o antigo topo.
   return 1;

}//fim[pilhaRemove]

int pilhaConsulta(Pilha *pi, struct aluno *al){

   // Pilha válida?
   if(pi == NULL)
      return 0;

   // Pilha vazia?
   if((*pi) == NULL)
      return 0;

   *al = (*pi)->dados; //copiandos os valores
   return 1;

}//fim[pilhaConsulta]






