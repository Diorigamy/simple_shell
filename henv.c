#include "shell.h"

/**
 * henv - builtin command henv, mimics sh builtin env
 * @arg_list: arguement list vectors
 * @envp: environmental variables to print
 * Return: 0 if success.
 */
int henv(char **arg_list, env *envp)
{
	int i;

	if (arg_list[1] == NULL)
	{
		penv(envp);
		return (0);
	}
	
	for (i = 1; arg_list[i] != NULL; i++)
		arg_list[i - 1] = arg_list[i];
	arg_list[i - 1] = arg_list[i];
	return (1);
}
/**
 * henv_help - builtin help printout for env
 * Return: Always 0
 */
int h_env_help(void)
{
	rw("env usage: env\n    Prints out the current envirornment.\n");
	return (0);
}
