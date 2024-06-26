#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *collection;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity)
{
    if (capacity <= 0)
        return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if (stack->collection == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

void destroy_stack(Stack *stack)
{
    if (stack == NULL)
        return;

    free(stack->collection);
    free(stack);
}

bool is_full(Stack *stack)
{
    return stack->size == stack->capacity;
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool push(Stack *stack, int item)
{
    if (stack == NULL || is_full(stack))
        return false;

    stack->collection[stack->size++] = item;
    return true;
}

bool peek(Stack *stack, int *item)
{
    if (stack == NULL || is_empty(stack))
        return false;

    *item = stack->collection[stack->size - 1];
    return true;
}

bool pop(Stack *stack, int *item)
{
    if (stack == NULL || is_empty(stack))
        return false;

    *item = stack->collection[--stack->size];
    return true;
}

int main()
{
    Stack *stack = create_stack(5);

    if (stack == NULL)
    {
        printf("Failed to create stack. Exiting...\n");
        return 1;
    }

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    int item;
    if (pop(stack, &item))
        printf("Popped item: %d\n", item);

    if (peek(stack, &item))
        printf("Top item: %d\n", item);

    destroy_stack(stack);
    return 0;
}
