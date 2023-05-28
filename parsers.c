#include "monty.h"

/**
 * parse_instruction - takes the line_buffer (stdin)
 * and divides it into comprehensible parts
 *
 * @opcode: the code of operation to be applied
 * @value: the value which the opcode applies
 * @line_buffer: the stdin
 * Return: nothing
 */
void parse_instruction(char **opcode, char **value, char *line_buffer)
{
	int i, len = 0;
	char *word, c;

	word = malloc(sizeof(char) * (_strlen(line_buffer) + 1));
	if (word == NULL)
		error_malloc();

	for (i = 0; (c = line_buffer[i]) != '\0'; i++)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (len)
			{
				word[len] = '\0';
				if (*opcode == NULL)
					*opcode = _strdup(word);
				else if (*value == NULL)
					*value = _strdup(word);
				else
				{
					len = 0;
					break;
				}
				len = 0;
			}
		}
		else
			word[len++] = c;
	}

	if (len)
	{
		word[len] = '\0';
		if (*opcode == NULL)
			*opcode = _strdup(word);
		else
			*value = _strdup(word);
		len = 0;
	}
	free(word);
}
