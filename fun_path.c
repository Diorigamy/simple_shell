#include "shell.h"

/**
 * gpath - copies the $PATH into the string path
 * @path: string to copy the $PATH into
 * @list: environemental variable list
 * Return: 0 if successly found PATH variable and 1 if PATH
 * not found
 */

int gpath(char *path, env *list)
{
	env *temp;

	temp = list;
	for (; temp->nxt != NULL; temp = temp->nxt)
	{
		if (smanch(temp->val, "PATH=") != 0)
		{
			scpy(path, temp->val);
			return (0);
		}
	}
	return (1);
}

/**
 * tokenize_path - creates an array of strings, each string is a directory
 * in the $PATH variable
 * @fpath: array of strings that contains a searchable path for each
 * string space.
 * @path: the string containing $PATH
 * @len: size of buffer
 * Description: This also mallocs fpath with how many directories are
 * found in path.
 * Return: a 2D array of tokens
 */

char **patok(char **fpath, char *path, int len)
{
	int i, count, pos;
	char *temp, *buffer;

	buffer = maloc(sizeof(char) * len);
	buffer[0] = '\0';
	for (i = 0, count = 1; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
			count++;
	}
	count++;
	fpath = maloc(sizeof(char *) * count);
	/* skip the PATH= */
	for (temp = path; *temp != '='; temp++)
		;
	temp++, pos = 0;
	do {
		if (*temp == ':' || *temp == '\0')
		{
			sncat(buffer, "/", 1);
			fpath[pos] = maloc(sizeof(char) * len);
			fpath[pos][0] = '\0';
			sncat(fpath[pos], buffer, slen(buffer));
			pos++;
			buffer[0] = '\0';
		}
		else
			sncat(buffer, temp, 1);
	} while (*temp++);
	fpath[pos] = maloc(sizeof(char *));
	fpath[pos] = NULL;
	return (fpath);
}

/**
 * mpath - checks whether or not the command exist or not
 * @t_cmd: command given by user, need to append to end of path strings
 * @fpath: array of path strings to check for existance of command
 * Description: Checks whether or not a t_cmd exist by trying to open commands
 * in the different path directories.
 * Return: 0 if found and -1 if not;
 */

int mpath(char *t_cmd, char **fpath)
{
	int x, fd;

	for (x = 0; fpath[x] != NULL; x++)
	{
		sncat(fpath[x], t_cmd, slen(t_cmd));
		fd = open(fpath[x], O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			scpy(t_cmd, fpath[x]);
			return (0);
		}
	}
	rw(0, "Error: command not found\n", 25);
	return (-1);
}
