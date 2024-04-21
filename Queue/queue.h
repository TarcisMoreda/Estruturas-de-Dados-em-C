#if !defined(QUEUE_H)
#define QUEUE_H

typedef struct queue_t Queue;

Queue *queue_create();
char queue_push_back(Queue *queue, const int value);
int queue_pop(Queue *queue);
char queue_clear(Queue *queue);
void queue_destroy(Queue *queue);

#endif // QUEUE_H