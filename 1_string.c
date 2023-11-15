#include "main.h"

/**
 * _strcmp: Compares a specified number of characters in two strings.
 * @a1: the first string
 * @a2: the second string
 * Return: positive if a1 > a2, negative if a1 < a2, zero if a1 == a2
 */
int _strcmp(const char *a1, const char *a2)
{
    while (*a1 && *a2)
    {
        if (*a1 != *a2)
            return (*a1 - *a2);
        a1++;
        a2++;
    }

    return (*a1 - *a2);
}


/**
 * _strlen - function returns the number of characters in the string pointed
 * @a: string length value to check
 * Return: integer length of string
 */
int _strlen(const char *a)
{
    int length = 0;

    if (!a)
        return 0;

    while (*a++)
        length++;

    return length;
}

/**
 * _strcat - functions to Concatenates a specified number of characters from the source to the destination.
 * @dest: the destination buffer value
 * @src: the source buffer value
 *
 * Return: pointer to destination buffer value
 */
char *_strcat(char *dest, const char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;

    while (*src)
        *dest++ = *src++;

    *dest = *src;

    return ret;
}

