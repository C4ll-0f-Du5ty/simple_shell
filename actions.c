#include "shell.h"

/**
 * getPathTokens - to tokenize the paths so i can loop freely on
 *
 * @paths: where to store the paths
 * @envp: a variable holds the environment
 *
 * Return: no return
 */

void getPathTokens(char *paths[], char *envp[])
{
	char *Pathvar = NULL;
	char *token;
	int i;

	for (i = 0; envp[i]; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
		{
			Pathvar = envp[i] + 5;
			break;
		}
	}

	if (Pathvar == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(Pathvar, ":");
	for (i = 0; token; i++)
	{
		paths[i] = token;
		token = strtok(NULL, ":");
	}

	paths[i] = NULL;
}

/**
 * isInteractive - test for my current state
 *
 *
 * Return: an intiger to indicate which one
 */

int isInteractive(void)
{
	return (isatty(fileno(stdin)));
}

/**
 * interactiveMode - to handle the clear and exit function
 *
 * @possiblePaths: the array where we store paths
 * @envp: a variable holds the environment
 * @argv: a variable holds the file names
 * Return: no return
 */

void interactiveMode(char *possiblePaths[], char *envp[], char *argv[])
{
	size_t n = 0;
	char *str = NULL;
	int leanth = 0;
	int counter = 1;

	while (1)
	{
		while (printf(" >_ ") && getline(&str, &n, stdin) != -1)
		{
			trimLeadingSpaces(str);
			leanth = _strlen(str);
			if (str[leanth - 1] == '\n')
			{
				str[leanth - 1] = '\0';
				leanth--;
			}
			if (_strlen(str) < 1)
			{
				continue;
			}
			else
			{
				if (_strcmp(str, "clear") == 0)
				{
					_clear(str);
					continue;
				}
				else if (_strcmp(str, "env") == 0)
				{_clear(str);
					_env(envp);
					continue;
				}
				else
					executeCommand(str, possiblePaths, counter, argv);
				counter++;
			}
		} free(str);
	}
}

/**
 * nonInteractiveMode - to handle the clear and exit function
 *
 * @possiblePaths: the array where we store paths
 * @envp: a variable holds the environment
 * @argv: a variable holds the file names
 * Return: no return
 */

void nonInteractiveMode(char *possiblePaths[], char *envp[], char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	int counter = 1;
	int length;

	while (getline(&line, &len, stdin) != -1)
	{
		trimLeadingSpaces(line);
		length = _strlen(line);

		if (line[length - 1] == '\n')
		{
			line[length - 1] = '\0';
			length--;
		}
		if (_strlen(line) < 1)
		{
			continue;
		}
		else
		{
			if (_strcmp(line, "clear") == 0)
			{
				_clear(line);
				continue;
			}
			else if (_strcmp(line, "env") == 0)
			{
				_env(envp);
				continue;
			}
			else
				executeCommand(line, possiblePaths, counter, argv);
			counter++;
		}
	}

	free(line);
}
