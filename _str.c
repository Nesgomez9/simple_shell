#include "shell.h"

/**
 * _atoi - writes the character c to stdout
 * @s: The array to be transform
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _atoi(char *s)
{
	int x, y, a, b;
	unsigned int n;

	if (s == NULL)
		return (0);
	x = 0;
	y = 1;
	n = 0;
	b = 1;

	while ((s[x] != '\0' && s[x] < '0') || (s[x] > '9' && s[x] != '\0'))
	{
		if (s[x] < 48 && s[x] > 57 && s[y] >= 48 && s[y] <= 57)
		{
			n = (s[y] - '0');
		}
		y = ++x;
	}
	while (s[x] >= 48 && s[x] <= 57)
	{
		n = (n * 10) + s[x] - '0';
		x++;
	}
	for (a = 0; a < x; a++)
	{
		if (s[a] == '-')
		{
			b *= -1;
		}
	}
	return (n * b);
}
/**
 * _strcmp - Function that concatenates two strings.
 * @s2: String destination.
 * @s1: Source String.
 *
 * Return: dest.
 */

int _strcmp(char *s1, char *s2)
{
	int i, n;

	i = 0;

	if (!s1 || !s2)
		return (-1);

	while (s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			n = 0;
		}
		else
		{
			n = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (n);
}


/**
 * _strlen - writes the character c to stdout
 * @s: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strchr - prints a char in memory
 * @c: the address of memory to print
 * @s: the char to print
 *
 * Return: s.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	if (s[i] == 0 && c != s[i])
	{
		return (0);
	}
	else
	{
		s += i;
		return (s);
	}
}
