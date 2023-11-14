#include <stdio.h>


/**
 * writing string length function that uses a for loop
 * Collaborators for tis project tech-gecko and akinremimoses
*/

size_t strlen(const char *str)
{
size_t length = 0;

    while (*str)
    {
        length++;
        str++;
    }

    return length;
}

int main()
{

    const char *String = "Hello, World!";

    size_t length =_strlen(myString);

   //("The length of the string is: %zu\n", length);

    return 0;
}


/**
 * writing string length function that uses a for loop
 * Collaborators for tis project tech-gecko and akinremimoses
 */


size_t strlen(const char *str)

{
    const char *ptr = str;

    for (size_t length = 0; *ptr != '\0'; ++length, ++ptr);

    return ptr - str;
}


int main()

{
   const char *String = "Custom String Length Function";

    size_t length = strlen(myString);

   //("The length of the string is: %zu\n", length);

    return 0;
}
