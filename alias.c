#include "shell.h"
/**
 * alias - builtin for alias function
 * @argv: argument vector
 * @env_p: env list
 * @typ: Execution typ for the program, 0 or !0
 * Description: Complicated parent function for the alias functionality
 *				of hsh. Uses two typs to allow it being called from
 *				multiple points from within our program.
 * Return: 0 on success, 2 on failure.
 */
int alias(char **argv, env *env_p, int typ)
{
	static c_alias list = {NULL, NULL, NULL};
	int retrn;
	(void) env_p;

	if (typ == 0)
	{
		argv[0] = falias(&list, argv[0]);
		return (0);
	}
	else
	{
		if (argv[1] == NULL)
			retrn = pallias(&list);
		else if (argv[2] != NULL)
		{
			rw("Error. Too many arguments.");
			return (2);
		}
		else
		{
			retrn = palias(&list, argv);
			if (retrn == 1)
				retrn = addalias(&list, argv);
		}
	}
	return (retrn);
}
/**
 * falias - find alias values matching their key
 * @list: alias linked list
 * @arg: alias to search for
 *
 * Return: matching alias value, or NULL
 */
char *falias(c_alias *list, char *arg)
{
	while (list != NULL && list->key != NULL)
	{
		if (smachic(arg, list->key))
			return (list->val);
		list = list->nxt;
	}
	return (NULL);
}
/**
 * pallias - printout the full alias list
 * @list: alias linked list
 *
 * Return: Always 0
 */
int pallias(c_alias *list)
{
	while (list != NULL && list->key != NULL)
	{
		rw("alias ");
		rw(list->key);
		rw("='");
		rw(list->val);
		rw("'\n");
		list = list->nxt;
	}
	return (0);
}
/**
 * palias - print out an alias if match found
 * @list: alias linked list
 * @argv: argument vector
 *
 * Return: 1 if no match needed, 2 on alias not found, 0 on success
 */
int palias(c_alias *list, char **argv)
{
	char *value;

	value = sewint(argv[1], "=");
	if (value != NULL)
		return (1);

	value = falias(list, argv[1]);
	if (value == NULL)
	{
		rw("alias not found\n");
		return (2);
	}
	else
	{
		rw("alias ");
		rw(argv[1]);
		rw("='");
		rw(value);
		rw("'\n");
	}
	return (0);
}
/**
 * addalias - add, edit, or print alias in the list
 * @list: alias linked list
 * @argv: argument vector
 *
 * Return: Always 0;
 */
int addalias(c_alias *list, char **argv)
{
	c_alias *newnode;
	char *key, *value;
	int i, j;

	value = sewint(argv[1], "=");
	if (value != NULL)
		value += 1;

	value = sdup(value);

	for (i = 0; argv[1][i] != '='; i++)
		;
	key = maloc(sizeof(char) * (i + 1));
	for (j = 0; j < i; j++)
		key[j] = argv[1][j];
	key[j] = '\0';

	while (list->nxt != NULL && !smachic(key, list->key))
		list = list->nxt;
	if (list->key == NULL || smachic(key, list->key))
	{
		list->key = key;
		list->val = value;
	}
	else if (list->nxt == NULL)
	{
		newnode = maloc(sizeof(c_alias));
		newnode->key = key;
		newnode->val = value;
		newnode->nxt = NULL;
		list->nxt = newnode;
	}
	else
		list->val = value;
	return (0);
}
