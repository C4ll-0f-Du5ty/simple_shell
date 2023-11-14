#include "shell.h"

/**
 * concatenate - A function that concatinates the strings
 *
 * @dest: pointer to destination input buffer
 * @src1: pointer to source input
 * @src2: pointer to source input
 * @destSize: bytes of @src
 *
 * Return: no return
 */

void concatenate(char *dest, char *src1, char *src2, size_t destSize)
{
	_strncpy(dest, src1, destSize);
	_strncat(dest, "/", destSize - strlen(dest));
	_strncat(dest, src2, destSize - strlen(dest));
}

/**
 * executeCommand - A function that executes the commands with checks
 *
 * @command: the input command
 * @paths: the paths where we will look into it.
 * @counter: number of commands
 * @argv: my program file name
 *
 * Return: no reutrn
 */

void executeCommand(char *command, char *paths[], int counter, char *argv[])
{
	pid_t child = fork();
	size_t length = _strlen(command) + 1;
	char **args = malloc(sizeof(char *) * length);
	int i = 0;
	char fullPath[MAX_ARGS];

	if (child == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}

	parseArguments(command, args, length);
	if (child == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			execve(args[0], args, NULL);
			free(args);
		}
		else
		{
			for (i = 0; paths[i] != NULL; i++)
			{
				concatenate(fullPath, paths[i], args[0], MAX_ARGS);
				if (access(fullPath, X_OK) != -1)
				{
					execve(fullPath, args, NULL);
					break;
				}
			}
			if (paths[i] == NULL)
			{
				printf("%s: %d: %s: not found\n", argv[0], counter, args[0]);
				free(args);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		int status;

		wait(&status);
	}
	free(args);
}

/**
 * parseArguments - A function that executes the commands with checks
 *
 * @input: the input command
 * @arguments: the paths where we will look into it after passing it.
 * @maxArguments: max number of arguments allowed
 *
 * description: to token my paths
 * Return: no reutrn
 */

void parseArguments(char *input, char *arguments[], int maxArguments)
{
	char *token = strtok(input, " ");
	int argCount = 0;

	while (token != NULL && argCount < maxArguments - 1)
	{
		arguments[argCount++] = token;
		token = strtok(NULL, " ");
	}
	arguments[argCount] = NULL;
	free(token);
}
