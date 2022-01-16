#include "Pilha.h"

#include <stdio.h>

int main(int argc, char const *argv[]){
	pilha* pi = pilhaCria();
	dados aux = {
		.nome = "Tárcis",
		.idade = 20
	};

	pilhaInsere(pi, aux);

	aux.nome = "Luis";
	aux.idade = 19;

	pilhaInsere(pi, aux);

	printf("%s\n", pi->inicio->dado.nome);

	pilhaRemove(pi);

	printf("%s\n", pi->inicio->dado.nome);

	pilhaDestroi(pi);

	return 0;
}
