/*================================
   Fila DINÂMICA.H
=================================*/

/* DEFINIÇÕES
***************/

struct aluno{
   int matricula;     // codigo da matricula
   char nome[30];     // nome do aluno
   float n1, n2, n3;  // notas do aluno
};

// Apelido pro tipo fila (simplificando)
typedef struct fila Fila;

/* PROTÓTIPOS
***************/
Fila* filaCria();

void filaDestroi(Fila* fi);

int filaTamanho(Fila *fi);

int filaCheia(Fila *fi);

int filaVazia(Fila *fi);

int filaInsere(Fila *fi, struct aluno al);

int filaRemove(Fila *fi);

int filaConsulta(Fila *fi, struct aluno *al);
