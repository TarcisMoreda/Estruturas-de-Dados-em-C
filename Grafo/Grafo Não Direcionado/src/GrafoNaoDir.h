#include <stdio.h>
#include <stdlib.h>

#if !defined(GRAFO_NAO_DIR)
#define GRAFO_NAO_DIR

typedef struct{
	int num;
	struct vertice* conexoes;
} vertice;

typedef struct{
	int totalVertices;
	int totalArestas;
	vertice* vertice;
} grafoNaoDir;

grafoNaoDir* criarGrafoNaoDir();
int adicionarVertice(grafoNaoDir* grafo, int num);

#endif // GRAFO_NAO_DIR
