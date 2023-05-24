#include "shell.h"
/**
 * smach - See if two strings are matching
 * @s1: string 1
 * @s2: string 2
 * Description: Returns a match if either string reaches \0 or space
 *
 * Return: 1 if match, 0 if not match
 */
int smach(char *s1, char *s2)
{
	int x;

	if (s1 == NULL || s2 == NULL)
		return (0);
	for (x = 0; s1[x] == s2[x]; x++)
	{
		if (s1[x] == '\0' || s2[x] == '\0')
			return (1);
		if (chesp(s1[x]) || chesp(s2[x]))
			return (1);
	}
	if (s1[i] == '\0' || s2[i] == '\0')
		return (1);
	if (chesp(s1[i]) || chesp(s2[i]))
		return (1);
	return (0);
}
/**
 * stach - Find if strings match, w multiple delims to stop the match
 * @s1: string one
 * @s2: string two
 * @delim: delimiters to stop the match on
 * Description: \0 is ALWAYS a condition to stop the match and return true.
 *				Argument 'delim' gives the function additional chars to
 *				stop the matching and return true with.
 * Return: 1 if match, 0 if no match.
 */
int stach(char *s1, char *s2, char *delim)
{
	int x;

	if (s1 == NULL || s2 == NULL || delim == NULL)
		return (0);

	for (x = 0; s1[x] == s2[x]; x++)
		if (chach(s1[x], delim))
			return (1);

	if (chach(s1[x], delim) || chach(s2[x], delim))
		return (1);

	return (0);
}
/**
 * chach - Find if char matches any given nds
 * @c: char to match
 * @nds: string to search for matching char
 * Description: Returns true if char 'c' is a match for any character in
 *				nds, including \0. Therefore it is always a match
 *				if 'c' is \0. By design.
 * Return: 1 if match, 0 if no match.
 */
int chach(char c, char *nds)
{
	if (nds == NULL)
		return (0);

	do {
		if (c == *nds)
			return (1);
	} while (*nds++);

	return (0);
}
