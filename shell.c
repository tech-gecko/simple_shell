#include "main.h"
/**
 * main - Program that emulates a simple shell.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	char *envp[] = {NULL};
	char **argv;

	/* Creates an infinite loop so the shell never ends*/
	while (1)
	{
		/* Shows prompt and parses command.*/
		argv = wrapper_func();
		if (argv == NULL)
		{
			return (0);
		}

		/* Implements exit command.*/
		if (_strcmp(argv[0], "exit") == 0)
			break;

		/* Executes the command.*/
		if (argv[0][0] != '~' && argv[0][0] != '/' && argv[0][0] != '.')
			exec_cmd(argv[0] - 5, argv, envp);
		else
			exec_cmd(argv[0], argv, envp);

		/* Frees up memory allocated dynamically.*/
		free(argv[0] - 5);
		free(argv);
	}


	return (0);
}
