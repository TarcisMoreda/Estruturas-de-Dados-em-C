#include<stdio.h>
#include<string.h>
#include"ListaDinEncadDupla.h"

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
   Lista *li = listaCria();

   // Inserindo elementos
   listaInsereInicio(li, naruto);
   listaInsereFinal(li, sasuke);
   listaInsereOrdenado(li, sakura);
   printf("O tamanho da Lista eh:%d\n", listaTamanho(li));

   // Consultando elementos
   listaImprime(li);

   listaConsultaPos(li, 2, &aux);
   printf("Matricula:\t%d\n", aux.matricula);
   printf("Nome:\t\t%s\n\n", aux.nome);

   listaConsultaMat(li, 15, &aux);
   printf("Matricula:\t%d\n", aux.matricula);
   printf("Nome:\t\t%s\n\n", aux.nome);

   // Removendo elementos
   listaRemoveFinal(li);
   listaRemoveInicio(li);
   listaRemove(li, 12);
   printf("O tamanho da Lista eh:%d\n", listaTamanho(li));

   // Checando informacoes
   if(listaCheia(li))
      printf("A lista esta cheia!\n");

   if(listaVazia(li))
      printf("A lista esta vazia!\n");

   // Liberando a estrutura
   listaDestroi(li);

}//fim[main]

