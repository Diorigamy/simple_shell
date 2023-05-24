#include "shell.h"
/**
 * _unsetenv - builtin command _unsetenv, mimics builtin unsetenv
 * @arg: arguement list for unstenv, contains the variable name
 * @envp: the linked list of all environment variables
 * Return: 0 on success and 1 on failure
 * Description: This will delete the node that contains the variable given, if
 * node does not exist then function will succeed
 */
int _unsetenv(char **arg, env *envp)
{
	int count, len;
	env *temp;
	char *name;

	if (arg[1] == NULL)
	{
		/*rw("unsetenv: Too few arguments.\n");*/
		return (2);
	}
	len = slen(arg[1]);
	name = maloc(sizeof(char) * (len + 2));
	mcpy(name, arg[1], len + 1);
	sncat(name, "=", 1);
	/* go through loop to search for environemental variable*/
	for (temp = envp, count = 0; temp != NULL; temp = temp->next)
	{
		if (sewint(temp->value, name) != NULL)
		{
			remonv(&envp, count);
			return (0);
		}
		count++;
	}
	return (2);
}
/**
 * _unsetenv_help - builtin help printout for unsetenv
 * Return: Always 0
 */
int hunsetenv(void)
{
	rw("unsetenv usage: unsetenv VARIABLE:\n    ");
	rw("Remove an envirornment variable.\n");
	return (0);
}
