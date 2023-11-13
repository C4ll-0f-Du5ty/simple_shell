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

int _strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    while ((*s1 && *s2) && i < n)
    {
        i++;
        if (*s1 != *s2)
        {
            return (1);
        }
        s1++;
        s2++;
    }
    return (0);
}

char *_strchr(const char *str, int character)
{
    while (*str != '\0')
    {
        if (*str == character)
        {
            return (char *)str; // Return the pointer to the first occurrence of the character
        }
        str++;
    }
    return NULL; // Return NULL if character is not found
}

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

void shiftString(char *str, int startIndex)
{
    int i = 0;
    while (str[i + startIndex] != '\0')
    {
        str[i] = str[i + startIndex];
        i++;
    }
    str[i] = '\0';
}

void trimLeadingSpaces(char *str)
{
    int len = _strlen(str);
    int startIndex = 0;

    // Find the index of the first non-space character
    while (startIndex < len && str[startIndex] == ' ')
    {
        startIndex++;
    }

    // Shift the string to remove leading spaces
    if (startIndex > 0)
    {
        // memmove(str, str + startIndex, len - startIndex + 1);
        shiftString(str, startIndex);
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

void _strncat(char *dest, char *src, size_t n)
{
    size_t dest_len = _strlen(dest);
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';
}
