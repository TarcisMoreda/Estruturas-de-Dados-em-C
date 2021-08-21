/*================================
   PILHA ESTÁTICA.C
=================================*/
#include<stdlib.h>
#include"PilhaEstatica.h"


/* DEFINIÇÕES
***************/
struct pilha{
   int qtd;
   struct aluno dados[MAX];
};


/* IMPLEMENTACOES
***************/

Pilha* pilhaCria(){

   Pilha *pi;
   pi = (Pilha*) malloc(sizeof(struct pilha));

   // Validação da alocação
   if(pi != NULL)
      pi->qtd = 0;

   return pi;
}//fim[pilhaCria]

void pilhaDestroi(Pilha* pi){

   free(pi);

}//fim[pilhaDestroi]

int pilhaTamanho(Pilha *pi){

   // Verificando se a pilha é válida
   if(pi == NULL)
      return -1;
   else
      return pi->qtd;

}//fim[pilhaTamanho]

int pilhaCheia(Pilha *pi){

   // Verificando se a pilha é válida
   if(pi == NULL)
      return -1;

   // S1M ou NA0
   return (pi->qtd == MAX);
  
}//fim[pilhaCheia]

int pilhaVazia(Pilha *pi){

   // Verificando se a pilha é válida
   if(pi == NULL)
      return -1;

   // S1M ou NA0
   return (pi->qtd == 0);
  
}//fim[pilhaVazia]

int pilhaInsere(Pilha *pi, struct aluno al){

   // Verificando se a pilha é válida
   if(pi == NULL)
      return 0;

   // Verificando se a pilha está cheia
   if(pilhaCheia(pi))
      return 0;

   pi->dados[pi->qtd] = al;
   pi->qtd++;
   return 1;

}//fim[pilhaInsere]

int pilhaRemove(Pilha *pi){

   // Pilha válida?
   // Pilha vazia?
   if(pi == NULL || pi->qtd == 0)
      return 0;

   pi->qtd--;
   return 1;

}//fim[pilhaRemove]

int pilhaConsulta(Pilha *pi, struct aluno *al){

   // Pilha válida?
   // Pilha vazia?
   if(pi == NULL || pi->qtd == 0)
      return 0;

   *al = pi->dados[pi->qtd-1];
   return 1;

}//fim[pilhaConsulta]

