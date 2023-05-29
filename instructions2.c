#include "monty.h"

/**
 * op_maths - adds two top elements
 * @opcode: holds operation
 * Return: 0 if successful, -1 if failed
 */
int op_maths(char *opcode)
{
	int result = 0, val1, val2;

	if (list_head == NULL || list_head->next == NULL)
	{
		error_short_stack(opcode);
		return (-1);
	}

	val1 = list_head->n;
	val2 = list_head->next->n;
	if (_strcmp(opcode, "add") == 0)
		result = val1 + val2;
	else if (_strcmp(opcode, "sub") == 0)
		result = val2 - val1;
	else if (_strcmp(opcode, "mul") == 0)
		result = val1 * val2;
	else if (_strcmp(opcode, "div") == 0 || _strcmp(opcode, "mod") == 0)
	{
		if (val1 == 0)
		{
			error_div_zero();
			return (-1);
		}
		if (_strcmp(opcode, "div") == 0)
			result = val2 / val1;
		else
			result = val2 % val1;
	}

	pop_front();
	pop_front();
	push_front(result);

	return (0);
}

/**
 * pchar - prints char top of stack
 * @opcode: holds operation code
 * Return: 0 if success, -1 if fail
 */
int pchar(char *opcode)
{
	char *s;

	if (list_head == NULL)
	{
		error_empty(opcode);
		return (-1);
	}

	if (list_head->n < 0 || list_head->n > 127)
	{
		error_ascii();
		return (-1);
	}

	s = _itoa(front());
	print_str(s);
	free(s);

	return (0);
}
