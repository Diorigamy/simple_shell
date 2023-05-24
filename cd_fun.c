#include "shell.h"

/**
 * pach - function to return the path to change directory
 * @largs: arg list given by user (directory to change to)
 * @env_p: environemental linked list to find HOME and OLDPWD
 * @lenp: size of the buffer
 * Return: returns the path to change, returns NULL if HOME
 * or OLDPWD is not found
 */

char *pach(char **largs, env *env_p, int lenp)
{
	char *path;
	int n, m;

	path = maloc(sizeof(char) * lenp);
	mset(path, '\0', lenp);
	n = m = 1;
	if (largs[1] != NULL)
	{
		n = scmp(largs[1], "~");
		m = scmp(largs[1], "-");
	}
	if (largs[1] == NULL || n == 0)
	{
		path = retenv(env_p, "HOME=");
		if (path == NULL)
		{
			rw("Error: variable Home not found\n");
			return (NULL);
		}
	}
	else if (largs[1] != NULL && m == 0)
	{
		path = retenv(env_p, "OLDPWD=");
		if (path == NULL)
		{
			rw("Error: variable OLDPWD not found\n");
			return (NULL);
		}
		rw(path), rw("\n");
	}
	else if (largs[1][0] == '/')
		path = largs[1];
	else
	{
		getcwd(path, lenp);
		_strcat(path, "/");
		_strcat(path, largs[1]);
	}
	return (path);
}
