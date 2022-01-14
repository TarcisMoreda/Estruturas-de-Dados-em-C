#include"ListaEncad.h"

/*
Aloca a memória para a lista
Checa se a alocação foi bem sucedida
Retorna o ponteiro para a lista criada
*/
listaEncad* listaEncadCria(){
   listaEncad* li = (listaEncad*) malloc(sizeof(listaEncad));

   if (li == NULL){
      printf("Erro ao criar lista encadeada.\n");
      return NULL;
   }

   return li;
}

/*
Checa se a lista existe
Um ponteiro de elemento(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Checa se o primeiro elemento da lista é nulo
Se sim o elemento novo é salvo no início
Se não, um ponteiro(aux) é criado e referencia o início da lista
Um loop é feito até chegar no último elemento da lista
O elemento após o último é definido como o novo. 
*/
int listaEncadInsere(listaEncad* li, dados dado){
   if (li == NULL) return 0;

   elemento* novo = (elemento*) malloc(sizeof(elemento));
   novo->dado = dado;
   novo->prox = NULL;

   if (*li == NULL){
      *li = novo;
      return 1;
   }

   elemento* aux = *li;
   while (aux->prox != NULL) aux = aux->prox;
   aux->prox = novo;

   return 1;
}

/*
Checa se a lista existe
Um ponteiro de elemento(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Checa se o primeiro elemento da lista é nulo
Se sim o elemento novo é salvo no início
Se não o elemento após o novo é definido como o primeiro elemento da lista
E a lista passa a referenciar o elemento novo.
*/
int listaEncadInsereInicio(listaEncad* li, dados dado){
   if (li == NULL) return 0;

   elemento* novo = (elemento*) malloc(sizeof(elemento));
   novo->dado = dado;
   novo->prox = NULL;

   if (*li == NULL){
      *li = novo;
      return 1;
   }

   novo->prox = *li;
   *li = novo;

   return 1;
}

/*
Checa se a lista existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um ponteiro de elemento(aux2) é criado e referencia o segundo elemento da lista
Checa se a posição é 0
Se sim muda-se a lista para referenciar o segundo elemento
E libera-se a memória do aux
Se não um loop é feito até chegar na posição
   Checa se o próximo elemento não é nulo e se está na última iteração do loop
   O aux passa a referenciar o próximo elemento da lista
   O aux2 passa a referenciar o elemento do aux
O elemento depois do aux passa a ser o elemento depois do aux2
Libera-se a memória do ponteiro aux2
*/
int listaEncadRemovePos(listaEncad *li, int pos){
   if (li == NULL || *li == NULL) return 0;

   elemento* aux = *li;
   elemento* aux2 = aux->prox;

   if (pos == 0){
      *li = (*li)->prox;
      free(aux);

      return 1;
   }

   for (int i=0; i<pos-1; ++i){
      if (aux->prox == NULL && i!=pos-2) return 0;
      aux = aux->prox;
      aux2 = aux->prox;
   }

   aux->prox = aux2->prox;
   free(aux2);

   return 1;
}

/*
Checa se a lista existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da lista
O início da lista passa a referenciar o segundo elemento
Libera-se a memória do ponteiro aux
*/
int listaEncadRemoveInicio(listaEncad* li){
   if (li == NULL || *li == NULL) return 0;

   elemento* aux = *li;
   *li = (*li)->prox;
   free(aux);

   return 1;
}

/*
Checa se a lista existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um ponteiro de elemento(aux2) é criado e referencia o segundo elemento da lista
Checa se o aux2 é nulo
Se não um loop é feito até chegar no final da lista
   O aux passa a referenciar o próximo elemento da lista
   O aux2 passa a referenciar o próximo elemento do aux
O elemento depois do aux passa a ser nulo
Libera-se a memória do ponteiro aux2
*/
int listaEncadRemoveFinal(listaEncad* li){
   if (li == NULL || *li == NULL) return 0;

   elemento* aux = *li;
   elemento* aux2 = aux->prox;

   if (aux2 != NULL)
   while (aux2->prox != NULL){
      aux = aux->prox;
      aux2 = aux->prox;
   }

   aux->prox = NULL;
   free(aux2);

   return 1;
}

/*
Checa se a lista existe e se algum elemento existe
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um ponteiro de elemento(aux2) é criado e referencia o segundo elemento da lista
Um loop é feito enquanto o próximo elemento não for nulo
   aux2 passa a referenciar o próximo item da lista
   Libera-se a memória do ponteiro aux
   O aux passa a referenciar a mesma coisa do aux2
*/
int listaEncadLimpa(listaEncad* li){
   if (li == NULL || *li == NULL) return 0;

   elemento* aux = *li;
   elemento* aux2 = NULL;

   while (aux->prox != NULL){
      aux2 = aux->prox;
      free(aux);
      aux = aux2;
   }

   return 1;
}

/*
Checa se a lista existe e se algum elemento existe
Um int é criado para guardar o número de elementos
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um loop é feito enquanto o próximo elemento não for nulo
   Aumenta a contagem do tamanho da lista
   O aux passa a referenciar o próximo item da lista
*/
int listaEncadTamanho(listaEncad *li){
   if (li == NULL || *li == NULL) return -1;

   int tamanho = 0;
   elemento* aux = *li;

   while (aux->prox != NULL){
      ++tamanho;
      aux = aux->prox;
   }

   return tamanho;
}

/*
Checa se a lista existe e se algum elemento existe
Um int é criado para guardar a posição do elemento
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um loop é feito enquanto o nome guardado na lista não for igual ao da pesquisa
   O aux passa a referenciar o próximo item da lista
   Aumenta a contagem da posição
*/
int listaEncadAcharPos(listaEncad *li, char* nome){
   if (li == NULL || *li == NULL) return -1;

   int pos = 0;
   elemento* aux = *li;

   while (strcmp(aux->dado.nome, nome) != 0){
      aux = aux->prox;
      ++pos;
   }

   return pos;
}

/*
Um dado é criado para guardar as informações
Checa se a lista existe e se algum elemento existe
Checa se a posição é 0
Um ponteiro de elemento(aux) é criado e referencia o início da lista
Um loop é feito até chegar na posição
   Checa se o próximo elemento não é nulo e se está na última iteração do loop
   O aux passa a referenciar o próximo elemento da lista
O dado passa a guardar o dado da lista
*/
dados listaEncadConsultaPos(listaEncad *li, int pos){
   dados dado = {
      .nome = "", 
      .idade = 0
   };

   if (li == NULL || *li == NULL) return dado;
   if (pos == 0) return (*li)->dado;

   elemento* aux = *li;

   for (int i=0; i<pos; ++i){
      if (aux->prox == NULL && i!=pos-1) return dado;
      aux = aux->prox;
   }

   dado = aux->dado;

   return dado;
}

/*
Checa se a lista existe
A função listaLimpa() limpa todos os dados da lista
Libera-se a memória da lista
*/
void listaEncadDestroi(listaEncad *li){
   if (li == NULL) return;

   listaEncadLimpa(li);
   free(li);

   return;
}