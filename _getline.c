#include "shell.h"
/**
 * cpy - check the code for Holberton School students.
 * @src: size of the lenght
 * @dest: string
 * @size: int
 *
 *Return: Always 0.
 */

char *cpy(char *src, char *dest, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - check the code for Holberton School students.
 * @ptr: size of the lenght
 * @old_size: int
 * @new_size: int
 *
 *Return: Always 0.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr2;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		ptr2 = malloc(new_size);
		if (!ptr2)
			return (NULL);
		free(ptr);
		return (ptr2);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	ptr2 = malloc(new_size);
	if (!ptr2)
		return (NULL);
	cpy(ptr, ptr2, old_size);
	free(ptr);
	return (ptr2);
}
/**
 * _readchar - custom getline currently reads 1 char at a time from a file
 * descriptor
 * @buffer: address of pointer to input commands buffer
 * @buff_size: maxsize of input character string, realloc if necessary
 *
 * Return: number of characters
 */
ssize_t _readchar(char **buffer, size_t *buff_size)
{
	unsigned int j;
	size_t count, iterations;

	count = 0;
	iterations = 1;
	j = 0;

	while (1)
	{
		if (read(STDIN_FILENO, (*buffer + j), 1) <= 0)
		{
			count = -1;
			break;
		}
		if ((*buffer)[j++] == '\n')
		{
			(*buffer)[j - 1] = '\0';
			break;
		}
		if (count++ % *buff_size == 0)
			*buffer = _realloc(*buffer, count, (*buff_size * ++iterations));
	}

	return ((ssize_t)count);
}
/**
 * _getline - custom getline
 * @buffer: address of pointer to input commands buffer
 * @buff_size: maxsize of input character string, realloc if necessary
 *
 * Return: number of characters
 */

ssize_t _getline(char **buffer, size_t *buff_size)
{
	ssize_t count;

	count = _readchar(buffer, buff_size);

	return (count);
}
