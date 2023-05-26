#include "python.h"

/**
 * parse_instruction - takes the line_buffer (stdin)
 * 		and divides it into comprehensible parts
 * @opcode: the code of operation to be applied
 * @value: the value which the opcode applies
 * @line_buffer: the stdin
 * Return: nothing
 */
void parse_instruction(char *opcode, char *value, char *line_buffer)
{
	int i, words = 0;
	size_t len;

	opcode = "";
	value = "";

	len = _strlen(line_buffer);

	for (i = 0; i < len; i++)
	{
		if (line_buffer[i] != ' ')
		{
			if (words == 0)
			{
				_strcat(opcode, line_buffer[i]);
				if (i + 1 < len && line_buffer[i+1] == ' ')
					words++;
			}
			else
			{
				_strcat(value, line_buffer[i]);
			}
		}
	}
}
