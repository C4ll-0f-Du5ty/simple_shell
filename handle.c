#include "shell.h"

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
 * @str: the input string
 *
 * Return: no return
 */

void leave(char *str)
{
	free(str);
	exit(EXIT_SUCCESS);
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
	write(STDOUT_FILENO, "\033[H\033[J", 6);
}

/**
 * handler - to handle the clear and exit function
 *
 * @str: the input string
 *
 * Return: no return
 */

void handler(char *str)
{
	formatHandler arr[] = {{"exit", leave}, {"clear", _clear}};
	int i = 0;

	while (str)
	{
		if (_strcmp(str, arr[i].name) == 0)
		{
			arr[i].functions(str);
			break;
		}
		i++;
	}
}
