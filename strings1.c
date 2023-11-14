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

/**
 * _strncmp - A function that compares two string.
 *
 * @s1: string one
 * @s2: string two
 * @n: number of bytes to compare
 *
 * Return: no return
 */

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

/**
 * _strchr - it finds the first existance of a character in a string
 *
 * @str: pointer to source input
 * @character: the one to search for
 *
 * Return: a pointer to that character
 */

char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
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
