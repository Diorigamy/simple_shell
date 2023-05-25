#include "shell.h"
/**
 *_memset - sets first n bytes of the memory area
 * @s: array to set
 * @b: set at
 * @n: first n bytes
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
	{
		s[a] = b;
	}
	return (s);
}
/**
 * _memcpy - copies n bytes of memory
 * @src: source code to copy
 * @dest: destination
 * @n: bytes to copy
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _strncat - concatenates two strings
 * @dest: dest
 * @src: string to concatenate
 * @n: no of bytes to concatenate
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
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
 * _strcat - appends strings
 * @dest: destination to append
 * @src: what to append
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	/*i++;*/
	dest[i] = '\0';
	return (dest);
}
/**
 * _strstr - finds the first occurence of a substring
 * @haystack: string to search
 * @needle: string to find
 * Return: pointer to located substring
 */
char *_strstr(char *haystack, char *needle)
{

	while (*haystack != '\0')
	{
		char *beginning = haystack;
		char *pattern = needle;

		while (*pattern == *haystack && *pattern != '\0'
		       && *haystack != '\0')
		{
			haystack++;
			pattern++;
		}
		if (*pattern == '\0')
			return (beginning);
		haystack = beginning + 1;
	}
	return (NULL);
}
