#include "monty.h"

/**
 * empty - checks if the list is empty
 *
 * Return: 1 if empty, 0 if not
 */
int empty(void)
{
	return (list_head == NULL && list_tail == NULL);
}

/**
 * push_back - adds a new node at the end of the list
 *
 * @data: value to add to the list
 */
void push_back(int data)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		error_malloc();
		return;
	}

	new_node->n = data;
	new_node->next = NULL;

	if (list_head == NULL)
	{
		new_node->prev = NULL;
		list_head = new_node;
		list_tail = new_node;
	}
	else
	{
		new_node->prev = list_tail;
		list_tail->next = new_node;
		list_tail = new_node;
	}
}

/**
 * push_front - adds a new node at the beginning of the list
 *
 * @data: value to add to the list
 */
void push_front(int data)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		error_malloc();
		return;
	}

	new_node->n = data;
	new_node->next = list_head;
	new_node->prev = NULL;

	if (list_head == NULL)
	{
		list_head = new_node;
		list_tail = new_node;
	}
	else
	{
		list_head->prev = new_node;
		list_head = new_node;
	}
}

/**
 * pop_back - removes the last element of the list
 */
void pop_back(void)
{
	if (list_head == NULL)
	{
		return;
	}

	if (list_head == list_tail)
	{
		free(list_head);
		list_head = NULL;
		list_tail = NULL;
	}
	else
	{
		stack_t *temp = list_tail;

		list_tail = list_tail->prev;
		list_tail->next = NULL;
		free(temp);
	}
}

/**
 * pop_front - removes the first element of the list
 */
void pop_front(void)
{
	if (list_head == NULL)
		return;

	if (list_head == list_tail)
	{
		free(list_head);
		list_head = NULL;
		list_tail = NULL;
	}
	else
	{
		stack_t *temp = list_head;

		list_head = list_head->next;
		list_head->prev = NULL;
		free(temp);
	}
}
