#include <stdlib.h>
#include <stdio.h>

#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

typedef struct{
    int num;
    struct noArvore* esquerda;
    struct noArvore* direita;
} noArvore;

noArvore* arvoreCria(int elem);
int arvoreInsere(noArvore* ar, int elem);
int arvoreRemove(noArvore* ar, int elem);
void arvoreDestroi(noArvore* ar);
int emOrdem(noArvore* ar);
int preOrdem(noArvore* ar);
int posOrdem(noArvore* ar);

#endif