/*================================
   PILHA ESTÁTICA.H
=================================*/

/* DEFINIÇÕES
***************/
#define MAX 100

struct aluno{
   int matricula;     // codigo da matricula
   char nome[30];     // nome do aluno
   float n1, n2, n3;  // notas do aluno
};

// Apelido pro tipo pilha (simplificando)
typedef struct pilha Pilha;

/* PROTÓTIPOS
***************/
Pilha* pilhaCria();

void pilhaDestroi(Pilha* pi);

int pilhaTamanho(Pilha *pi);

int pilhaCheia(Pilha *pi);

int pilhaVazia(Pilha *pi);

int pilhaInsere(Pilha *pi, struct aluno al);

int pilhaRemove(Pilha *pi);

int pilhaConsulta(Pilha *pi, struct aluno *al);
