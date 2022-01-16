#include "Fila.h"

#include <stdio.h>

int main(int argc, char const *argv[]){
	fila* fi = filaCria();
	dados aux = {
		.nome = "Tárcis",
		.idade = 20
	};

	filaInsere(fi, aux);

	aux.nome = "Luis";
	aux.idade = 19;

	filaInsere(fi, aux);

	printf("%s\n", fi->inicio->dado.nome);

	filaRemove(fi);

	printf("%s\n", fi->inicio->dado.nome);

	filaDestroi(fi);

	return 0;
}
