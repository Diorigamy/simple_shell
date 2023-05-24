#include "shell.h"
/**
 * _setenv - builtin command _setenv, mimics builtin setenv
 * @arg: list of arguements that contain the env name, value and
 * overwrite value
 * @envp: a pointer to the linked list of environmental variables
 * @lenp: buf size to set malloc space
 * Return: 0 on success and 1 on error
 */
int _setenv(char **arg, env *envp, int lenp)
{
	int typ, len, len2;
	char *name;
	env *temp;
	(void) lenp;

	if (arg[1] == NULL || arg[2] == NULL || arg[3] != NULL)
		return (2);
	if (!(salpha(arg[1][0])))
		return (2);
	/* set up all strings up*/
	len2 = slen(arg[2]);
	len = slen(arg[1]);
	name = maloc(sizeof(char) * (len + len2 + 2));
	mcpy(name, arg[1], len + 1);
	sncat(name, "=", 1);

	for (temp = envp, typ = 0; temp != NULL; temp = temp->nxt)
	{
		if (smanch(temp->val, name) != 0)
		{
			scat(name, arg[2]);
			temp->val = name;
			typ = 1;
		}
	}
	if (typ == 0)
	{
		scat(name, arg[2]);
		envadd(&envp, name);
	}
	return (0);
}

/**
 * _setenv_help - builtin help printout for setenv
 * Return: Always 0
 */
int shetenv(void)
{
	rw("setenv usage: setenv VARIABLE VALUE\n    Initialize a new");
	rw(" environment variable, or modify an existing one.\n");
	return (0);
}
