#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if true, 0 if false
 */

int _strcmp(char *s1, char *s2)
{
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    if (*s1 == *s2)
    {
        return (0);
    }
    else
    {
        return (*s1 - *s2);
    }
}
// int _strcmp(char *s1, char *s2)
// {
//     while (*s1 && *s2 && *s1 == *s2)
//     {
//         s1++;
//         s2++;
//     }

//     if (*s1 == '\0' && *s2 == '\0')
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

/**
 * _strncpy - A function that copies a string.
 *
 * @dest: pointer to destination input buffer
 * @src: pointer to source input buffer
 * @n: bytes of @src
 *
 * Return: @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return (dest);
}

void trimLeadingSpaces(char *str)
{
    int len = strlen(str);
    int startIndex = 0;

    // Find the index of the first non-space character
    while (startIndex < len && str[startIndex] == ' ')
    {
        startIndex++;
    }

    // Shift the string to remove leading spaces
    if (startIndex > 0)
    {
        memmove(str, str + startIndex, len - startIndex + 1);
    }
}

/**
 * _strlen - returns the length of a string
 *
 * @s: string parameter input
 *
 * Return: length of string
 */

int _strlen(char *s)
{
    int counter = 0;

    while (*s != '\0')
    {
        counter++;
        s++;
    }

    if (counter != 0)
    {
        return (counter);
    }
    else
    {
        return (0);
    }
}

int _str1_len(char *s, char deli)
{
    int counter = 0;

    while (*s != '\0' && *s != deli)
    {
        counter++;
        s++;
    }

    if (counter != 0)
    {
        return (counter);
    }
    else
    {
        return (0);
    }
}
