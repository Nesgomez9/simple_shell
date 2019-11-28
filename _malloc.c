#include "shell.h"
/**
 * str_concat - Prints the array reverse
 * @s1: string
 * @s2: string
 *
 * Return: Nothing
 */

char *str_concat(char *s1, char *s2)
{
	int i, size1, size2, j;
	char *dest;

	if (s1 == 0)
		s1 = "";
	if (s2 == 0)
		s2 = "";
	for (size1 = 0; s1[size1]; size1++)
	{}
	for (size2 = 0; s2[size2]; size2++)
	{}

	dest = _malloc((size1 + size2 + 1) * sizeof(char));

	for (i = 0; i < size1 ; i++)
		dest[i] = s1[i];
	for (i = 0, j = size1; i <= size2; i++, j++)
		dest[j] = s2[i];

	return (dest);
}
/**
 * _strdup - Prints the array reverse
 * @str: string
 *
 * Return: Nothing
 */

char *_strdup(char *str)
{
	int i, size;
	char *dest;

	if (str == 0)
	{
		return (NULL);
	}
	for (size = 0; str[size] != 0; size++)
	{}
	dest = _malloc((size + 1) * sizeof(char));
	for (i = 0; i < size; i++)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _malloc - mallocs memory of size bytes, prints error message on error
 * @chars: number of bytes to malloc
 *
 * Return: pointer to malloced memory or NULL
 */
char *_malloc(int chars)
{
	char *string;
	int i;

	string = malloc(chars);
	if (string == NULL)
	{
		_perror("No Memory\n");
		exit(1);
	}
	for (i = 0; i < chars; i++)
		string[i] = '\0';
	return (string);
}
/**
 * _free - free and set to null the pointer
 * @ptr: pointer
 *
 * Return: Nothing
 */
void _free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
