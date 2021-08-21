#include <stdlib.h>
#include <stdio.h>
#include "../include/ArvoreBinaria.h"

struct noArvore{
    int num;
    struct noArvore* esquerda;
    struct noArvore* direita;
};

noArvore* arvoreCria(int num){
    noArvore* ar = (noArvore*) malloc(sizeof(noArvore));

    if (ar == NULL) return NULL;

    ar->num = num;
    ar->esquerda = NULL;
    ar->direita = NULL;

    return ar;
}

void arvoreDestroi(noArvore* ar){
    if (ar != NULL){
       if (ar->esquerda != NULL) arvoreDestroi(ar->esquerda);
       if (ar->direita != NULL) arvoreDestroi(ar->direita);

       free(ar);
    }
}

int arvoreInsere(noArvore* ar, int elem){
    if (ar == NULL || elem == ar->num) return 0;

    if (elem < ar->num && ar->esquerda == NULL) ar->esquerda = arvoreCria(elem);
    else if (elem < ar->num) arvoreInsere(ar->esquerda, elem);

    if (elem > ar->num && ar->direita == NULL) ar->direita = arvoreCria(elem);
    else if (elem > ar->num) arvoreInsere(ar->direita, elem);

    return 1;
}

int arvoreRemove(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* aux;

    if (elem < ar->num) arvoreRemove(ar->esquerda, elem);
    else if (elem > ar->num) arvoreRemove(ar->direita, elem);
    else{
        if (ar->esquerda == NULL && ar->direita == NULL) ar = NULL;
        if (ar->esquerda != NULL && ar->direita == NULL){
            aux = ar->esquerda;
            ar->num = aux->num;
            free(aux);
        }
        else if (ar->direita != NULL && ar->esquerda == NULL){
            aux = ar->direita;
            ar->num = aux->num;
            free(aux);
        }
        else{
            aux = ar;
            while (aux != NULL && aux->esquerda != NULL) aux = aux->esquerda;
            ar->num = aux->num;
            free(aux);
        }
    }

    return 1;
}

int emOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    preOrdem(ar->esquerda);
    printf("%d ", ar->num);
    preOrdem(ar->direita);

    return 1;
}

int preOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    printf("%d ", ar->num);
    preOrdem(ar->esquerda);
    preOrdem(ar->direita);

    return 1;
}

int posOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    preOrdem(ar->esquerda);
    preOrdem(ar->direita);
    printf("%d ", ar->num);

    return 1;
}
