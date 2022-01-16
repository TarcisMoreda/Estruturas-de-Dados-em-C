#if !defined(PILHA_H)
#define PILHA_H

//Struct que define os dados da pilha. 
typedef struct dados{
   char* nome;
   int idade;
} dados;

//Struct que define um elemento.
typedef struct elemento{
   dados dado;
   struct elemento* prox;
} elemento;

//Struct que define a pilha.
typedef struct pilha{
	elemento* inicio;
   unsigned int tamanho;
} pilha;

//Prototipação das funções da pilha.
pilha* pilhaCria();
int pilhaInsere(pilha *fi, dados dado);
int pilhaRemove(pilha *fi);
int pilhaLimpa(pilha* fi);
void pilhaDestroi(pilha* fi);

#endif // PILHA_H