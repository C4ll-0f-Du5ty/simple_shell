#include "shell.h"

// void executeCommand(command x, char *arguments[])
// {
//     pid_t pid = fork();
//     int i;

//     if (pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0)
//     {
//         // char **arguments = malloc(sizeof(char *) * (sizeof(x.arguments) + 2));
//         // if (arguments == NULL)
//         // {
//         //     perror("malloc");
//         //     exit(EXIT_FAILURE);
//         // }
//         // arguments[0] = x.path;
//         // for (i = 0; arguments[i]; i++)
//         // {
//         //     arguments[i + 1] = x.arguments[i];
//         // }
//         // arguments[1 + sizeof(x.arguments) / sizeof(char *)] = NULL;
//         if (execve(x.path, arguments, NULL) == -1)
//         {
//             perror("execve");
//             exit(EXIT_FAILURE);
//         }
//     }
//     else
//     {
//         int status;
//         wait(&status);
//     }
// }

void concatenate(char *dest, char *src1, char *src2, size_t destSize)
{
    _strncpy(dest, src1, destSize);
    _strncat(dest, "/", destSize - strlen(dest));
    _strncat(dest, src2, destSize - strlen(dest));
}

void executeCommand(char *command, char *paths[], int counter, char *argv[])
{
    pid_t child = fork();
    // char *args[MAX_ARGS];
    size_t length = _strlen(command) + 1;
    char **args = malloc(sizeof(char) * length);
    int i = 0;

    if (child == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    parseArguments(command, args, length);
    if (child == 0)
    {

        // if (args[0] == NULL)
        // {
        //     printf("Invalid command\n");
        //     exit(EXIT_FAILURE);
        // }

        if (strchr(args[0], '/') != NULL)
        {
            execve(args[0], args, NULL);
        }
        else
        {
            char fullPath[MAX_ARGS];
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

// int specifier1(char *c, command specifier[], size_t size)
// {
//     int i;

//     for (i = 0; i < size; i++)
//     {
//         if (_strcmp(c, specifier[i].name) == 0 || _strcmp(c, specifier[i].path) == 0)
//         {
//             return (i);
//         }
//     }

//     return (-1);
// }

// int parseArguments(char *input, char *arguments[], int maxArguments)
// {
//     int argCount = 0;
//     int argStart = 0;
//     char deli = ' ';
//     int len;

//     while (*input != '\0')
//     {
//         if (argCount >= maxArguments - 1)
//         {
//             break;
//         }

//         len = 0;
//         while (input[len + argStart] != '\0' && input[len + argStart] != deli)
//         {
//             len++;
//         }
//         if (len != 0)
//         {
//             arguments[argCount] = (char *)malloc(len + 1);
//             _strncpy(arguments[argCount], input + argStart, len);
//             arguments[argCount][len] = '\0';
//             argCount++;
//             argStart += len + 1;
//         }
//         else
//             break;

//         if (argCount == 1)
//         {
//             // If this is the first argument, treat it as the command itself
//             free(arguments[0]); // Free the previously allocated memory
//             argCount--;         // Decrease the argument count
//         }
//     }
//     arguments[argCount] = NULL; // Set the last argument to NULL

//     int i = 0;
//     while (arguments[i] != NULL)
//     {
//         printf("%s ", arguments[i]);
//         i++;
//     }
//     // for (i = 0; i < argCount; i++)
//     // {
//     //     free(arguments[i]); // Free allocated memory
//     // }
//     return argCount;
// }

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

// void parseArguments(const char *input, char *arguments[], int maxArguments)
// {
//     int i;
//     for (i = 0; i < maxArguments; i++)
//     {
//         arguments[i] = NULL;
//     }

//     char *token = strtok((char *)input, " \n");
//     int argCount = 0;

//     while (token != NULL && argCount < maxArguments - 1)
//     {
//         arguments[argCount] = token;
//         argCount++;

//         // If the token ends with a double quote, combine tokens until the next double quote is found
//         if (token[strlen(token) - 1] == '"')
//         {
//             while (token[strlen(token) - 1] != '"' && token[strlen(token) - 2] != '\\')
//             {
//                 token = strtok(NULL, " \n");
//                 if (token == NULL)
//                 {
//                     break;
//                 }
//                 strcat(arguments[argCount - 1], " ");
//                 strcat(arguments[argCount - 1], token);
//             }
//         }

//         token = strtok(NULL, " \n");
//     }
// }

// void parseArguments(const char *input, char *arguments[], int maxArguments)
// {
//     int argCount = 0;
//     char *token = strtok((char *)input, " ");
//     char *start = NULL;
//     int inQuotes = 0;

//     while (token != NULL && argCount < maxArguments - 1)
//     {
//         if (inQuotes)
//         {
//             if (token[strlen(token) - 1] == '"')
//             {
//                 inQuotes = 0;
//                 token[strlen(token) - 1] = '\0';
//                 strcat(start, " ");
//                 strcat(start, token);
//                 arguments[argCount++] = start;
//             }
//             else
//             {
//                 strcat(start, " ");
//                 strcat(start, token);
//             }
//         }
//         else
//         {
//             if (token[0] == '"')
//             {
//                 inQuotes = 1;
//                 start = token + 1;
//                 if (token[strlen(token) - 1] == '"')
//                 {
//                     inQuotes = 0;
//                     token[strlen(token) - 1] = '\0';
//                     arguments[argCount++] = start;
//                 }
//             }
//             else
//             {
//                 arguments[argCount++] = token;
//             }
//         }

//         token = strtok(NULL, " ");
//     }

//     arguments[argCount] = NULL; // Set the last argument to NULL
// }
