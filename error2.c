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
