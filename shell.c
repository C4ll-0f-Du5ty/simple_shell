#include "shell.h"

// int main(char *envp[])
// {
//     size_t n = 0;
//     char *str = NULL;
//     char *env[] = {NULL};
//     int y = 0;
//     int leanth = 0;

//     command specifier[] = {
//         {"ls", "/bin/ls"},
//         {"pwd", "/usr/bin/pwd"},
//         {"echo", "/bin/echo"},
//         {"env", "/usr/bin/env"},
//     };

// to get the path done!!
// char *possiblePaths[MAX_ARGS];
// getPathTokens(possiblePaths, envp);
//     size_t specifierSize = sizeof(specifier) / sizeof(specifier[0]);

//     while (printf(":) ") && getline(&str, &n, stdin) != -1)
//     {

//         trimLeadingSpaces(str);
//         leanth = _strlen(str);
//         if (str[leanth - 1] == '\n')
//         {
//             str[leanth - 1] = '\0';
//             leanth--;
//         }

//         if (_strcmp(str, "exit") == 0 || _strcmp(str, "clear") == 0)
//         {
//             handler(str);
//             continue;
//         }
//         else if (_strcmp(str, "env") == 0)
//         {
//             _env();
//             continue;
//         }

//         char *commandArgs[leanth];
//         parseArguments(str, commandArgs, leanth);

//         y = specifier1(str, specifier, specifierSize);
//         if (y != -1)
//         {
//             executeCommand(specifier[y], commandArgs);
//         }
//         else
//         {
//             printf("%s", str);
//         }
//     }

//     free(str);
//     exit(EXIT_SUCCESS);
// }

// int main(int argc, char *argv[], char *envp[])
// {
//     // Other declarations
//     char *env[] = {NULL};
//     int commandIndex;
//     // Initializing your specifier array and other settings...

//     char *possiblePaths[MAX_ARGS];
//     getPathTokens(possiblePaths, envp);

//     while (1)
//     {
//         size_t n = 0;
//         char *str = NULL;
//         int leanth = 0;

//         while (printf(":) ") && getline(&str, &n, stdin) != -1)
//         {
//             trimLeadingSpaces(str);
//             leanth = strlen(str);
//             if (str[leanth - 1] == '\n')
//             {
//                 str[leanth - 1] = '\0';
//                 leanth--;
//             }

//             // if (_strcmp(str, "exit") == 0 || _strcmp(str, "clear") == 0)
//             // {
//             //     handler(str);
//             //     continue;
//             // }
//             // else if (_strcmp(str, "env") == 0)
//             // {
//             //     _env();
//             //     continue;
//             // }
//             if (strlen(str) <= 1)
//             {
//                 continue;
//             }

//             char *commandArgs[leanth];
//             parseArguments(str, commandArgs, leanth);

//             // Search for the command in possiblePaths
//             commandIndex = checkCommandExists(str, possiblePaths, MAX_ARGS);
//             if (commandIndex != -1)
//             {
//                 char commandPath[strlen(possiblePaths[commandIndex]) + strlen(commandArgs[0]) + 2];
//                 if (strchr(commandArgs[0], '/'))
//                 {
//                     sprintf(commandPath, "%s", commandArgs[0]);
//                 }
//                 else
//                 {
//                     sprintf(commandPath, "%s/%s", possiblePaths[commandIndex], commandArgs[0]);
//                 }

//                 executeCommand((command){commandArgs[0], commandPath}, commandArgs);
//             }
//             else
//             {
//                 printf("Command '%s' not found.\n", commandArgs[0]);
//             }
//         }

//         free(str);
//         if (argc > 1 && strcmp(argv[1], "non-interactive") == 0)
//         {
//             break;
//         }
//     }
//     exit(EXIT_SUCCESS);
// }

int main(int argc, char *argv[], char *envp[])
{
    char *possiblePaths[MAX_ARGS];
    getPathTokens(possiblePaths, envp);

    // if (isatty())
    // {
    //     size_t n = 0;
    //     char *str = NULL;
    //     int y = 0;
    //     int leanth = 0;

    //     // to get the path done!!

    //     while (1)
    //     {

    //         while (printf(" >_ ") && getline(&str, &n, stdin) != -1)
    //         {

    //             trimLeadingSpaces(str);
    //             leanth = _strlen(str);

    //             if (str[leanth - 1] == '\n')
    //             {
    //                 str[leanth - 1] = '\0';
    //                 leanth--;
    //             }

    //             if (_strcmp(str, "exit") == 0 || _strcmp(str, "clear") == 0)
    //             {
    //                 handler(str);
    //                 continue;
    //             }
    //             else if (_strcmp(str, "env") == 0)
    //             {
    //                 char **environment = envp;
    //                 while (*environment)
    //                 {
    //                     printf("%s\n", *environment);
    //                     environment++;
    //                 }
    //                 continue;
    //             }
    //             else
    //                 executeCommand(str, possiblePaths);
    //         }

    //         free(str);
    //         exit(EXIT_SUCCESS);
    //     }
    // }

    if (isInteractive())
    {
        interactiveMode(possiblePaths, envp, argv);
    }
    else
    {
        nonInteractiveMode(possiblePaths, envp, argv);
    }
    free(possiblePaths);
}