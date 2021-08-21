#ifndef ARVORE_BINARIA
#define  ARVORE_BINARIA

typedef struct noArvore noArvore;

noArvore* arvoreCria(int num);
void arvoreDestroi(noArvore* ar);
int arvoreInsere(noArvore* ar, int elem);
int arvoreRemove(noArvore* ar, int elem);
int emOrdem(noArvore* ar);
int preOrdem(noArvore* ar);
int posOrdem(noArvore* ar);

#endif
