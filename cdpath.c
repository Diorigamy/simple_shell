#include "shell.h"
/**
 * cd_path - returns path to change directory
 * @arg_list: the directory to change to
 * @envp: environemental linked list
 * @buf_size: buffer size
 * Return: returns the path to be changed
 */
char *cd_path(char **arg_list, env_t *envp, int buf_size)
{
	int a, b;
	char *path;

	path = safe_malloc(sizeof(char) * buf_size);
	_memset(path, '\0', buf_size);
	a = b = 1;
	if (arg_list[1] != NULL)
	{
		a = _strcmp(arg_list[1], "~");
		b = _strcmp(arg_list[1], "-");
	}
	if (arg_list[1] == NULL || a == 0)
	{
		path = get_env_value(envp, "HOME=");
		if (path == NULL)
		{
			_write("Error: variable Home not found\n");
			return (NULL);
		}
	}
	else if (arg_list[1] != NULL && b == 0)
	{
		path = get_env_value(envp, "OLDPWD=");
		if (path == NULL)
		{
			_write("Error: variable OLDPWD not found\n");
			return (NULL);
		}
		_write(path), _write("\n");
	}
	else if (arg_list[1][0] == '/')
		path = arg_list[1];
	else
	{
		getcwd(path, buf_size);
		_strcat(path, "/");
		_strcat(path, arg_list[1]);
	}
	return (path);
}

