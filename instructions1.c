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

	if (format == 0)
		push_front(v);
	else if (format == 1)
		push_back(v);
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
 * @opcode: holder for operation
 * Return: 0 if success, -1 if failed
 */
int op_pint(char *opcode)
{
	char *s;

	if (list_head == NULL)
	{
		error_empty(opcode);
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

/**
 * op_swap - swap top two elements
 * @opcode: holds the operation code
 * Return: 0 on success, -1 if failed
 */
int op_swap(char *opcode)
{
	int val1, val2;

	if (list_head == NULL || list_head->next == NULL)
	{
		error_short_stack(opcode);
		return (-1);
	}

	val1 = front();
	pop_front();
	val2 = front();
	pop_front();

	push_front(val1);
	push_front(val2);

	return (0);
}
