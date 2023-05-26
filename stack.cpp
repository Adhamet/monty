#include "monty.h"

/**
 * init_stack - give stack the final values
 * @stack: dll to hold the elements
 */
void init_stack(stack_t *stack)
{
    stack->n = 0;
    stack->prev = NULL;
    stack->next = NULL;
    stack->push_back = &stack_push_back;
    stack->push_front = &queue_push_front;
    stack->pop_back = &stack_pop_back;
    stack->pop_front = &queue_pop_front;
    stack->front = &queue_front;
    stack->back = &queue_back;
}

/**
 * stack_push_back - push back into stack
 * @stack: dll to push back the element
 */
void stack_push_back(stack_t *stack, int value)
{
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    new_node->n = value;
    new_node->next = NULL;

    if (stack->n == 0)
    {
        new_node->prev = NULL;
        stack->next = new_node;
    }
    else
    {
        new_node->prev = stack->next;
        stack->next->next = new_node;
        stack->next = new_node;
    }

    stack->n++;
}

/**
 * stack_pop_back - pop out element
 * @stack: dll that holds the elements
 * Return: value if successful
 * 		-1 if failed.
 */
int stack_pop_back(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int value = stack->next->n;
    stack_t *temp = stack->next;
    stack->next = stack->next->prev;

    if (stack->next != NULL)
        stack->next->next = NULL;

    free(temp);
    stack->n--;

    return value;
}

/**
 * stack_front - print out front of stack
 * @stack: dll that holds the elements
 * Return: value of stack front
 */
int stack_front(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->next->n;
}

/**
 * queue_front - print out front of stack
 * @stack: dll that holds the elements
 * Return: value of queue front
 */
int queue_front(stack_t *stack)
{
    return stack_front(stack);
}
