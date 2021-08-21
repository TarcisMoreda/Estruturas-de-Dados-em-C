#include<stdio.h>
#include<stdlib.h>
#include"ListaDinEncadDupla.h"

struct elemento{
   struct elemento *ant;
   struct aluno dados;
   struct elemento *prox;
};

typedef struct elemento Elem;


Lista* listaCria(){

   Lista* li = (Lista*) malloc(sizeof(Lista));

   // Verificando alocação
   if(li != NULL)
      *li = NULL;
   return li;

}//fim[listaCria]

void listaDestroi(Lista* li){

   if(li != NULL){
      Elem* no;
      while((*li) != NULL){
         no = *li;
         *li = (*li)->prox;
         free(no);
      }
      free(li);
   }

}//fim[listaDestroi]

int listaTamanho(Lista* li){

   // Lista nula?
   if(li == NULL) return 0;

   int cont = 0;

   Elem* no = *li;

   while(no != NULL){
      cont++;
      no = no->prox;
   }
   return cont;

}//fim[listaTamanho]

int listaCheia(Lista* li){

   return 0;

}//fim[listaCheia]

int listaVazia(Lista* li){

   if(li == NULL)
      return 1;
   if(*li == NULL)
      return 1;

   return 0;

}//fim[listaVazia]

int listaInsereInicio(Lista* li, struct aluno al){

   if(li == NULL) return 0;
   
   Elem* no = (Elem*) malloc(sizeof(Elem));
   if(no == NULL) return 0;

   no->dados = al;
   no->prox = (*li);
   no->ant = NULL;

   // Se a lista nao estava vazia, devemos
   // apontar pro no anterior
   if(*li != NULL) 
      (*li)->ant = no;
   *li = no;

   return 1;

}//fim[listaInsereInicio]

int listaInsereFinal(Lista *li, struct aluno al){

   if(li == NULL) return 0;
   
   Elem* no = (Elem*) malloc(sizeof(Elem));
   if(no == NULL) return 0;

   no->dados = al;
   no->prox = NULL;

   // Lista vazia?
   if((*li) == NULL){
      no->ant = NULL;
      *li = no;
   }
   else{
      Elem *aux = *li;
      while(aux->prox != NULL)
         aux = aux-> prox;
      aux->prox = no;
      no->ant = aux;
   }
   return 1;

}//fim[listaInsereFinal]

int listaInsereOrdenado(Lista *li, struct aluno al){

   if(li == NULL) return 0;
   
   Elem* no = (Elem*) malloc(sizeof(Elem));
   if(no == NULL) return 0;

   no->dados = al;

   if(listaVazia(li)){
      no->prox = NULL;
      no->ant = NULL;
      *li = no;
      return 1;
   }
   else{
      Elem *ante, *atual = *li;
      // Percorrendo a lista
      while(atual != NULL && atual->dados.matricula < al.matricula){
         ante = atual;
         atual = atual->prox;
      }
      if(atual == *li){   //sera o primeiro elemento
         no->ant = NULL;
         (*li)->ant = no;
         no->prox = (*li);
         *li = no;
      }
      else{ // sera no meio ou no final
         no->prox = ante->prox;
         no->ant = ante;
         ante->prox = no;
         if(atual != NULL)
            atual->ant = no;
      }
      return 1;
   }

}//fim[listaInsereOrdenado]

int listaRemoveInicio(Lista *li){

   if(li == NULL)
      return 0;

   if((*li) == NULL)
      return 0;

   Elem *no = *li;
   *li = no->prox;
   if(no->prox != NULL)
      no->prox->ant = NULL;

   free(no);
   return 1;

}//fim[listaRemoveInicio]

int listaRemoveFinal(Lista *li){

   if(li == NULL)
      return 0;

   if((*li) == NULL)
      return 0;

   Elem *no = *li;
   while(no->prox != NULL)
      no = no->prox;

   /// Remover o primeiro elemento?
   if(no->ant == NULL)
      *li = no->prox;
   else
      no->ant->prox = NULL;

   free(no);
   return 1;

}//fim[listaRemoveFinal]

int listaRemove(Lista *li, int mat){

   if(li == NULL)
      return 0;

   Elem *no = *li;
   while(no != NULL && no->dados.matricula != mat){
      no = no->prox;
   }
   // Não encontrado?
   if(no == NULL) 
      return 0;

   // Remover o primeiro elemento?
   if(no->ant == NULL)
      *li = no->prox;
   else
      no->ant->prox = no->prox;

   // Não é o último?
   if(no->prox != NULL)
      no->prox->ant = no->ant;

   free(no);
   return 1;   

}//fim[listaRemove]

int listaConsultaPos(Lista *li, int pos, struct aluno *al){

   if(li == NULL || pos <= 0) return 0;
   Elem *no = *li;
   int i = 1;

   while(no != NULL && i < pos){
      no = no->prox;
      i++;
   }
   if(no == NULL)
      return 0;

   else{
      *al = no->dados;
      return 1;
   }

}//fim[listaConsultaPos]

int listaConsultaMat(Lista *li, int mat, struct aluno *al){

   if(li == NULL) return 0;
   Elem *no = *li;

   while(no != NULL && no->dados.matricula != mat){
      no = no->prox;
   }
   if(no == NULL)
      return 0;
   else{
      *al = no->dados;
      return 1;
   }

}//fim[listaConsultaPos]

int listaImprime(Lista *li){

   Elem *no = *li;

   printf("Relatorio: -----\n");
   while(no != NULL){

      printf("Matricula:\t%d\n", no->dados.matricula);
      printf("Nome:\t\t%s\n", no->dados.nome);
      printf("Nota1:%.2f\tNota2:%.2f\tNota3:%.2f\n\n", no->dados.n1, no->dados.n2, no->dados.n3);
      no = no->prox;
   }

   printf("---------------\n");
   return 1;

}//fim[listaImprime]













