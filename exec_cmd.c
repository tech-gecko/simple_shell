#include "main.h"

/**
 * exec_cmd - Creates new process for and executes new command.
 * @pathname: Path to executable file of command.
 * @argv: Argument vector containing command and arguments.
 * @envp: Environment variable array.
 *
 * Return: Nothing.
 */
void exec_cmd(const char *pathname, char *const argv[], char *const envp[])
{
	pid_t pid;
	int status, exec_return;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(98);
	}
	else if (pid == 0)
	{
		exec_return = execve(pathname, argv, envp);
		if (exec_return == -1)
		{
			perror("hsh");
			exit(98);
		}
	}
	else
		wait(&status);
}
