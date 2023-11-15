#include "shell.h"

/**
 * _atoi - to convert strings to integers
 *
 * @str: the string to be converted
 *
 * Return: the integer
 */

int _atoi(char *str)
{
	unsigned int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}

	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i++] == '-') ? -1 : 1;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * _env - to display my environment if needed
 *
 * @envp: a variable holds the environment
 *
 * Return: no return
 */

void _env(char *envp[])
{
	int i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

/**
 * leave - to exit my program
 *
 * @status_str: the status of the exit function
 *
 * Return: no return
 */

void leave(char *status_str)
{
	int status;

	if (status_str == NULL)
	{
		exit(EXIT_SUCCESS);
	}

	status = _atoi(status_str);

	exit(status);
}

/**
 * _clear - to clear the console display
 *
 * @str: the input string
 *
 * Return: no return
 */

void _clear(char *str)
{
	(void)str;
	free(str);
	write(STDOUT_FILENO, "\033[H\033[J", 6);
}
