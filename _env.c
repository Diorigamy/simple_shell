#include "shell.h"
/**
 * henv - mimics env builtin
 * @list: list of arguments
 * @env_n: variables
 * Return: 0
 */
int henv(char **list, env *env_n)
{
	int a;

	if (list[1] == NULL)
	{
		penv(env_n);
		return (0);
	}
	for (a = 1; list[a] != NULL; a++)
		list[a - 1] = list[a];
	list[a - 1] = list[a];
	return (1);
}
/**
 * h_env_help - printout for env
 * Return: 0
 */
int h_env_help(void)
{
	wr("env usage: env\n    Prints out the current envirornment.\n");
	return (0);
}
