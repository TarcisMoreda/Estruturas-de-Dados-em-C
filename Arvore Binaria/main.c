#include "include/ArvoreBinaria.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    noArvore* raiz = arvoreCria(4);
    int auxInt;

    arvoreInsere(raiz, 3);
    arvoreInsere(raiz, 5);
    arvoreInsere(raiz, 2);
    arvoreInsere(raiz, 6);
    arvoreInsere(raiz, 1);
    arvoreInsere(raiz, 7);
    arvoreInsere(raiz, 6);
    arvoreInsere(raiz, 3);

    emOrdem(raiz);
    printf("\n");

    arvoreRemove(raiz, 7);

    emOrdem(raiz);
    printf("\n");

    arvoreDestroi(raiz);
    return 0;
}
