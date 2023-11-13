#include "shell.h"

// void _env(void)
// {
//     char **environment = environ;
//     while (*environment)
//     {
//         printf("%s\n", *environment);
//         environment++;
//     }
// }

void _env(char *envp[])
{
    int i = 0;

    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
}

void leave(char *str)
{
    free(str);
    exit(EXIT_SUCCESS);
}

void _clear(char *str)
{
    write(STDOUT_FILENO, "\033[H\033[J", 6);
}

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

int isInteractive()
{
    return isatty(fileno(stdin)); // Checks if the standard input is a terminal
}

void interactiveMode(char *possiblePaths[], char *envp[], char *argv[])
{
    size_t n = 0;
    char *str = NULL;
    int leanth = 0;
    int counter = 1;

    while (printf(" >_ ") && getline(&str, &n, stdin) != -1)
    {
        trimLeadingSpaces(str);
        leanth = _strlen(str);

        if (str[leanth - 1] == '\n')
        {
            str[leanth - 1] = '\0';
            leanth--;
        }

        if (str == NULL)
        {
            continue;
        }
        else
        {
            if (_strcmp(str, "exit") == 0 || _strcmp(str, "clear") == 0)
            {
                handler(str);
                continue;
            }
            else if (_strcmp(str, "env") == 0)
            {
                _env(envp);
            }
            else
                executeCommand(str, possiblePaths, counter, argv);
            counter++;
        }
    }

    free(str);
}

void nonInteractiveMode(char *possiblePaths[], char *envp[], char *argv[])
{
    char *line = NULL;
    size_t len = 0;
    int counter = 1;

    while (getline(&line, &len, stdin) != -1)
    {
        trimLeadingSpaces(line);
        int length = _strlen(line);

        if (line[length - 1] == '\n')
        {
            line[length - 1] = '\0';
            length--;
        }

        executeCommand(line, possiblePaths, counter, argv);
    }

    free(line);
}