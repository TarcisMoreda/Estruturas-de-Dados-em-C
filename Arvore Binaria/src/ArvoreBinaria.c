#include "ArvoreBinaria.h"

/*
Aloca a memória para o primeiro nó da árvore
Checa se a alocação foi bem sucedida
Define o valor do primeiro elemento
Retorna o ponteiro para o nó criado
*/
noArvore* arvoreCria(int elem){
    noArvore* no = (noArvore*) malloc(sizeof(noArvore));

    if (no == NULL){
      printf("Erro ao criar árvore.\n");
      return NULL;
    }

    no->num = elem;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

/*
Checa se a árvore existe
Um ponteiro de nó(novo) é criado
Os dados a serem adicionados são salvos no ponteiro novo
Chama a função recursiva arvoreInsereAux()
*/
void arvoreInsereAux(noArvore* ar, noArvore* novo);
int arvoreInsere(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* novo = (noArvore*) malloc(sizeof(noArvore));
    novo->num = elem;
    novo->esquerda = NULL;
    novo->direita = NULL;

    arvoreInsereAux(ar, novo);

    return 1;
}

/*
Checa se o nó novo tem um valor maior que o nó atual
    Checa se o nó da esquerda existe
        Se sim chama-se a função recursivamente
        Se não salva o nó novo à esquerda do atual
Checa se o nó novo tem um valor menor que o nó atual
    Checa se o nó da direita existe
        Se sim chama-se a função recursivamente
        Se não salva o nó novo à direita do atual
*/
void arvoreInsereAux(noArvore* ar, noArvore* novo){
    if (novo->num < ar->num){
        if (ar->esquerda != NULL) arvoreInsereAux(ar->esquerda, novo);
        else ar->esquerda = novo;
    }
    else if (novo->num > ar->num){
        if (ar->direita != NULL) arvoreInsereAux(ar->direita, novo);
        else ar->direita = novo;
    }

    return;
}

/*
Eu odeio essa funcao, ela me deu tanta dor de cabeca.
Mas o problema não era ela, o problema era a funcao de inserir.
*/
int arvoreRemove(noArvore* ar, int elem){
    if (ar == NULL) return 0;

    noArvore* raiz = ar;
    noArvore* aux = ar;

    while (ar->num != elem){
        aux = ar;

        if (elem < ar->num){
            if (ar->esquerda == NULL) return 0;
            ar = ar->esquerda;
        }
        else if (elem > ar->num){
            if (ar->direita == NULL) return 0;
            ar = ar->direita;
        }
    }

    if (ar->esquerda == NULL && ar->direita == NULL){
        if (aux->esquerda == ar) aux->esquerda = NULL;
        else if (aux->direita == ar) aux->direita = NULL;
        else return 0;

        free(ar);

        return 1;
    }
    else if (ar->esquerda != NULL && ar->direita != NULL){
        aux = ar->direita;

        while (aux->esquerda != NULL)
        aux = aux->esquerda;

        int valor = aux->num;
        arvoreRemove(raiz, aux->num);
        ar->num = valor;

        return 1;
    }

    noArvore* filho = (ar->esquerda != NULL) ? ar->esquerda: ar->direita;
        
    if (ar != raiz){
        if (aux->esquerda == ar)
        aux->esquerda = filho;
        else
        aux->direita = filho;
    }
    else raiz = filho;

    free(ar);

    return 1;
}

/*
Checa se a árvore existe
Checa os lados do nó atual e chama a função recursivamente
Libera-se a memória da árvore
*/
void arvoreDestroi(noArvore* ar){
    if (ar == NULL) return;

    if (ar->esquerda != NULL) arvoreDestroi(ar->esquerda);
    else if (ar->direita != NULL) arvoreDestroi(ar->direita);
    free(ar);
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó da esquerda -> Nó do meio -> Nó da direita
*/
int emOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    printf("%d ", ar->num);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó do meio -> Nó da esquerda -> Nó da direita
*/
int preOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    printf("%d ", ar->num);
    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);

    return 1;
}

/*
Checa se a árvore existe
Printa todos os nós da árvore na sequência:
    Nó da esquerda -> Nó da direita -> Nó do meio 
*/
int posOrdem(noArvore* ar){
    if (ar == NULL) return 0;

    if (ar->esquerda != NULL) emOrdem(ar->esquerda);
    if (ar->direita != NULL) emOrdem(ar->direita);
    printf("%d ", ar->num);

    return 1 ;
}