/*================================
   LISTA SEQUENCIAL.C
=================================*/

/* DEFINIÇÕES
***************/

#include"listaSequencial.h"
#include<stdio.h>
#include<stdlib.h>

// Definição do tipo lista
struct lista{
   int qtd;     
   struct aluno dados[MAX];
};

/* IMPLEMENTACOES
***************/

Lista* listaCria(){
   Lista *li;
   li = (Lista*) malloc(sizeof(struct lista));

   if(li != NULL)
      li->qtd = 0;

   return li;

}//fim[listaCria]

void listaDestroi(Lista *li){
   free(li);
}//fim[listaDestroi]

int listaTamanho(Lista *li){
   if(li == NULL)
      return -1;
   else
      return li->qtd; // (*li).qtd

}//fim[listaTamanho]

int listaCheia(Lista* li){

   if(li == NULL)
      return -1;

   return (li->qtd == MAX);

}//fim[listaCheia]

int listaVazia(Lista* li){

   if(li == NULL)
      return -1;

   return (li->qtd == 0);

}//fim[listaVazia]

int listaInsereFinal(Lista* li, struct aluno al){
   if(li == NULL)
      return 0; // NA0

   if(listaCheia(li))
      return 0; // NAO

   li->dados[li->qtd] = al;
   li->qtd++;
   return 1; // S1M

}//fim[listaInsereFinal]

int listaInsereInicio(Lista* li, struct aluno al){
   int i; // Para laços

   if(li == NULL)
      return 0; // NA0

   if(listaCheia(li))
      return 0; // NAO

   for(i = li->qtd-1; i >= 0; i--)
      li->dados[i+1] = li->dados[i];

   li->dados[0] = al; 
   li->qtd++;

   return 1; // S1M

}//fim[listaInsereFinal]

int listaInsereOrdenado(Lista* li, struct aluno al){

   int k, i; // para laços

   if(li == NULL)
      return 0; // NA0

   if(listaCheia(li))
      return 0; // NA0

   // Fazendo uma busca:
   i = 0;
   while(i < li->qtd && li->dados[i].matricula < al.matricula)
      i++;

   for(k = li->qtd-1; k >= i; k--)
      li->dados[k+1] = li->dados[k];

   li->dados[i] = al;
   li->qtd++;
   return 1;  // SIM;

}//fim[listaInsereOrdenado]

int listaRemoveFinal(Lista* li){

   if(li == NULL)
      return 0; // NA0

   if(listaVazia(li))
      return 0; // NA0

   li->qtd--;
   return 1; // S1M

}//fim[listaRemoveFinal]

int listaRemoveInicio(Lista* li){

   int k; // para laços
   
   if(li == NULL)
      return 0; // NA0

   if(listaVazia(li))
      return 0; // NA0

   for(k = 0; k < li->qtd -1; k++)
      li->dados[k] = li->dados[k+1];

   li->qtd--;
   return 1; // S1M

}//fim[listaRemoveInicio]

int listaRemove(Lista* li, int mat){

   int k, i; // para laços

   if(li == NULL)
      return 0; // NA0

   if(listaVazia(li))
      return 0; // NA0

   // Fazendo a busca
   i = 0;
   while(i < li->qtd && li->dados[i].matricula != mat)
      i++;

   // Não Encontrou?
   if(i == li->qtd)
      return 0;

   for(k = i; k < li->qtd-1; k++)
      li->dados[k] = li->dados[k+1];

   li->qtd--;

   return 1;   // S1M

}//fim[listaRemove]

int listaConsultaPos(Lista*li, int pos, struct aluno *al){

   if(li == NULL || pos <= 0 || pos > li->qtd)
      return 0; // NA0

   *al = li->dados[pos-1];
   return 1;    // S1M

}//fim[listaConsultaPos]



int listaConsultaMat(Lista*li, int mat, struct aluno *al){

   int k, i;

   if(li == NULL)
      return 0;  // NA0

   // Fazendo a busca
   i = 0;
   while(i < li->qtd && li->dados[i].matricula != mat)
      i++;

   // Não Encontrou?
   if(i == li->qtd)
      return 0; // NA0

   *al = li->dados[i];
   return 1;  // S1M

}//fim[listaConsultaMat]

int listaImprime(Lista* li){

   int i;
   i = 0;
   printf("Relatorio: -----\n");
   while(i < li->qtd){
      printf("Matricula:\t%d\n", li->dados[i].matricula);
      printf("Nome:\t\t%s\n", li->dados[i].nome);
      printf("Nota1:%.2f\tNota2:%.2f\tNota3:%.2f\n\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
      i++;
   }
   printf("---------------\n");

   return 1;
   
}//fim[listaImprime]







