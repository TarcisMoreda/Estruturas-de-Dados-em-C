/*================================
   INT MAIN.C
=================================*/
#include<stdio.h>
#include<string.h>
#include"PilhaEstatica.h"

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
   Pilha *pi;

   pi = pilhaCria();

   printf("Tamanho da pilha: %d\n", pilhaTamanho(pi));

   if(pilhaCheia(pi))
      printf("Pilha está cheia!\n");
   else
      printf("Pilha não cheia!\n");

   if(pilhaVazia(pi))
      printf("Pilha está vazia!\n");
   else
      printf("Pilha não vazia!\n");

   // Inserindo elementos
   pilhaInsere(pi, naruto);
   pilhaInsere(pi, sasuke);
   pilhaInsere(pi, sakura);

   // Removendo elementos
   pilhaRemove(pi);
   pilhaRemove(pi);
   pilhaConsulta(pi, &aux);

   printf("Matricula:\t%d\n", aux.matricula);
   printf("Nome:\t\t%s\n", aux.nome);
   printf("Nota1:%.2f\tNota2:%.2f\tNota3:%.2f\n\n", aux.n1, aux.n2, aux.n3);

   pilhaDestroi(pi);

}//fim[main]


