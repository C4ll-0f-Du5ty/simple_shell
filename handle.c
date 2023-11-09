#include "shell.h"

void _env(void)
{
    char **environment = environ;
    while (*environment)
    {
        printf("%s\n", *environment);
        environment++;
    }
}

void leave(char *str)
{
    if (_strcmp(str, "exit") == 0 || _strcmp(str, "quit") == 0)
    {
        free(str);
        exit(EXIT_SUCCESS);
    }
}

void _clear(char *str)
{
    if (_strcmp(str, "clear") == 0)
    {
        write(STDOUT_FILENO, "\033[H\033[J", 6);
    }
}

void handler(char *str)
{
    formatHandler arr[] = {{"exit", leave}, {"clear", _clear}};
    int i = 0;

    while (str != "\0")
    {
        if (_strcmp(str, arr[i].name) == 0)
        {
            arr[i].functions(str);
            break;
        }
        i++;
    }
}