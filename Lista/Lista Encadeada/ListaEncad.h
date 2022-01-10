#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(LISTA_ENCAD_H)
#define LISTA_ENCAD_H

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

//Definindo o tipo lista como um ponteiro de elementos 
typedef elemento* listaEncad;

//Prototipação das funções da lista.
listaEncad* listaEncadCria();
int listaEncadInsere(listaEncad* li, dados dado);
int listaEncadInsereInicio(listaEncad* li, dados dado);
int listaEncadRemovePos(listaEncad *li, int pos);
int listaEncadRemoveInicio(listaEncad* li);
int listaEncadRemoveFinal(listaEncad* li);
int listaEncadLimpa(listaEncad* li);
int listaEncadTamanho(listaEncad *li);
int listaEncadAcharPos(listaEncad *li, char* nome);
dados listaEncadConsultaPos(listaEncad *li, int pos);
void listaEncadDestroi(listaEncad *li);

#endif // LISTA_ENCAD_H