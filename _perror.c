#include "shell.h"
/**
 * print_error - custom perror
 * @arg0: input error string to write to stderr
 * @arg1: input error string to write to stderr
 * @status: the number of the status
 * Return: void
 */
void print_error(char *arg0, char *arg1, int status)
{
	if (status == 0)
	{
		if (arg1[0] == '/')
		{
			write(STDERR_FILENO, arg1, _strlen(arg1));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, arg1, _strlen(arg1));
			write(STDERR_FILENO, ": Syntax error: \"(\" unexpected\n", 32);
		}
		else
		{
			write(STDERR_FILENO, arg0, _strlen(arg0));
			write(STDERR_FILENO, ": 0: Can't open ", 16);
			write(STDERR_FILENO, arg1, _strlen(arg1));
			write(STDERR_FILENO, "\n", 1);
		}
	}
	else
	{
		write(STDERR_FILENO, arg0, _strlen(arg0));
		write(STDERR_FILENO, ": ", 2);
		print_number(status);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, arg1, _strlen(arg1));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
/**
 * _perror - custom perror
 * @s: input error string to write to stderr
 *
 * Return: void
 */
void _perror(char *s)
{
	write(STDERR_FILENO, s, _strlen(s));
}
