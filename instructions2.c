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

	s = malloc(sizeof(char) * 3);
	if (s == NULL)
	{
		error_malloc();
		return (-1);
	}

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

	s[0] = list_head->n;
	s[1] = '\n';
	s[2] = '\0';
	print_str(s);
	free(s);

	return (0);
}

/**
 * pstr - print string
 * Return: 0 on success, -1 if fail
 */
int pstr(void)
{
	stack_t *tmp = list_head;
	char *s;

	while (tmp != NULL && tmp->n > 0 && tmp->n < 127)
	{
		s = malloc(sizeof(char) * 2);

		if (s == NULL)
		{
			error_malloc();
			return (-1);
		}

		s[0] = tmp->n;
		s[1] = '\0';
		print_str(s);
		free(s);

		tmp = tmp->next;
	}

	print_str("\n");
	return (0);
}

/**
 * op_print - check which operation print it is
 * @opcode: operation holder
 * Return: 0 if succeeded, -1 if failed
 */
int op_print(char *opcode)
{
	int rn = 0;

	if (_strcmp(opcode, "pint") == 0)
		rn = op_pint(opcode);
	else if (_strcmp(opcode, "pchar") == 0)
		rn = pchar(opcode);
	else if (_strcmp(opcode, "pstr") == 0)
		rn = pstr();

	return (rn);
}
