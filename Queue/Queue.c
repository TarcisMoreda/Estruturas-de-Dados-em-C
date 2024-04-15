#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
   int value;
   struct node_t *next;
} Node;

struct queue_t
{
   Node *head;
   Node *tail;
   unsigned int size;
};

Queue *queue_create()
{
   Queue *queue = (Queue *)malloc(sizeof(Queue));

   if (!queue)
      return NULL;

   queue->head = NULL;
   queue->tail = NULL;
   queue->size = 0;

   return queue;
}

unsigned int queue_size(Queue *queue)
{
   return !queue ? 0 : queue->size;
}

char queue_push_back(Queue *queue, int value)
{
   if (!queue)
      return 1;

   Node *node = (Node *)malloc(sizeof(Node));
   node->value = value;

   if (!queue->head)
      queue->head = node;
   else
      queue->tail->next = node;

   queue->tail = node;
   ++(queue->size);

   return 0;
}

int queue_pop(Queue *queue)
{
   if (!queue || !queue->head)
      return 0;

   Node *aux = queue->head;
   int value = queue->head->value;
   queue->head = queue->head->next;

   if (!queue->head)
      queue->tail = NULL;

   free(aux);
   --(queue->size);

   return value;
}

char queue_clear(Queue *queue)
{
   if (!queue || !queue->head)
      return 1;

   while (!queue->head)
   {
      queue_pop(queue);
      --(queue->size);
   }

   return 0;
}

void queue_destroy(Queue *queue)
{
   if (!queue)
      return;

   queue_clear(queue);
   free(queue);

   return;
}