#include "shell.h"
/**
 * _exit - builtin command _exit, mimics exit
 * @list: list given by user input
 * @envp: environmental linked list
 * @length: the size of path
 * Return: 0 on success;
 */
int _exit(char **list, env *envp, int length)
{
	int tmp;
	(void) length;

	if (list[1] != NULL)
	{
		if (!(digits(list[1][0])))
		{
			/*rw("exit: Expression Syntax.\n");*/
			return (2);
		}
	}
	tmp = s2i(list[1]);
	svd_hist("", envp, 'w');
	freed(FREE_ADDRESSES);
	_exit(tmp & 0377);
	return (0);
}
/**
 * h_exit_help - builtin help printout for exit
 * Return: Always 0
 */
int h_exit_help(void)
{
	rw("exit usage: exit N\n    Exit the shell.\n\n    ");
	rw("Exits the shell with a status of N.  If N is omitted, ");
	rw("the exit status\n    is that of the last command executed.\n");
	return (0);
}
