/*================================
   LISTA DINAMICA SEQUENCIAL.C
=================================*/
#include<stdio.h>
#include<stdlib.h>
#include"ListaDinEncad.h"


/* DEFINIÇÕES
***************/

struct elemento{
   struct aluno dados;    // conteúdo de cada elemento
   struct elemento *prox; // ponteiro pro próximo elemento
};

typedef struct elemento Elem;


/* IMPLEMENTACOES
***************/

Lista* listaCria(){

   Lista *li = (Lista*) malloc(sizeof(Lista));

   // Testando a alocação
   if(li != NULL)
     *li = NULL;

   return li;
 
}//fim[listaCria]

void listaDestroi(Lista *li){

   if(li != NULL){

      Elem* aux; // auxiliar pra eliminacao

      while((*li) != NULL){
         aux = *li;          // guardando o início.
         *li = (*li)->prox; // avançar o início da lista
         free(aux);          // eliminar o antigo início
      }
      free(li);

   }//fim[null]

}//fim[listaDrestroi]


int listaTamanho(Lista *li){

   int cont = 0;

   if(li == NULL)
      return cont;

   // Cuidado!
   // Não podemos utilizar a cabeça da lista nessa operação
   // Podemos perder a referência do começo!
   Elem* aux = *li;
   while(aux != NULL){
      cont++;
      aux = aux->prox;
   }
   return cont;

}//fim[listaTamanho]


int listaCheia(Lista *li){

   // Não existe conceito de lista cheia nesse modelo;
   // Cheia seria equivalente à memória cheia.
   return 0;

}//fim[listaCheia]

int listaVazia(Lista *li){

   // Testando se a lista é válida
   if(li == NULL)
      return 1;

   // Se válida, porem aponta pra NULL
   if(*li == NULL)
      return 1;

   // Caso contrário
   return 0;

}//fim[listaVazia]

int listaInsereInicio(Lista* li, struct aluno al){

   // Lista existe?
   if(li == NULL)
      return 0;

   // Criando o no
   Elem* aux = (Elem*) malloc(sizeof(Elem));
   if(aux == NULL)
      return 0;

   // Copiando dados e atualizando ponteiros
   aux->dados = al;
   aux->prox = (*li);
   *li = aux;

   return 1;

}//fim[listaInsereInicio]

int listaInsereFinal(Lista* li, struct aluno al){

   // Lista existe?
   if(li == NULL)
      return 0;

   // Criando o no
   Elem* no = (Elem*) malloc(sizeof(Elem));
   if(no == NULL)
      return 0;

   // Montando o no
   no->dados = al;
   no->prox = NULL;

   // Lista vazia?
   if((*li) == NULL){
      *li = no;
   }
   else{

      // Varrendo a lista
      Elem *aux = *li;
      while(aux->prox != NULL){
         aux = aux->prox;
      }
      aux->prox = no;
   }
   return 1;

}//fim[listaInsereFinal]

int listaInsereOrdenada(Lista* li, struct aluno al){

   // Lista existe?
   if(li == NULL)
      return 0;

   // Criando o no
   Elem *no = (Elem*) malloc(sizeof(Elem));
   if(no == NULL)
      return 0;

   // Montando o no
   no->dados = al;

   // Lista vazia?
   if((*li) == NULL){
      no->prox = (*li);
      *li = no;
      return 1;
   }
   // Procurar onde inserir
   else{
      Elem *ant;
      Elem *atual = *li;

      while(atual != NULL && atual->dados.matricula < al.matricula){
         ant = atual;
         atual = atual->prox;
      }

      // Esta no inicio?
      if(atual == *li){
         no->prox = (*li);
         *li = no;
      }
      else{
         no->prox = ant->prox;
         ant->prox = no;
      }
      
   }
   return 1;

}//fim[listaInsereOrdenada]

int listaRemoveInicio(Lista* li){

   // Lista válida?
   if(li == NULL)
      return 0;

   // Lista vazia?
   if((*li) == NULL)
      return 0;

   Elem *aux = *li;
   *li = aux->prox;
   free(aux);

   return 1;

}//fim[removeListaInicio]

int listaRemoveFinal(Lista* li){

   // Lista válida?
   if(li == NULL)
      return 0;

   // Lista vazia?
   if((*li) == NULL)
      return 0;

 
   Elem *ant;
   Elem *no = *li;
   while(no->prox != NULL){
      ant = no;
      no = no->prox;
   }

   //Remover o primeiro?
   if(no == (*li))
      *li = no->prox;
   else
      ant->prox = no->prox;

   free(no);
   return 1; 
   
}//fim[removeListaFinal]

int listaRemove(Lista *li, int mat){

   // Lista válida?
   if(li == NULL)
      return 0;

   Elem *ant;
   Elem *no = *li;

   while(no != NULL && no->dados.matricula !=  mat){
      ant = no;
      no = no->prox;
   }

   // Elemento não encontrado ou Lista vazia
   if(no == NULL)
      return 0;


   // Remover o primeiro?
   if(no == *li)
      *li = no->prox;
   else
      ant->prox = no->prox;

   free(no);
   return 1;

}//fim[listaRemove]

int listaConsultaPos(Lista *li, int pos, struct aluno *al){

   if(li == NULL || pos <= 0)
      return 0;

   Elem *no = *li;

   int i = 1;
   while(no != NULL && i < pos){
      no = no->prox;
      i++;
   }

   // Não achou o registro ou lista vazia?
   if(no == NULL)
      return 0;
   else
      *al = no->dados;
      return 1;


}//fim[listaConsultaPos]

int listaConsultaMat(Lista *li, int mat, struct aluno *al){

   if(li == NULL)
      return 0;

   Elem *no = *li;

   while(no != NULL && no->dados.matricula != mat){
      no = no->prox;
   }

   // Não achou o registro ou lista vazia?
   if(no == NULL) 
      return 0;
   else{
      *al = no->dados;
      return 1;
   }

}//fim[listaConsultaMat]

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















