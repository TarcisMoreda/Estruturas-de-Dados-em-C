#if !defined(STACK_H)
#define STACK_H

typedef struct stack_t Stack;

Stack *stack_create();
unsigned int stack_size(Stack *stack);
char stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
char stack_clear(Stack *stack);
void stack_destroy(Stack *stack);

#endif // STACK_H