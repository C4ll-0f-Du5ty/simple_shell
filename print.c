#include "shell.h"

int checkCommandExists(const char *commandName, char *possiblePaths[], int numPaths)
{
    struct stat sb;
    int i;

    for (i = 0; i < numPaths; i++)
    {
        char commandPath[strlen(possiblePaths[i]) + strlen(commandName) + 2];

        if (_strchr(commandName, '/'))
        {
            // If the command name contains a path separator (/), just check if it's executable
            if (stat(commandName, &sb) == 0)
            {
                return 0; // Command found
            }
        }
        else
        {
            sprintf(commandPath, "%s/%s", possiblePaths[i], commandName);
            if (stat(commandPath, &sb) == 0 && S_ISREG(sb.st_mode) && (sb.st_mode & S_IXUSR))
            {
                return i; // Command found at index 'i' in possiblePaths
            }
        }
    }

    printf("%d", i);

    return -1; // Command not found
}

// void getPathTokens(char *paths[], char *envp[])
// {
//     char *pathVar = ""; // Find the PATH variable in the envp array
//     int i;
//     for (i = 0; envp[i] != NULL; i++)
//     {
//         // printf("%s\n", envp[i]);
//         if (_strncmp(envp[i], "PATH=", 5) == 0)
//         {
//             pathVar = envp[i] + 5;
//             break;
//         }
//     }
//     printf("%s\n\n%d\n\n", pathVar, i);

//     char *token = strtok(pathVar, ":");
//     int count = 0;

//     while (token != NULL && count < MAX_ARGS - 1)
//     {
//         paths[count++] = token;
//         token = strtok(NULL, ":");
//     }
//     paths[count] = NULL;
// }

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

    token = strtok(Pathvar, ":");
    for (i = 0; token; i++)
    {
        paths[i] = token;
        token = strtok(NULL, ":");
    }

    paths[i] = NULL;
    free(token);
    free(Pathvar);
}