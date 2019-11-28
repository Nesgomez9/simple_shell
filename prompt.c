#include "shell.h"
/**
 * signalhandler - Ignore CTRL + C.
 *
 * @n: unused variable
 * Return: Nothing.
 */
void signalhandler(int n)
{
	(void) n;
	write(1, "\n$ ", 3);
}
/**
 * exit_function - Exit of the shell
 * @buffercpy: cpy of the buffer
 * @buffer: buffer
 * @procces: number of the process
 * @arg0: name of the shell
 *
 * Return: Nothing.
 */
int exit_function(char *arg0, char **buffercpy, char **buffer, int procces)
{
	char *exit_arg[2];
	int error_e;

	exit_arg[0] = strtok(*buffercpy, " \n\t");
	exit_arg[1] = strtok(NULL, " \n\t");
	error_e = _atoi(exit_arg[1]);
	if (_strcmp("exit", exit_arg[0]) == 0 && error_e >= 0)
	{
		free(*buffer);
		if (exit_arg[1] != NULL && error_e >= 0)
		{
			free(*buffercpy);
			exit(error_e);
		}
		else if (exit_arg[1] == NULL)
		{
			free(*buffercpy);
			exit(0);
		}
	}
	else if (_strcmp(exit_arg[0], "exit") == 0 && error_e < 0)
	{
		print_error(arg0, exit_arg[0], procces);
		return (-1);
	}
	return (0);
}
/**
 * _exec - Exit of the shell
 * @arg1: name of the shell
 * @pro: process
 * @buffercpy: cpy of the buffer
 * @buffer: buffer
 * @tmp: number of the process
 *
 * Return: Nothing.
 */
void _exec(char *arg1, char **buffer, char **buffercpy, char **tmp, int pro)
{
	char *command_line[200];
	int i, exec_status;
	pid_t child_pid;

	for (i = 0; i < 200; i++)
		command_line[i] = NULL;
	command_line[0] = strtok(*buffer, " \n\t");
	for (i = 0; command_line[i++];)
		command_line[i] = strtok(NULL, " \n\t");
	command_line[i] = NULL;
	*tmp = path(command_line[0]);
	command_line[0] = *tmp;
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command_line[0], command_line, environ) == -1)
			print_error(arg1, command_line[0], pro);
		_free(tmp);
		_free(buffercpy);
		_free(buffer);
		kill(getpid(), SIGKILL);
	}
	else
		waitpid((child_pid), &exec_status, 0);
	command_line[0] = NULL;

}
/**
 * f_error - Exit of the shell
 * @arg1: name of the shell
 * @procces: process
 * @arg2: cpy of the buffer
 * @arv: buffer
 *
 * Return: Nothing.
 */

void f_error(int arv, char *arg1, char *arg2, int procces)
{
	if (arv > 1 && arg2[0] == '/')
	{
		print_error(arg1, arg2, procces);
		exit(2);
	}
	else if (arv > 1)
	{
		print_error(arg1, arg2, procces);
		exit(127);
	}
}

/**
 * main - Exit of the shell
 * @arv: int
 * @arg: string
 * Return: Always 0
 */

int  main(int arv, char **arg)
{
	char *tmp, *buffer, *buffercpy;
	size_t bufsize = 1024;
	int atty, status, procces;

	procces = atty = 0;
	f_error(arv, arg[0], arg[1], procces);
	procces = 1;
	status = 0;
	if (!(isatty(STDIN_FILENO)))
		atty = 1;

	while (1)
	{
		buffer = _malloc(bufsize);
		if (atty == 0)
			write(1, "$ ", 2);
		signal(SIGINT, signalhandler);
		status = _getline(&buffer, &bufsize);
		if (status == -1)
		{
			_free(&buffer);
			exit(0);
		}
		buffercpy = _strdup(buffer);
		status = exit_function(arg[0], &buffercpy, &buffer, procces);
		if (status != -1)
			_exec(arg[0], &buffer, &buffercpy, &tmp, procces);
		_free(&tmp), _free(&buffercpy), _free(&buffer);
		procces++;
	}
	return (0);
}
