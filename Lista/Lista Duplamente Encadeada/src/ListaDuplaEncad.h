#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(LISTA_DUPLA_ENCAD_H)
#define LISTA_DUPLA_ENCAD_H

//Struct que define os dados da fila. 
typedef struct dados{
   char* nome;
   int idade;
} dados;

//Struct que define um elemento.
typedef struct elemento{
   dados dado;
   struct elemento* ant;
   struct elemento* prox;
} elemento;

//Definindo o tipo lista como um ponteiro de elementos 
typedef elemento* listaDuplaEncad;

//Prototipação das funções da lista.
listaDuplaEncad* listaDuplaEncadCria();
int listaDuplaEncadInsere(listaDuplaEncad* li, dados dado);
int listaDuplaEncadInsereInicio(listaDuplaEncad* li, dados dado);
int listaDuplaEncadRemovePos(listaDuplaEncad *li, int pos);
int listaDuplaEncadRemoveInicio(listaDuplaEncad* li);
int listaDuplaEncadRemoveFinal(listaDuplaEncad* li);
int listaDuplaEncadLimpa(listaDuplaEncad* li);
int listaDuplaEncadTamanho(listaDuplaEncad *li);
int listaDuplaEncadAcharPos(listaDuplaEncad *li, char* nome);
dados listaDuplaEncadConsultaPos(listaDuplaEncad *li, int pos);
void listaDuplaEncadDestroi(listaDuplaEncad *li);

#endif // LISTA_DUPLA_ENCAD_H