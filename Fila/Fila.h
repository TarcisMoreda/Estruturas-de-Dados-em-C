#if !defined(FILA_H)
#define FILA_H

//Struct que define os dados da fila. 
typedef struct{
   char* nome;
   int idade;
} dados;

//Struct que define um elemento.
typedef struct{
   dados dado;
   struct elemento* prox;
} elemento;

//Struct que define a fila.
typedef struct fila{
	elemento* inicio;
	elemento* fim;
   unsigned int tamanho;
} fila;

//Prototipação das funções da fila.
fila* filaCria();
int filaInsere(fila *fi, dados dado);
int filaRemove(fila *fi);
int filaLimpa(fila* fi);
void filaDestroi(fila* fi);

#endif // FILA_H