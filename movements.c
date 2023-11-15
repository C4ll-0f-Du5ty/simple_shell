#include "shell.h"

/**
 * _getenv - A function that executes the commands with checks
 *
 * @n: the input string to search for
 *
 * Return: no reutrn
 */

char *_getenv(char *n)
{
	char *env_var;

	for (int i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (_strncmp(env_var, n, _strlen(n)) == 0 && env_var[_strlen(n)] == '=')
		{
			return (env_var + strlen(n) + 1);
		}
	}
	return (NULL);
}
/**
 * changeDirectory - A function that executes the commands with checks
 *
 * @args: the input directory
 *
 * Return: no reutrn
 */

void changeDirectory(char *args[])
{
	if (args[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		if (access(args[1], F_OK) != 0)
		{
			fprintf(stderr, "-bash: cd: %s: No such file or directory\n", args[1]);
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror("cd");
			}
		}
	}
}
