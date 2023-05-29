#include "monty.h"

/* global variable */
int line_number = 1;
int format = 0;
stack_t *list_head = NULL;
stack_t *list_tail = NULL;


/* helper functions */
int run_instruction(char *line_buffer);

/**
 * main - entry point for the program
 * @argc: argument count
 * @argv: argument list
 * Return: an integer.
 */
int main(int argc, char *argv[])
{
	int fd, rn = 0;
	size_t line_size;
	char *line_buffer = NULL;

	if (argc != 2)
	{
		print_err("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (process_file(argv[1], &fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (true)
	{
		if (_getline(&line_buffer, &line_size, fd) != -1)
		{
			if (rn != EXIT_FAILURE && run_instruction(line_buffer) == -1)
				rn = EXIT_FAILURE;
			line_number++;
		}
		else
			break;
	}

	free(line_buffer);
	free_list();
	close(fd);
	return (rn);
}

/**
 * run_instruction - applies the instruction
 * @line_buffer: the input/opcode to apply.
 * Return: 0 on success, -1 on failure.
 */
int run_instruction(char *line_buffer)
{
	char *opcode = NULL, *value = NULL;
	int rn = 0;

	parse_instruction(&opcode, &value, line_buffer);

	if (opcode == NULL)
	{
		if (value != NULL)
			free(value);
		return (0);
	}

	if (_strcmp(opcode, "push") == 0)
		rn = op_push(value);
	else if (_strcmp(opcode, "pall") == 0)
		rn = op_pall();
	else if (_strcmp(opcode, "pint") == 0)
		rn = op_pint();
	else if (_strcmp(opcode, "pop") == 0)
		rn = op_pop();
	else if (_strcmp(opcode, "swap") == 0)
		rn = op_swap(opcode);
	else if (_strcmp(opcode, "add") == 0 || _strcmp(opcode, "sub") == 0 ||
			_strcmp(opcode, "div") == 0 || _strcmp(opcode, "mod") == 0 ||
			_strcmp(opcode, "mul") == 0)
		rn = op_maths(opcode);
	else if (_strcmp(opcode, "nop") == 0 || opcode[0] == '#')
		rn = 0;
	else if (_strcmp(opcode, "stack") == 0)
		format = 0;
	else if (_strcmp(opcode, "queue") == 0)
		format = 1;
	else
		rn = error_instruction(opcode);

	free(opcode);
	if (value != NULL)
		free(value);
	return (rn);
}
