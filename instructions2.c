#include "monty.h"

/**
 * op_add - adds two top elements
 * @opcode: holds operation
 * Return: 0 if successful, -1 if failed
 */
int op_add(char *opcode)
{
	int result = 0, val1, val2;

	if (list_head == NULL || list_head->next == NULL)
	{
		error_short_stack(opcode);
		return (-1);
	}

	val1 = list_head->n;
	val2 = list_head->n;
	result = val1 + val2;

	pop_front();
	pop_front();
	push_front(result);

	return (0);
}
