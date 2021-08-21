/*================================
   LISTA DINAMICA ENCADEADA.H
=================================*/

/* DEFINIÇÕES
***************/

struct aluno{
   int matricula;     // codigo da matricula
   char nome[30];     // nome do aluno
   float n1, n2, n3;  // notas do aluno
};


// Apelido pro tipo lista (simplificando)
// Não só um apelido, mas um apelido pra ponteiro
typedef struct elemento* Lista;



/* PROTÓTIPOS
***************/
Lista* listaCria();

void listaDestroi(Lista *li);

int listaTamanho(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int listaInsereInicio(Lista* li, struct aluno al);

int listaInsereFinal(Lista* li, struct aluno al);

int listaInsereOrdenada(Lista* li, struct aluno al);

int listaRemoveInicio(Lista* li);

int listaRemoveFinal(Lista* li);

int listaRemove(Lista *li, int mat);

int listaConsultaPos(Lista *li, int pos, struct aluno *al);

int listaConsultaMat(Lista *li, int mat, struct aluno *al);

int listaImprime(Lista *li);
