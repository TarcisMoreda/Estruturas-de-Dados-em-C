/*================================
   INT MAIN.C
=================================*/
#include<stdio.h>
#include<string.h>
#include"FilaEstatica.h"

int main(){

   // ---------------------------------
   // Dados para alimentar a estrutura
   // ---------------------------------
   struct aluno naruto, sasuke, sakura, aux;
   naruto.matricula = 10;
   strcpy(naruto.nome, "Naruto Uzumaki");
   naruto.n1 = 20; naruto.n2 = 14; naruto.n3 = 18;

   sakura.matricula = 12;
   strcpy(sakura.nome, "Sakura Haruno");
   sakura.n1 = 25; sakura.n2 = 25; sakura.n3 = 23;

   sasuke.matricula = 15;
   strcpy(sasuke.nome, "Sasuke Uchila");
   sasuke.n1 = 15; sasuke.n2 = 20; sasuke.n3 = 20;


   // ---------------------------------
   // Manipulando a estrutura:
   // ---------------------------------
   Fila *fi;

   fi = filaCria();

   printf("Tamanho da fila: %d\n", filaTamanho(fi));

   if(filaCheia(fi))
      printf("Fila está cheia!\n");
   else
      printf("Fila não cheia!\n");

   if(filaVazia(fi))
      printf("Fila está vazia!\n");
   else
      printf("Fila não vazia!\n");

   // Inserindo elementos
   filaInsere(fi, naruto);
   filaInsere(fi, sasuke);
   filaInsere(fi, sakura);

   // Removendo elementos
   filaRemove(fi);
   filaRemove(fi);
   filaConsulta(fi, &aux);

   printf("Matricula:\t%d\n", aux.matricula);
   printf("Nome:\t\t%s\n", aux.nome);
   printf("Nota1:%.2f\tNota2:%.2f\tNota3:%.2f\n\n", aux.n1, aux.n2, aux.n3);

   filaDestroi(fi);

}//fim[main]


