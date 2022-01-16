#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

/*
Aloca a memória para a fila
Checa se a alocação foi bem sucedida
Define os valores iniciais das pontas da fila
Retorna o ponteiro para a fila criada
*/
fila* filaCria(){
   fila* fi = (fila*) malloc(sizeof(fila));

   if (fi == NULL){
      printf("Erro ao criar fila.\n");
      return NULL;
   }

   fi->inicio = NULL;
   fi->fim = NULL;
   fi->tamanho = 0;

   return fi;
}

/*
Checa se a fila existe
Um ponteiro de elemento(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Checa se o primeiro elemento da fila é nulo
Se sim o elemento novo é salvo no início
Se não ele é salvo após o fim da fila
O fim da fila é declarado como o elemento novo
A contagem do tamanho da fila é aumentada
*/
int filaInsere(fila *fi, dados dado){
   if (fi == NULL) return 0;

   elemento* novo = (elemento*) malloc(sizeof(elemento));
   novo->dado = dado;

   if (fi->inicio == NULL) fi->inicio = novo;
   else fi->fim->prox = novo;
   fi->fim = novo;

   ++(fi->tamanho);
   return 1;
}

/*
Checa se a fila existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da fila
O início da fila é substituído pelo próximo elemento da fila
Se o novo elemento inicial da fila for nulo o fim também é nulo
Libera-se a memória do ponteiro aux
Diminui a contagem do tamanho da fila
*/
int filaRemove(fila *fi){
   if (fi == NULL || fi->inicio == NULL) return 0;

   elemento* aux = fi->inicio;
	fi->inicio = fi->inicio->prox;

   if (fi->inicio == NULL) fi->fim = NULL;

   free(aux);
   --(fi->tamanho);
   return 1;
}

/*
Checa se a fila existe e se algum elemento existe
Um ponteiro elemento(aux) é criado e referencia o início da fila
Outro ponteiro elemento(aux2) é criado e é definido como nulo
Um loop é feito enquanto a fila não estiver vazia
   O ponteiro aux2 passa a referenciar o elemento que vem depois do aux
   Libera-se a memória do ponteiro aux
   O ponteiro aux passa a referenciar o mesmo elemento do ponteiro aux2
   Diminui a contagem do tamanho da fila
*/
int filaLimpa(fila* fi){
   if (fi == NULL || fi->inicio == NULL) return 0;

   while (fi->inicio != NULL){
      filaRemove(fi);
      --(fi->tamanho);
   }

   return 1;
}

/*
Checa se a fila existe
A função filaLimpa() limpa todos os dados da fila
Libera-se a memória da fila
*/
void filaDestroi(fila* fi){
   if (fi == NULL) return;

   filaLimpa(fi);
   free(fi);

   return;
}