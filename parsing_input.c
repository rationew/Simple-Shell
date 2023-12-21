#include "simpleshell.h"

#define MAX_ARGS 10
#define MAX_INPUT_LENGTH 100
/**
 * parsing_input - parse the input string into an array of arguments.
 * @string: input string to be parsed
 * @args: array to store the parsed arguments.
 *
 * Return: parsed input
 */
void parsing_input(char *string, char **args)
{
	char *index;
	int j = 0;

	index = strtok(string, "\t\n");
	while (index != NULL && j < MAX_ARGS)
	{
		args[j++] = index;
		index = strtok(NULL, "\t\n");
	}
	args[j] = NULL;
}
