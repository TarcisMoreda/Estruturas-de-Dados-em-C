#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
Aloca a memória para a pilha
Checa se a alocação foi bem sucedida
Define os valores iniciais das pontas da pilha
Retorna o ponteiro para a pilha criada
*/
pilha* pilhaCria(){
   pilha* pi = (pilha*) malloc(sizeof(pilha));

   if (pi == NULL){
      printf("Erro ao criar pilha.\n");
      return NULL;
   }

   pi->inicio = NULL;
   pi->tamanho = 0;

   return pi;
}

/*
Checa se a pilha existe
Um ponteiro de pilha(aux) é criado
Um ponteiro de elemento(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Os elementos de aux depois do primeiro referenciam a pilha original
O primeiro elemento de aux é declarado como o dado novo
A pilha passa a referenciar o mesmo ponto que aux.
A contagem do tamanho da pilha é aumentada
*/
int pilhaInsere(pilha *pi, dados dado){
   if (pi == NULL) return 0;

   elemento* novo = (elemento*) malloc(sizeof(elemento));
   novo->dado = dado;

   novo->prox = pi->inicio;
   pi->inicio = novo;

   ++(pi->tamanho);
   return 1;
}

/*
Checa se a pilha existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da pilha
O início da pilha é substituído pelo próximo elemento da pilha
Se o novo elemento inicial da pilha for nulo o fim também é nulo
Libera-se a memória do ponteiro aux
Diminui a contagem do tamanho da pilha
*/
int pilhaRemove(pilha *pi){
   if (pi == NULL || pi->inicio == NULL) return 0;

   elemento* aux = pi->inicio;
	pi->inicio = pi->inicio->prox;

   free(aux);
   --(pi->tamanho);
   return 1;
}

/*
Checa se a pilha existe e se algum elemento existe
Um ponteiro elemento(aux) é criado e referencia o início da pilha
Outro ponteiro elemento(aux2) é criado e é definido como nulo
Um loop é feito enquanto a pilha não estiver vazia
   O ponteiro aux2 passa a referenciar o elemento que vem depois do aux
   Libera-se a memória do ponteiro aux
   O ponteiro aux passa a referenciar o mesmo elemento do ponteiro aux2
   Diminui a contagem do tamanho da pilha
*/
int pilhaLimpa(pilha* pi){
   if (pi == NULL || pi->inicio == NULL) return 0;

   while (pi->inicio != NULL){
      pilhaRemove(pi);
      --(pi->tamanho);
   }

   return 1;
}

/*
Checa se a pilha existe
A função pilhaLimpa() limpa todos os dados da pilha
Libera-se a memória da pilha
*/
void pilhaDestroi(pilha* pi){
   if (pi == NULL) return;

   pilhaLimpa(pi);
   free(pi);

   return;
}