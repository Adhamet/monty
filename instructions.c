#include "monty.h"

/**
 * op_push - pushes into stack
 * @value: value to push
 * Return: 0 on success, -1 on failure
 */
int op_push(char *value)
{
	int v;

	if (is_numeric(value) == 0)
	{
		error_push();
		return (-1);
	}

	v = _atoi(value);

	push_front(v);
	return (0);
}

/**
 * op_pall - print all
 * Return: 0 if success, -1 if failed
 */
int op_pall(void)
{
	stack_t *curr = list_head;

	while (curr != NULL)
	{
		char *str = _itoa(curr->n);

		print_str(str);
		print_str("\n");
		curr = curr->next;
		free(str);
	}

	return (0);
}
