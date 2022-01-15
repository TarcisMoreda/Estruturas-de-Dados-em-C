#include "ArvoreBinaria.h"

int main(int argc, char const *argv[]){
	noArvore* arvore = arvoreCria(6);

	for (int i=0; i<10; ++i)
	arvoreInsere(arvore, i);

	preOrdem(arvore);
	printf("\n");

	arvoreRemove(arvore, 6);

	preOrdem(arvore);
	printf("\n");
 
	arvoreDestroi(arvore);

	return 0;
}