#include <stdio.h>

/**
 * This function is to write a customized string for comparison
 *
 * the collaboratots are akinremimoses and tech-gecko
 * Return Always 0
 */

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    // The difference between the differing characters
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main()
{
    const char *string1 = "hello";
    const char *string2 = "world";

    int result = strcmp(string1, string2);

    if (result == 0)
    {
        // Strings are equal

    }

    else if (result < 0)
    {
        // String 1 is lexicographically less than String 2

    }

    else
    {
        // String 1 is lexicographically greater than String 2

    }

    return 0;
}

