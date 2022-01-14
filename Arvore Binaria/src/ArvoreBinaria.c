#include "ArvoreBinaria.h"

/*
Aloca a memória para o primeiro nó da árvore
Checa se a alocação foi bem sucedida
Define o valor do primeiro elemento
Retorna o ponteiro para o nó criado
*/
noArvore* arvoreCria(int elem){
    noArvore* no = (noArvore*) malloc(sizeof(noArvore));

    if (no == NULL){
      printf("Erro ao criar árvore.\n");
      return NULL;
    }

    no->num = elem;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

/*
Checa se a árvore existe
Um ponteiro de nó(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Chama a função recursiva arvoreInsereAux()
*/
void arvoreInsereAux(noArvore* ar, noArvore* novo);
int arvoreInsere(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* novo = (noArvore*) malloc(sizeof(noArvore));
    novo->num = elem;
    novo->esquerda = NULL;
    novo->direita = NULL;

    arvoreInsereAux(ar, novo);

    return 1;
}

/*
Checa se o nó novo tem um valor maior que o nó atual
    Checa se o nó da esquerda existe
        Se sim chama-se a função recursivamente
        Se não salva o nó novo à esquerda do atual
Checa se o nó novo tem um valor menor que o nó atual
    Checa se o nó da direita existe
        Se sim chama-se a função recursivamente
        Se não salva o nó novo à direita do atual
*/
void arvoreInsereAux(noArvore* ar, noArvore* novo){
    if (novo->num < ar->num){
        if (ar->esquerda != NULL) arvoreInsereAux(ar->esquerda, novo);
        else ar->esquerda = novo;
    }
    else{
        if (ar->direita != NULL) arvoreInsereAux(ar->direita, novo);
        else ar->direita = novo;
    }

    return;
}

/*
Checa se a árvore existe
Um ponteiro de nó(atual) é criado
Um ponteiro de nó(anterior) é criado
Um loop é criado até chegar no nó desejado
    O anterior referencia o atual
    O atual referencia o próximo nó dependendo do valor elem
Checa se o nó da direita do atual não existe
    Checa de que lado o nó atual está em relacão ao anterior
        O nó anterior deixa de referenciar o atual e passa a referenciar o nó da esquerda do atual
    Libera-se a memória do ponteiro atual
Um ponteiro de nó(aux) é criado
Um ponteiro de nó(auxAnt) é criado
O aux passa a referenciar o nó da direita do atual
Um loop é criado até o aux referenciar o nó mais da esquerda
Checa se o nó da direita do aux existe
    Se sim o nó da esquerda do auxAnt passa a referenciar o nó da direita do aux
    Se não o nó da esquerda do auxAnt é nulo
Checa de que lado o nó atual está em relacão ao anterior
    O nó anterior deixa de referenciar o atual e passa a referenciar o nó aux
Os lados do nó aux passam a referenciar os mesmos do atual
Libera-se a memória do ponteiro atual
*/
int arvoreRemove(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* atual = ar;
    noArvore* anterior = NULL;

    while (atual->num != elem){
        anterior = atual;
        
        if (elem < atual->num)atual = atual->esquerda;
        else atual = atual->direita;

        if (atual == NULL) return 0;
    }

    if (atual->direita == NULL){
        if (anterior->esquerda == atual) anterior->esquerda = atual->esquerda;
        else if (anterior->direita == atual) anterior->direita = atual->esquerda;
        free(atual);

        return 1;
    }

    noArvore* aux = NULL;
    noArvore* auxAnt = NULL;

    auxAnt = atual;
    aux = atual->direita;

    while (aux->esquerda != NULL){
        auxAnt = aux;
        aux = aux->esquerda;
    }

    if (aux->direita != NULL) auxAnt->esquerda = aux->direita;
    else auxAnt->esquerda = NULL;

    if (anterior->esquerda == atual) anterior->esquerda = aux;
    else if (anterior->direita == atual) anterior->direita = aux;

    aux->esquerda = atual->esquerda;
    aux->direita = atual->direita;
    free(atual);

    return 1;
}

/*
Checa se a árvore existe
Checa os lados do nó atual e chama a função recursivamente
Libera-se a memória da árvore
*/
void arvoreDestroi(noArvore* ar){
    if (ar == NULL) return;

    if (ar->esquerda != NULL) arvoreDestroi(ar->esquerda);
    else if (ar->direita != NULL) arvoreDestroi(ar->direita);
    free(ar);
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó da esquerda -> Nó do meio -> Nó da direita
*/
int emOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    printf("%d ", ar->num);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó do meio -> Nó da esquerda -> Nó da direita
*/
int preOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    printf("%d ", ar->num);
    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó da esquerda -> Nó da direita -> Nó do meio 
*/
int posOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);
    printf("%d ", ar->num);

    return 1 ;
}