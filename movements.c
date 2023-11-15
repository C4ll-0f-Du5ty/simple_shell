#include "shell.h"

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
		fprintf(stderr, "cd: missing argument\n");
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
