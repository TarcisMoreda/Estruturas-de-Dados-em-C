#include "listaEncad.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	listaEncad* li = listaEncadCria();
	dados aux = {
		.nome = "Tárcis",
		.idade = 20
	};

	listaEncadInsere(li, aux);

	aux.nome = "Luis";
	aux.idade = 19;

	listaEncadInsere(li, aux);
	listaEncadInsere(li, aux);

	int a = listaEncadAcharPos(li, "Tárcis");
	aux = listaEncadConsultaPos(li, 0);

	printf("%d\n", a);
	printf("%s\n", aux.nome);

	listaEncadDestroi(li);

	return 0;
}
