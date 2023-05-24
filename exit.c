#include "shell.h"
/**
 * hexit - mimics exit
 * @list: argument list given by user
 * @env_n: linked list
 * @length: size of path
 * Return: 0
 */
int hexit(char **list, env *env_n, int length)
{
	(void) length;
	int temp;

	if (list[1] != NULL)
	{
		if (!(digits(list[1][0])))
			return (2);
	}
	temp = s_2i(list[1]);
	svd_hits("", env_n, 'w');
	freed(FREE_ADDRESSES);
	_exit(temp & 0377);
	return (0);
}
/**
 * sh_exit_help - help print out 
 * Return: 0
 */
int h_exit_help(void)
{
	wr("exit usage: exit N\n    Exit the shell.\n\n    ");
	wr("Exits the shell with a status of N.  If N is omitted, ");
	wr("the exit status\n    is that of the last command executed.\n");
	return (0);
}

