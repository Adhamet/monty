#include "monty.h"

/**
 * queue_push_back - push back an element in queue
 * @stack: dll to push the element into
 * @value: the value of the element
 */
void queue_push_back(stack_t *stack, int value)
{
    stack_push_back(stack, value);
}

/**
 * queue_push_front - push front an element in queue
 * @stack: dll to push the element into
 * @value: value of the element
 */
void queue_push_front(stack_t *stack, int value)
{
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    new_node->n = value;
    new_node->prev = NULL;

    if (stack->n == 0)
    {
        new_node->next = NULL;
        stack->next = new_node;
    }
    else
    {
        new_node->next = stack->next;
        stack->next->prev = new_node;
        stack->next = new_node;
    }

    stack->n++;
}

/**
 * queue_pop_back - remove out back of queue
 * @stack: dll to get the element
 * Return: value of queue back
 */
int queue_pop_back(stack_t *stack)
{
    return stack_pop_back(stack);
}

/**
 * queue_pop_front - remove out front of queue
 * @stack: dll to get the element
 * Return: value of queue front
 */
int queue_pop_front(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int value = stack->next->n;
    stack_t *temp = stack->next;

    if (stack->next->prev != NULL)
        stack->next->prev->next = NULL;

    stack->next = stack->next->prev;

    free(temp);
    stack->n--;

    return value;
}

/**
 * queue_back - print out back of queue
 * @stack: dll to get the element
 * Return: value of queue back
 */
int queue_back(stack_t *stack)
{
    if (stack->n == 0)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    stack_t *temp = stack->next;

    while (temp->prev != NULL)
        temp = temp->prev;

    return temp->n;
}

