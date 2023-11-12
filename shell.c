#include "main.h"
/**
 * main - Program that emulates a simple shell.
 * argc: Argument count.
 * argv: Argument vector.
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{
	char *envp[] = {NULL};
	(void)argc;

	/* Creates an infinite loop so the shell never ends*/
	while (1)
	{
		/* Shows prompt and parses command.*/
		argv = wrapper_func();
		if (argv == NULL)
		{
			return (0);
		}

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
