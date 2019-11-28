#include "shell.h"
/**
 * print_number- writes the character c to stdout
 *
 *@n: the number to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

void print_number(int n)
{
	int b, m;
	unsigned int c;

	b = 10;
	c = n;
	if (n >= 0 && n < 10)
	{
		_putchar(n + '0');
	}
	else if (n < 0 && n > -10)
	{
		n *= -1;
		_putchar('-');
		_putchar(n + '0');
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			_putchar('-');
		}
		c = n;
		while (c / b > 9)
		{
			b *= 10;
		}
		while (b > 0)
		{
			m = c / b;
			c %= b;
			_putchar(m + '0');
			b /= 10;
		}
	}
}
/**
 * _strstr - prints a char in memory
 * @haystack: the address of memory to print
 * @needle: the char to print
 *
 * Return: s.
 */

char *_strstr(char *haystack, char *needle)
{
	int l, l2, i, j, a;

	l = 0, l2 = 0;
	while (haystack[l] != '\0')
		l++;
	while (needle[l2] != '\0')
		l2++;
	for (i = 0; i < l; i++, haystack++)
	{
		for (j = 0, a = 0; j < l2; j++)
		{
			if (haystack[j] == 0)
				break;
			if (haystack[j] == needle[j])
			{
				a += 1;
			}
		}
		if (a == l2)
			return (haystack);
	}
	return (0);
}

/**
 * _charncat - Function that concatenates two strings.
 * @dest: String destination.
 * @src: Source String.
 *
 * Return: dest.
 */

char *_charncat(char *dest, char src)
{
	int a;

	a = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	dest[a] = src;
	dest[++a] = 0;
	return (dest);
}
