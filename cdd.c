#include "shell.h"
/**
 * blt_rin - checking largs for builtins and executing found cmd.
 * @largs: argument list
 * @env_r: enviorn list
 * @lenp: buffer size
 * Return: 0 on found builtin, 1 on found nothing, 2 on builtin error
 */
int blt_rin(char **largs, env *env_r, int lenp)
{
	int i, size, status;
	blt_in table[] = {
	{"exit", _exit},     {"env", henv},
	{"setenv", _setenv}, {"unsetenv", _unsetenv},
	{"cd", ccd},         {"history", _hist},
	{"help", _help},     {"alias", halias}
	};

	size = ARRAY_SIZE(table);
	for (i = 0; i < size; i++)
	{
		if (smachic(largs[0], table[i].name))
		{
			status = table[i].func(largs, env_r, lenp);
			return (status);
		}
	}
	return (1);
}
