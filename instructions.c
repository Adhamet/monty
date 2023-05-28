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

/**
 * op_pint - print integer at top of stack
 * Return: 0 if success, -1 if failed
 */
int op_pint(void)
{
	char *s;

	if (list_head == NULL)
	{
		error_pint();
		return (-1);
	}

	s = _itoa(front());
	print_str(s);
	print_str("\n");

	free(s);
	return (0);
}

/**
 * op_pop - pop top of stack
 * Return: -1 if failed, 0 if success
 */
int op_pop(void)
{
	if (list_head == NULL)
	{
		error_pop();
		return (-1);
	}

	pop_front();
	return (0);
}
