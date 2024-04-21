#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
   int value;
   struct node_t *next;
} Node;

struct stack_t
{
   Node *head;
   unsigned int size;
};

Stack *stack_create()
{
   Stack *stack = (Stack *)malloc(sizeof(Stack));

   if (!stack)
      return NULL;

   stack->head = NULL;
   stack->size = 0;

   return stack;
}

unsigned int stack_size(Stack *stack)
{
   return !stack ? 0 : stack->size;
}

char stack_push(Stack *stack, int value)
{
   if (!stack)
      return 1;

   Node *node = (Node *)malloc(sizeof(Node));
   node->value = value;

   node->next = stack->head;
   stack->head = node;
   ++(stack->size);

   return 0;
}

int stack_pop(Stack *stack)
{
   if (!stack || !stack->head)
      return 0;

   Node *aux = stack->head;
   const int value = aux->value;
   stack->head = stack->head->next;

   free(aux);
   --(stack->size);

   return value;
}

char stack_clear(Stack *stack)
{
   if (!stack || !stack->head)
      return 1;

   while (stack->head)
      stack_pop(stack);

   return 0;
}

void stack_destroy(Stack *stack)
{
   if (!stack)
      return;

   stack_clear(stack);
   free(stack);

   return;
}