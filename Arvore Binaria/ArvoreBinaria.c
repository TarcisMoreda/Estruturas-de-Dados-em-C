#include "ArvoreBinaria.h"

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

int arvoreInsere(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* novo = (noArvore*) malloc(sizeof(noArvore));
    novo->num = elem;
    novo->esquerda = NULL;
    novo->direita = NULL;

    arvoreInsereAux(ar, novo);

    return 1;
}

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

void arvoreDestroi(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) arvoreDestroi(ar->esquerda);
    else if (ar->direita != NULL) arvoreDestroi(ar->direita);
    free(ar);

    return 1;
}

int emOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    printf("%d ", ar->num);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

int preOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    printf("%d ", ar->num);
    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

int posOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);
    printf("%d ", ar->num);

    return 1;
}