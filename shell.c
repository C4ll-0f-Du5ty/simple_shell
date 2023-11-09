#include "shell.h"

int main(void)
{
    size_t n = 0;
    char *str = NULL;
    char *env[] = {NULL};
    int y = 0;
    int leanth = 0;

    command specifier[] = {
        {"ls", "/bin/ls"},
        {"pwd", "/usr/bin/pwd"},
        {"echo", "/bin/echo"},
        {"env", "/usr/bin/env"},
    };

    size_t specifierSize = sizeof(specifier) / sizeof(specifier[0]);

    while (printf(":) ") && getline(&str, &n, stdin) != -1)
    {

        trimLeadingSpaces(str);
        leanth = _strlen(str);
        if (str[leanth - 1] == '\n')
        {
            str[leanth - 1] = '\0';
            leanth--;
        }

        if (_strcmp(str, "exit") == 0 || _strcmp(str, "clear") == 0)
        {
            handler(str);
            continue;
        }
        else if (_strcmp(str, "env") == 0)
        {
            _env();
            continue;
        }

        char *commandArgs[leanth];
        parseArguments(str, commandArgs, leanth);

        y = specifier1(str, specifier, specifierSize);
        if (y != -1)
        {
            executeCommand(specifier[y], commandArgs);
        }
        else
        {
            printf("%s", str);
        }
    }

    free(str);
    exit(EXIT_SUCCESS);
}