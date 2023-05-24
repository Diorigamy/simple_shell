#include "shell.h"
/**
 * rw - Write information to STDOUT
 * @s: string;
 */
void rw(char *s)
{
	write(STDOUT_FILENO, s, slen(s));
}
/**
 * upath - rewrites PWD path to not include sybols
 * @lsarg: arguement list given by the user to determine directory
 * @env_r: environemental variable linked list
 * @path: current path to be updated
 * @lenp: the size of the current path
 * Return: a path without any symbols such as (., .., ~, or -)
 */

char *upath(char **lsarg, env *env_r, char *path, int lenp)
{
	int i, indic, pon;
	char *dir, *npath;

	npath = maloc(sizeof(char) * lenp);
	mset(npath, '\0', lenp);
	scpy(npath, path);
	for (i = 0, indic = 0; npath[i] != '\0'; i++)
	{
		if (npath[i] == '/')
			indic++;
	}
	dir = lsarg[1];
	if (scmp(dir, ".") == 0)
		npath = delv(env_r, "PWD=", lenp);
	else if (scmp(dir, "..") == 0)
	{
		/* check for if things behind it + append*/
		for (pon = 0, i = 0; pon < indic - 1; i++)
		{
			if (npath[i] == '/')
				pon++;
		}
		npath[i - 1] = '\0';
	}
	else if (scmp(dir, "~") == 0)
		npath = delv(env_r, "HOME=", lenp);
	else if (scmp(dir, "-") == 0)
		npath = delv(env_r, "OLDPWD=", lenp);
	return (npath);

}

/**
 * lsarr - converts a linked list to an hldr
 * @env_r: environemental list to convert
 * Return: a 2D hldr containing strings contained in linked list
 */

char **lsarr(env *env_r)
{
	char **hldr;
	env *temp;
	int count, i, len;

	for (temp = env_r, count = 0; temp != NULL; temp = temp->nxt)
		count++;
	hldr = malloc(sizeof(char *) * (count + 1));
	for (temp = env_r, i = 0; temp != NULL; temp = temp->nxt, i++)
	{
		len = slen(temp->val);
		hldr[i] = maloc(sizeof(char) * (len + 1));
		mset(hldr[i], '\0', (len + 1));
		mcpy(hldr[i], temp->val, len);
	}
	hldr[i] = NULL;
	return (hldr);
}

/**
 * scmp - compares two strings
 * @s1: string one to compare
 * @s2: string two to compare
 * Return: an integer less than 0 if s1 is found
 */

int scmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >  s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * scpy - copies string pointed by src to the buffer point to by dest
 * @dest: destination where i want
 * @src: string that i want to copy
 * Return: the point to dest
 */

char *scpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != 0; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';
	return (dest);
}
