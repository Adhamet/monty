#include "monty.h"

/**
 * front - returns the value of the first element in the list
 *
 * Return: value of the first element
 */
int front(void)
{
	if (list_head != NULL)
		return (list_head->n);
	else
		return (-1);
}

/**
 * back - returns the value of the last element in the list
 *
 * Return: value of the last element
 */
int back(void)
{
	if (list_tail != NULL)
		return (list_tail->n);
	else
		return (-1);
}

/**
 * free_list - frees a list_t list
 */
void free_list(void)
{
	stack_t *temp;

	while (list_head != NULL)
	{
		temp = list_head;
		list_head = (list_head)->next;
		free(temp);
	}
}
