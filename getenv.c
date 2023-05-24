#include "shell.h"
/**
 * print_cmdline - prints the command line or PS1
 */
void pinp(void)
{
	char *str;

	str = "(^.^) ";
	write(0, str, 6);
}
/**
 * maloc - allocates memory and handles errors
 * @size: size of space to allocate
 *
 * Return: pointer to new space
 */
void *maloc(size_t size)
{
	void *tmp;

	tmp = malloc(size);
	if (tmp == NULL)
	{
		rw("Out of Memory, Exiting (._.)\n");
		freed(FREE_ADDRESSES);
		_exit(4);
	}
	freed(tmp);
	return (tmp);
}
/**
 * werr - Write to standard error
 * @s: string to write to stderr
 */
void werr(char *s)
{
	write(STDERR_FILENO, s, slen(s));
}
/**
 * delv - removes varaiable name of an environemental variable
 * @envp: the environemental varaible name and value string
 * @name: the variable name to search for
 * @lenp: the size of the path
 * Return: a string containing the path
 */

char *delv(env *envp, char *arg, int lenp)
{
	char *pwd;
	env *temp;

	pwd = maloc(sizeof(char) * lenp);
	mset(pwd, '\0', lenp);
	temp = envp;
	for (; ; temp = temp->nxt)
	{
		if (smach(temp->val, arg))
		{
			scpy(pwd, temp->val);
			break;
		}
		else if (temp->nxt == NULL)
		{
			fr(pwd);
			return (NULL);
		}
	}
	while (*pwd != '=')
		pwd++;
	pwd++;
	return (pwd);
}
/**
 * retenv - get a the value from an env variable
 * @env_g: the env list
 * @name: key/name of the env variable
 * Return: a pointer to the value, NULL if none found
 */
char *retenv(env *env_g, char *nm)
{
	char *value;

	while (1)
	{
		if (smach(env_g->val, nm))
		{
			value = env_g->val;
			break;
		}
		else if (env_g->nxt == NULL)
			return (NULL);
		env_g = env_g->nxt;
	}
	while (*value++ != '=')
		;
	return (value);
}
