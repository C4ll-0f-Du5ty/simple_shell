#include "shell.h"

/**
 * shiftString - removes the white spaces
 *
 * @str: string parameter input
 * @startIndex: total number of spaces
 *
 * Return: no return
 */

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

/**
 * trimLeadingSpaces - removes the white spaces
 *
 * @str: string parameter input
 *
 * Return: no return
 */

void trimLeadingSpaces(char *str)
{
	int len = _strlen(str);
	int startIndex = 0;

	while (startIndex < len && str[startIndex] == ' ')
	{
		startIndex++;
	}

	if (startIndex > 0)
	{
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
/**
 * _str1_len - the lenght of a string till a delimeter
 *
 * @s: string parameter input
 * @deli: where the function should stop counting
 *
 * Return: length of string
 */

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

/**
 * _strncat - concatinates a number n of two variables
 *
 * @src: string parameter input
 * @dest: string would be modified
 * @n: number of strings
 *
 * Return: no return
 */

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
