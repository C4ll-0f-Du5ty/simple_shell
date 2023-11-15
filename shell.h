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

#define MAX_ARGS 1024

/**
 * struct formatHandler - Struct for handling format specifiers
 * @name: The format specifier
 * @functions: Pointer to the corresponding handler function
 *
 */

typedef struct formatHandler
{
	char *name;
	void (*functions)(char *);
} formatHandler;

void concatenate(char *dest, char *src1, char *src2, size_t destSize);
void executeCommand(char *command, char *paths[], int counter, char *argv[]);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _str1_len(char *s, char deli);
void trimLeadingSpaces(char *str);
void shiftString(char *str, int startIndex);
void parseArguments(char *input, char *arguments[], int maxArguments);
void _clear(char *str);
void leave(char *status_str);
void _env(char *envp[]);
void getPathTokens(char *paths[], char *envp[]);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(const char *str, int character);
void _strncat(char *dest, char *src, size_t n);
int isInteractive(void);
void interactiveMode(char *possiblePaths[], char *envp[], char *argv[]);
void nonInteractiveMode(char *possiblePaths[], char *envp[], char *argv[]);
void executePath(char *paths[], char **args, char *argv[], int counter);
int _atoi(char *str);
void changeDirectory(char *args[]);

#endif
