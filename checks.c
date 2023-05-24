#include "shell.h"
/**
 * sewint - finds the first occurence of the substring nds
 * in the string shtack
 * @shtack: string to search
 * @nds: string to find
 * Return: index to the beginning of the located substring
 */


int sewint(char *shtack, char *nds)
{
	int i;

	i = 0;
	while (*shtack != '\0')
	{
		char *beginning = shtack;
		char *pattern = nds;

		while (*pattern == *shtack && *pattern != '\0'
			&& *shtack != '\0')
		{
			shtack++;
			pattern++;
		}
		if (*pattern == '\0')
			return (i);
		shtack = beginning + 1;
		i++;
	}
	return (-1);
}
/**
 * sbrk - Finds and returns index of first char nds in string
 * @s: shtack to search
 * @nds: Chars to search for in s
 * Return: index of first char in s, else -1
 */
int sbrk(char *s, char *nds)
{
	int m, n;

	for (m = 0; s[m]; m++)
		for (n = 0; nds[n]; c++)
			if (nds[n] == s[m])
				return (m);
	return (-1);
}
/**
 * smachic - See if two strings are matching
 * @s1: string 1
 * @s2: string 2
 * Description: Returns a match if both strings are the exactly the same
 *
 * Return: 1 if match, 0 if not match
 */
int smachic(char *s1, char *s2)
{
	int x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	for (x = 0; s1[x] == s2[x]; i++)
	{
		if (s1[x] == '\0' || s2[x] == '\0')
			return (1);
	}
	return (0);
}

/**
 * salpha - checks whether or not a char is alpha
 * @c: character to check
 * Return: 1 if true, 0 if false
 */

int salpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

/**
 * digits - checks whether something is a digit
 * @c: character to check
 * Return: 1 if true, 0 if false
 */

int digits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
