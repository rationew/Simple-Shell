#include "simpleshell.h"
/**
 * main - checks the code
 *
 * Return: void
 */
int main(void)
{
	char message[MAX_MESSAGE_LENGTH];

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

		execute_command(message);
	}
	shell_print("Shell exiting...\n");

	return (0);
}
