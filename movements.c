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
	int i;

	for (i = 0; environ[i] != NULL; i++)
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
 * changeDirectory - Change the current working directory.
 * @args: An array containing the command and directory argument.
 * @counter: number of commands
 * @argv: my program file name
 * Return: No return value.
 */
void changeDirectory(char *args[], char *argv[], int counter)
{
	char *targetDir = args[1];
	char *oldPwd;
	char cwd[MAX_ARGS];

	if (targetDir == NULL || _strcmp(targetDir, "~") == 0)
	{
		targetDir = _getenv("HOME");
	}
	else if (_strcmp(targetDir, "-") == 0)
	{
		targetDir = _getenv("OLDPWD");
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (chdir(targetDir) != 0 && targetDir != NULL)
	{
		fprintf(stderr, "%s: %d: cd: can't cd to %s\n", argv[0], counter, targetDir);
	}
	else
	{
		oldPwd = _getenv("PWD");
		if (oldPwd != NULL)
		{
			setenv("OLDPWD", oldPwd, 1);
		}
		setenv("PWD", cwd, 1);
	}
}
