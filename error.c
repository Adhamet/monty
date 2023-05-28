#include "monty.h"

/**
 * error_file - print error message for file failures.
 *
 * @file: file name.
 */
void error_file(char *file)
{
	print_err("Error: Can't open file ");
	print_err(file);
	print_err("\n");
}

/**
 * error_instruction - print error message for unknown instruction opcode
 *
 * @opcode: the unknown opcode
 * Return: -1
 */
int error_instruction(char *opcode)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": unknown instruction ");
	print_err(opcode);
	print_err("\n");

	free(s);
	return (-1);
}

/**
 * error_malloc - print error message when malloc can't allocate memory anymore
 */
void error_malloc(void)
{
	print_err("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_push - prints error msg of push function
 */
void error_push(void)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": usage: push integer\n");

	free(s);

	exit(EXIT_FAILURE);
}

/**
 * error_pint - error for print integer
 */
void error_pint(void)
{
	char *s = _itoa(line_number);

	print_err("L");
	print_err(s);
	print_err(": can't pint, stack empty\n");

	free(s);
}
