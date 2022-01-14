#include <stdlib.h>
#include <stdio.h>

#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

//Struct que define o nó da árvore.
typedef struct noArvore{
    int num;
    struct noArvore* esquerda;
    struct noArvore* direita;
} noArvore;

//Prototipação das funções da árvore.
noArvore* arvoreCria(int elem);
int arvoreInsere(noArvore* ar, int elem);
int arvoreRemove(noArvore* ar, int elem);
void arvoreDestroi(noArvore* ar);
int emOrdem(noArvore* ar);
int preOrdem(noArvore* ar);
int posOrdem(noArvore* ar);

#endif