 #include "main.h"

/**
 * parser - Displays prompt and saves input as an array of chars.
 *
 * Return: An array of input commands.
 */
char *parser(void)
{
	ssize_t chars_read;
	char *lineptr;
	size_t n = 0;
	char prompt[] = "($) ";

	write(STDOUT_FILENO, prompt, 3);

	chars_read = _getline(&lineptr, &n, STDIN_FILENO);
	if (chars_read < 1)
	{
		return (NULL);
	}

	return (lineptr + 5);
}

/**
 * tokenizer - splits line of command and args into individul words.
 * @lineptr: pointer to the array of input commands.
 * @delim: str containing all chars that should tokenize lineptr.
 *
 * Return: An array of arrays of words gotten from tokenizer.
 */
char **tokenizer(char *lineptr, char *delim)
{
	char *token;
	int count = 0;
	char **command = malloc(20 * sizeof(char *));

	token = _strtok(lineptr, delim);
	command[0] = token;

	while (token != NULL)
	{
		token = _strtok(NULL, delim);
		command[++count] = token;
	}

	return (command);
}

/**
 * wrapper_func - Main entry point to the parser & tokenizer.
 *
 * Return: Same as return from the "tokenizer" function.
 */
char **wrapper_func(void)
{
	char delim[] = " \n";
	char *lineptr = parser();

	if (lineptr == NULL)
	{
		write(1, "\n", 1);
		return (NULL);
	}

	while (*lineptr == '\n')
	{
		free(lineptr - 5);
		lineptr = parser();

		if (lineptr == NULL)
		{
			write(1, "\n", 1);
			return (NULL);
		}
	}

	return (tokenizer(lineptr, delim));
}

/**
 * _getline - Customized getline to handle wrongly specified path.
 * @lineptr: Pointer to array of input commands.
 * @n: Number of characters read.
 * @fd: File descriptor.
 *
 * Return: Number of characters seen before \n or EOF.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t count = 0;
	char *buffer = malloc(1024 * sizeof(char));

	if (buffer == NULL)
		return (0);

	*n = _read(buffer, fd, n);
	if (*n == 0)
	{
		free(buffer);
		return (0);
	}

	*lineptr = malloc(sizeof(char) * ((*n) + 5));
	if (*lineptr == NULL)
	{
		free(buffer);
		return (0);
	}
	lineptr[0][0] = '/';
	lineptr[0][1] = 'b';
	lineptr[0][2] = 'i';
	lineptr[0][3] = 'n';
	lineptr[0][4] = '/';
	for (count = 0; buffer[count] != '\n'; count++)
	{
		lineptr[0][count + 5] = buffer[count];
	}
	lineptr[0][count + 5] = buffer[count];
	free(buffer);

	return (count + 1);
}

/**
 * _read - A recursive version of the getline syscall.
 * @buffer: Buffer to store the line of command in.
 * @fd: File descriptor.
 * @n: Number of characters read.
 *
 * Description: This is a recursive function!
 *              It handles conditions like EOF, CTRL_C, CTRL_D.
 *
 * Return: Number of characters read.
 */
ssize_t _read(char *buffer, int fd, size_t *n)
{
	size_t temp1 = 0;
	size_t temp2 = 0;

	temp1 = read(fd, buffer, 1024);
	*n += temp1;
	if (temp1 == 0 && *n > 0)
	{
		buffer[*n] = '\n';
		return (*n + 1);
	}

	if (temp1 == 0)
		return (*n);

	if (buffer[(*n) - 1] != '\n')
	{
		temp2 = read(fd, &(buffer[*n]), 1024);

		if (temp2 == 0)
		{
			buffer[*n] = '\n';
			return (*n + 1);
		}

		if (buffer[*n + temp2 - 1] == '\n')
			return (*n + temp2);
		*n += temp2;

		return (_read(&(buffer[*n]), fd, n));
	}
	return (*n);
}
