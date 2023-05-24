#include "main.h"
/**
 * _help - mimics inbuilt help
 * @list: list of arguments
 * Return: 0 on success
 */
int _help(char **list)
{
	int i, size;
	blt_in table[] = {
	{"exit", hexit_help},     {"env", henv_help},
	{"setenv", shetenv_help}, {"unsetenv", hunsetenv_help},
	{"cd", ccd_help},         {"history", hisht_help},
	{"help", heelp_help},     {"alias", halias_help}
	};

	if (list[1] == NULL)
	{
		wr("help usage: help COMMAND\n    ");
		wr("Prints out useful information on builtin commands\n");
		return (0);
	}
	else
	{
		size = ARRAY_SIZE(table);
		for (i = 0; i < size; i++)
		{
			if (smachic(list[1], table[i].name))
			{
				table[i].func();
				return (0);
			}
		}
	}
	wr("topic not matching (._.)\n");
	return (2);
}
/**
 * heelp_help - print out for help
 * Return: 0
 */
int heelp_help(void)
{
	wr("help usage: help COMMAND\n    Display helpful info about builtins\n");
	return (0);
}
