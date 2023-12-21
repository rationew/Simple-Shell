#include "simpleshell.h"
/**
 * main - checks the code
 *
 * Return: void
 */
int main(void)
{
	char message[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		display_prompt();

		if (fgets(message, sizeof(message), stdin) == NULL)
		{
			/*handle CTRL+D (end of file)*/
			shell_print("\n");
			break;
		}
		/*Remove the newline character*/
		message[strcspn(message, "\n")] = '\0';

		parse_message(message, args);

		if (args[0] != NULL)
		{
			execute_command(args);
		}
	}
	shell_print("Shell exiting...\n");

	return (0);
}
