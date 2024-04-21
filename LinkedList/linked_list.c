#include "linked_list.h"
#include <stdlib.h>

typedef struct node_t
{
   int value;
   struct node_t *next;
} Node;

struct linked_list_t
{
   Node *head;
   Node *tail;
   unsigned int size;
};

LinkedList *linked_list_create()
{
   LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
   if (!ll)
      return NULL;

   ll->head = NULL;
   ll->tail = NULL;
   ll->size = 0;

   return ll;
}

char linked_list_insert(LinkedList *ll, const int value, const unsigned int index)
{
   if (!ll || index >= ll->size)
      return 1;
   if (index == 0)
      return linked_list_push(ll, value);
   if (index == ll->size - 1)
      return linked_list_push_back(ll, value);

   Node *node = (Node *)malloc(sizeof(Node));
   if (!node)
      return 1;

   Node *ptr = ll->head;
   for (unsigned int i = 0; i < index - 1; ++i)
      ptr = ptr->next;

   node->value = value;
   node->next = ptr->next;
   ptr->next = node;

   return 0;
}

char linked_list_push(LinkedList *ll, const int value)
{
   if (!ll)
      return 1;

   Node *node = (Node *)malloc(sizeof(Node));
   if (!node)
      return 1;

   node->value = value;
   node->next = ll->head;
   ll->head = node;
   ++ll->size;

   return 0;
}

char linked_list_push_back(LinkedList *ll, const int value)
{
   if (!ll)
      return 1;

   Node *node = (Node *)malloc(sizeof(Node));
   if (!node)
      return 1;

   node->value = value;
   node->next = NULL;

   if (!ll->tail)
   {
      ll->head = node;
      ll->tail = node;
      ++ll->size;

      return 0;
   }

   ll->tail->next = node;
   ll->tail = node;
   ++ll->size;

   return 0;
}

char linked_list_remove(LinkedList *ll, const unsigned int index)
{
   if (!ll || index >= ll->size)
      return 1;
   if (index == 0)
      return linked_list_pop(ll);
   if (index == ll->size - 1)
      return linked_list_pop_back(ll);

   Node *ptr = ll->head;
   for (unsigned int i = 0; i < index - 1; ++i)
      ptr = ptr->next;
   Node *tmp = ptr->next;
   ptr->next = tmp->next;
   free(tmp);

   return 0;
}

char linked_list_pop(LinkedList *ll)
{
   if (!ll || !ll->head || ll->size == 0)
      return 1;
   if (ll->head == ll->tail)
   {
      free(ll->head);
      ll->head = NULL;
      ll->tail = NULL;
      --ll->size;

      return 0;
   }

   Node *ptr = ll->head;
   ll->head = ll->head->next;
   free(ptr);
   --ll->size;

   return 0;
}

char linked_list_pop_back(LinkedList *ll)
{
   if (!ll || !ll->tail || ll->size == 0)
      return 1;
   if (ll->head == ll->tail)
   {
      free(ll->head);
      ll->head = NULL;
      ll->tail = NULL;
      --ll->size;

      return 0;
   }

   Node *ptr = ll->head;
   while (ptr->next != ll->tail)
      ptr = ptr->next;

   free(ll->tail);
   ptr->next = NULL;
   ll->tail = ptr;
   --ll->size;

   return 0;
}

char linked_list_clear(LinkedList *ll)
{
   if (!ll)
      return 1;

   while (ll->head)
      linked_list_pop(ll);

   return 0;
}

char linked_list_size(LinkedList *ll)
{
   return !ll ? 0 : ll->size;
}

unsigned int linked_list_find(LinkedList *ll, const int value)
{
   if (!ll || !ll->head)
      return 0;

   Node *ptr = ll->head;
   unsigned int i = 0;
   while (ptr && ptr->value != value)
   {
      ptr = ptr->next;
      ++i;
   }

   if (!ptr)
      return 0;
   return i;
}

int linked_list_get(LinkedList *ll, const unsigned int index)
{
   if (!ll || !ll->head)
      return 0;

   Node *ptr = ll->head;
   for (unsigned int i = 0; i < index; ++i)
   {
      if (!ptr)
         return 0;
      ptr = ptr->next;
   }

   return ptr->value;
}

void linked_list_destroy(LinkedList *ll)
{
   if (!ll)
      return;

   linked_list_clear(ll);
   free(ll);
}