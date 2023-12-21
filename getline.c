#include "simpleshell.h"
/**
 * getline - reads a line from a stream and allocate memory dynamically
 * @ptr: pointer to the buffer where the line will be stored.
 * @k: pointer to the size of the buffer pointer to by 'ptr'
 *
 * Return: k and the mememory space read.
 */
ssize_t getline(char **ptr, size_t *k)
{
	static char buffer[100];

	static size_t buffer_value;

	ssize_t bytecount = 0;

	while (1)
	{
		if (buffer_value == 0)
		{
			bytecount = read(STDIN_FILENO, buffer, sizeof(buffer));

			if (bytecount <= 0)
			{
				return (bytecount);
				/*Error*/
			}
		}
		char current = buffer[buffer_value++];

		if (current == '\n' || current == '\0')
		{
			*ptr == strdup(buffer);
			if (*ptr == NULL)
			{
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			*k = strlen(*ptr);
			buffer_index = 0;

			return (*k);
		}
	}
}
