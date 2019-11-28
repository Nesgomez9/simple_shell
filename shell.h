#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
int _putchar(char c);
void _free(char **ptr);
void _perror(char *s);
void print_error(char *arg0, char *arg1, int status);
void print_number(int n);
char *_malloc(int chars);
char *_charncat(char *dest, char src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char *_strstr(char *haystack, char *needle);
int _atoi(char *s);
char *path(char *command_line);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
ssize_t _readline(char **buffer, size_t *limit);
ssize_t _getline(char **buffer, size_t *limit);
#endif
