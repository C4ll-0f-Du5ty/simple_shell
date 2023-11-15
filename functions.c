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
	_strncat(dest, "/", destSize - _strlen(dest));
	_strncat(dest, src2, destSize - _strlen(dest));
}

/**
 * executeCommand - A function that executes the commands with checks
 *
 * @command: the input command
 * @paths: the paths where we will look into it.
 * @counter: number of commands
 * @argv: my program file name
 * @envp: a variable holds the environment
 *
 * Return: no reutrn
 */

void executeCommand(char *command, char *paths[],
int counter, char *argv[], char *envp[])
{

	size_t length = _strlen(command) + 1;
	char **args = malloc(sizeof(char *) * length);

	parseArguments(command, args, length);
	if (_strcmp(args[0], "exit") == 0)
	{
		leave(args[1]);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		changeDirectory(args, argv, counter);
	}
	else
	{
		pid_t child = fork();

		if (child == -1)
		{
			perror("fork");
			free(args);
			exit(EXIT_FAILURE);
		}

		if (child == 0)
		{
			executePath(paths, args, argv, counter, envp);
			free(args);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
	free(args);
}

/**
 * executePath - A function that executes the commands with checks
 *
 * @args: the input command seperated
 * @paths: the paths where we will look into it.
 * @counter: number of commands
 * @argv: my program file name
 * @envp: a variable holds the environment
 * Return: no reutrn
 */

void executePath(char *paths[], char **args,
char *argv[], int counter, char *envp[])
{
	char fullPath[MAX_ARGS];
	int i = 0;

	if (_strchr(args[0], '/') != NULL)
	{
		execve(args[0], args, envp);
		perror("execve");
	}
	else
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			size_t len1 = strlen(paths[i]);
			size_t len2 = strlen(args[0]);

			if (len1 + len2 + 2 <= MAX_ARGS)
				concatenate(fullPath, paths[i], args[0], MAX_ARGS);
			else
			{
				fprintf(stderr, "Path too long\n");
				free(args);
				exit(EXIT_FAILURE);
			}
			if (access(fullPath, X_OK) != -1)
			{
				execve(fullPath, args, envp);
				free(args);
				break;
			}
		}
		if (paths[i] == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], counter, args[0]);
			exit(EXIT_FAILURE);
		}
	}
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
		if (argCount > 0 && token[0] == '#')
		{
			break;
		}

		arguments[argCount++] = token;
		token = strtok(NULL, " ");
	}
	arguments[argCount] = NULL;
}
