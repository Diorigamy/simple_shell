#include "shell.h"

/**
 * sdup - returns a pointer to a new string which is a duplicate
 * of string str
 * @str: string to copy
 * Return: pointer to copy of string
 */

char *sdup(char *str)
{
	char *dest;
	unsigned int m, n;

	if (str == NULL)
		return (NULL);
	for (m = 0; str[m] != '\0'; m++)
		;
	m++;
	dest = maloc(m * sizeof(char));
	n = 0;
	while (n < m)
	{
		dest[n] = str[n];
		n++;
	}
	return (dest);
}


/**
 * schr - returns a pointer to the first occurence of the
 * character c in the string s
 * @c: caracter to return
 * @s: string to search character
 * Return: pointer to first occurence of character c or null if not found
 */

char *schr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	else
		return (NULL);
}

/**
 * slen - returns length of string
 * @s: character of string
 * Return: length of string
 */

int slen(char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
		;
	return (i);
}

/**
 * smanch - See if two strings are matching
 * @s1: string 1
 * @s2: string 2
 * Description: Returns a match if either string reaches \0 or space
 *
 * Return: 1 if match, 0 if not match
 */
int smanch(char *s1, char *s2)
{
	int x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	for (x = 0; s1[i] == s2[i]; x++)
	{
		if (s1[x] == '\0' || s2[x] == '\0')
			return (1);
	}
	if (s1[x] == '\0' || s2[x] == '\0')
		return (1);
	return (0);
}
/**
 * s2i - convert a string to a number
 * @s: string to convert
 *
 * Return: number representation of string
 */
int s2i(char *s)
{
	int j;

	if (s == NULL)
		return (0);
	for (j = 0; *s; s++)
		if (*s >= '0' && *s <= '9')
			j = (j * 10) + (*s - '0');
	return (j);
}
