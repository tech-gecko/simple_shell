#include "main.h"

/**
 * _strcmp - Compares two strings and returns an int
 *          according to that comparison.
 * @a1: The first string.
 * @a2: The second string.
 *
 * Return: -1, 0 or 1.
 */
int _strcmp(const char *a1, const char *a2)
{
	while (*a1 && *a2)
	{
		if (*a1 == *a2)
			return (0);
		a1++;
		a2++;
	}

	return (*a1 - *a2);
}


/**
 * _strlen - Function that returns the number of characters in a string.
 * @a: String whose length is to be checked.
 *
 * Return: Integer length of string.
 */
int _strlen(const char *a)
{
	int length = 0;

	if (!a)
		return (0);

	while (*a++)
		length++;

	return (length);
}

/**
 * _strcat - Function to concatenate a specified number of
 *           characters from the source to the destination.
 * @dest: The destination buffer value.
 * @src: The source buffer value.
 *
 * Return: Pointer to destination buffer value.
 */
char *_strcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;

	return (ret);
}

/**
 * _strtok - Tokenizes a string using delimiters.
 * @str: String to be tokenized.
 * @delim: String holding all delimeters.
 *
 * Return: All split tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *new_token;

	if (str)
	{
		new_token = NULL;
		str = search(&new_token, str, delim);
		return (str);
	}

	else
	{
		if (new_token)
		{
			str = new_token;
			str = search(&new_token, str, delim);
			return (str);
		}
		return (NULL);
	}
	return (NULL);
}


/**
 * search - Replaces delimeters with '\0' after tokenization.
 * @newer: Pointer set to after delimeter or NULL.
 * @str: String to be parsed.
 * @delim: Array of delimeter characters.
 *
 * Return: Pointer to parsed tokens.
 */
char *search(char **newer, char *str, const char *delim)
{
	int i, j, k;
	int count;

	k = i = 0;
	do {
		count = 0;
		while (count < _strlen(delim))
		{
			if (str[k] == delim[count])
			{
				k++;
				count = 0;
			}
			else
			{
				count++;
			}
		}
	} while (str[k] == delim[count] && str[k] != '\0');
	i = k;
	if (str[k] == '\0')
	{
		*newer = NULL;
		return (NULL);
	}
	while (str[k] != '\0')
	{
		for (j = 0; j < _strlen(delim); j++)
		{
			if (str[k] == delim[j])
			{
				str[k] = '\0';
				*newer = &str[k + 1];
				return (str + i);
			}
		}
		k++;
	}
	*newer = NULL;
	return (str + i);
}
