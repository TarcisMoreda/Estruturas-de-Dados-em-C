#include "ListaDuplaEncad.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
	listaDuplaEncad* li = listaDuplaEncadCria();
	dados aux = {
		.nome = "Tárcis",
		.idade = 20
	};

	listaDuplaEncadInsere(li, aux);

	aux.nome = "Luis";
	aux.idade = 19;

	listaDuplaEncadInsere(li, aux);
	listaDuplaEncadInsere(li, aux);

	int a = listaDuplaEncadAcharPos(li, "Tárcis");
	aux = listaDuplaEncadConsultaPos(li, 0);

	printf("%d\n", a);
	printf("%s\n", aux.nome);

	listaDuplaEncadDestroi(li);

	return 0;
}
