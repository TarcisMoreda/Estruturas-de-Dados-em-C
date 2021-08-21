/*================================
   LISTA SEQUENCIAL.H
=================================*/

/* DEFINIÇÕES
***************/

#define MAX 50

struct aluno{
   int matricula;    // codigo da matricula
   char nome[50];    // nome do aluno
   float n1, n2, n3; // notas do aluno
};

//Apelido pro tipo lista (simplificando)
typedef struct lista Lista;


/* PROTÓTIPOS
***************/
Lista* listaCria();

void listaDestroi(Lista *li);

int listaTamanho(Lista *li);

int listaCheia(Lista* li);

int listaVazia(Lista* li);

int listaInsereFinal(Lista* li, struct aluno al);

int listaInsereInicio(Lista* li, struct aluno al);

int listaInsereOrdenado(Lista* li, struct aluno al);

int listaRemoveFinal(Lista* li);

int listaRemoveInicio(Lista* li);

int listaRemove(Lista* li, int mat);

int listaConsultaPos(Lista*li, int pos, struct aluno *al);

int listaConsultaMat(Lista*li, int mat, struct aluno *al);

int listaImprime(Lista* li);
