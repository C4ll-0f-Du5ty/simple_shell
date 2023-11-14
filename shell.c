#include "shell.h"

/**
 * main - my main scope
 *
 * @argc: number of arguments passed
 * @argv: a variable holds the file names
 * @envp: a variable holds the environment
 *
 * Return: no return
 */

int main(int argc, char *argv[], char *envp[])
{
	char *possiblePaths[MAX_ARGS];
	(void)argc;

	getPathTokens(possiblePaths, envp);

	if (isInteractive())
	{
		interactiveMode(possiblePaths, envp, argv);
	}
	else
	{
		nonInteractiveMode(possiblePaths, envp, argv);
	}
	return (0);
}
