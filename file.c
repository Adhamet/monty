#include "monty.h"

/**
 * process_file - updates file descriptor to read input from a file
 *
 * @file: the path to the file
 * @fd: the file descriptor to update
 *
 * Return: 0 on sucess, otherwise error code
 */
int process_file(char *file, int *fd)
{
	if (access(file, R_OK) == -1)
	{
		error_file(file);
		return (EXIT_FAILURE);
	}

	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		error_file(file);
		return (EXIT_FAILURE);
	}

	return (0);
}
