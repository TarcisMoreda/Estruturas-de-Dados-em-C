#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

typedef struct linked_list_t LinkedList;

LinkedList *linked_list_create();

char linked_list_insert(LinkedList *ll, const int value, const unsigned int index);
char linked_list_push(LinkedList *ll, const int value);
char linked_list_push_back(LinkedList *ll, const int value);

char linked_list_remove(LinkedList *ll, const unsigned int index);
char linked_list_pop(LinkedList *ll);
char linked_list_pop_back(LinkedList *ll);
char linked_list_clear(LinkedList *ll);

char linked_list_size(LinkedList *ll);
unsigned int linked_list_find(LinkedList *ll, const int value);
int linked_list_get(LinkedList *ll, const unsigned int index);

void linked_list_destroy(LinkedList *ll);

#endif // LINKED_LIST_H