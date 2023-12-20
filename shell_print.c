#include "simpleshell.h"
/**
 * shell_print - will act as the printf function
 * @str: pointer to the character to be printed to the std output
 *
 * Return: NULL
 */
void shell_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
