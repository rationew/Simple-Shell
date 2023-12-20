#include "simpleshell.h"

/**
 * display_prompt - displays a prompt and wait for the user to type a command.
 *
 * Return: void
 */
void display_prompt(void)
{
	shell_print("$ ");
	fflush(stdout);
}
/**
 * execute_command - executes command each time the prompt is displayed
 *
 * @message: pointer to character to be executed by the command
 *
 * Return: The message
 */
void execute_command(const char *message)
{
	pid_t processid = fork();

	if (processid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (processid == 0)
	{
		/*child process*/
		execlp(message, message, (char *)NULL);
		/*if execlp fails*/
		perror("execlp");
	}
	else
	{
		/*parent process*/
		int command;

		waitpid(processid, &command, 0);

		if (WIFEXITED(command))
		{
			shell_print("Child exited with status %d\n",
					WEXITSTATUS(command));
		}
		else
		{
			shell_print("Child process did not exit normally\n");
		}
	}
}
