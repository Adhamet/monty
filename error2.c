#include "monty.h"

/**
 * error_pop - error for pop
 */
void error_pop(void)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": can't pop an empty stack\n");

	free(s);
}

/**
 * error_short_stack - error for not having
 * enough elements
 * @opcode: the operation
 */
void error_short_stack(char *opcode)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": can't ");
	print_err(opcode);
	print_err(", stack too short\n");

	free(s);
}
