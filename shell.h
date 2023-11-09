#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;

typedef struct formatHandler
{
    char *name;
    void (*functions)(char *);
} formatHandler;

typedef struct command
{
    char *name;
    char *path;
} command;

void executeCommand(command x, char *arguments[]);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _str1_len(char *s, char deli);
void trimLeadingSpaces(char *str);
int specifier1(char *c, command specifier[], size_t size);
void parseArguments(char *input, char *arguments[], int maxArguments);
void handler(char *str);
void _clear(char *str);
void leave(char *str);
void _env(void);

// void _putchar(char *str);
// void _puts(char *str);

#endif
