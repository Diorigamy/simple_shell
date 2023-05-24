#include "shell.h"

/**
 * mcpy - copies n bytes form the memory area src
 * to memory area dest
 * @src: source code to copy
 * @dest: destination to copy to
 * @n: how many bytes to copy
 * Return: dest;
 */

char *mcpy(char *dest, char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}

/**
 *mset - sets first n bytes of the memory area
 * @s: array to set
 * @b: what to set it to
 * @n: first n bytes
 * Return: s
 */

char *mset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * scat - appends strings
 * @dest: destination to append
 * @src: what to append
 * Return: pointer to dest
 */

char *scat(char *dest, char *src)
{
	int m, n;

	for (m = 0; dest[m] != '\0'; m++)
	{
	}
	n = 0;
	while (src[n] != '\0')
	{
		dest[m] = src[n];
		n++;
		m++;
	}
	/*i++;*/
	dest[m] = '\0';
	return (dest);
}


/**
 * sncat - concatenates one string (number of byte given)
 * to another
 * @dest: where to concatenate
 * @src: string to concatenate
 * @n: how many bytes to
 * Return: dest
 */

char *sncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * ssew - finds the first occurence of the substring nd
 * in the string shtack
 * @shtack: string to search
 * @nd: string to find
 * Return: pointer to the start of the located substring
 */


char *ssew(char *shtack, char *nd)
{

	while (*shtack != '\0')
	{
		char *start = shtack;
		char *dsn = nd;

		while (*dsn == *shtack && *dsn != '\0'
		       && *shtack != '\0')
		{
			shtack++;
			dsn++;
		}
		if (*dsn == '\0')
			return (start);
		shtack = start + 1;
	}
	return (NULL);
}
