#include "monty.h"

/* global variable */
stack_t stack;

/**
 * main - entry point for the program
 * @argc: argument count
 * @argv: argument list
 * Return: an integer.
 */
int main(int argc, char *argv[])
{
	int fd;
	size_t line_size;
	char *line_buffer = NULL;

	if (argc < 2)
	{
		print_err("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (process_file(argv[1], &fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	init_stack(&stack);
	while(true)
	{
		if ((_getline(&line_buffer, &line_size, fd) != -1))
		{
			if (run_instruction(line_buffer) == -1)
				return (EXIT_FAILURE);
		}
		else
			break;
	}

	return (0);
}

/**
 * run_instruction - applies the instruction
 * @line_buffer: the input/opcode to apply.
 * Return: 0 on success,
 * 	   -1 on failure.
 */
int run_instruction(char *line_buffer)
{
	char *opcode = NULL, *value = NULL;

	parse_instruction(&opcode, &value, line_buffer);

	if (opcode == NULL)
		return (-1);
	if (is_numeric(value) == 0)
	{
		error_instruction(value);
		return (-1);
	}

	if (_strcmp(opcode, "push") == 0)
	{
		int data;
		data = _atoi(value);
		stack.push_back(&stack, data);
	}
	else if (_strcmp(opcode, "pall") == 0)
	{
		while (stack.front(&stack) != -1)
		{
			char *s = _itoa(stack.front(&stack));

			print_str(s);
			print_str('\n');
			stack.pop_front(&stack);
		}
	}
	else
	{
		error_Instruction(opcode);
		free(opcode);
		return (-1);
	}

	free(opcode);
	free(value);
	return (0);
}
