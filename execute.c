#include "shell.h"
/**
 * _rexec - execution function for command
 * @list: argument list
 * @env_n: variable list
 * @length: size of command
 *
 */
int _rexec(char **list, env *env_n, int length)
{
	int status, i, j;
	char **searchpath = NULL;
	char *command, path;

	i = 0;
	command = maloc(sizeof(char) * length);
	path = maloc(sizeof(char) * length);
	scpy(command, list[0]);
	if (schr(command, '/') != NULL)
		status = _fexec(command, list, env_n);
	else
	{
		j = gpath(path, env_n);
		if (j != 0)
		{
			_rw("Error: PATH cannot be found\n");
			return (127);
		}
		searchpath = patok(searchpath, path, length);
		i = mpath(command, searchpath);
		if (i == 0)
			status = _fexec(command, list, env_n);
	}
	if (i == 0)
		return (status);
	else
		return (127);
}
/**
 * _fexec - runs the execve
 * @command: the path of cmd
 * @list: argument list
 * @env_n: variable list
 * Return: 0 on success
 */
int _fexec(char *command, char **list, env *env_n)
{
	pid_t pid;
	int status, a;
	char **arr;

	pid = fork();
	if (pid == 0)
	{
		arr = lsarr(evn_n);
		a = execve(command, list, arr);
		if (a < 0)
		{
			wr("Error: cannot find command\n");
			return (2);
			_exit(1);
	}
	else
	{
		pid = wait(&status);
		if ((WIFEXITED(status))
			return (status);
	}
	return (2);
}
