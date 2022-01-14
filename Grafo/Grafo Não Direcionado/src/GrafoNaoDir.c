#include "GrafoNaoDir.h"

grafoNaoDir* criarGrafoNaoDir(){
	grafoNaoDir* grafo = (grafoNaoDir*) malloc(sizeof(grafoNaoDir));

	if (grafo == NULL){
    	printf("Erro ao criar grafo não direcionado.\n");
    	return NULL;
	}

	grafo->totalArestas = 0;
	grafo->totalVertices = 0;

	return grafo;
}