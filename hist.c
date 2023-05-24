#include "shell.h"
/**
 * svd_hist - actions to be performed for history
 * @t_cmd: a command for adding history
 * @env_n: environmental variable
 * @typ: determines mode of action
 */
void svd_hist(char *t_cmd, env *env_n, char typ)
{
	char **ag;

	ag = maloc(sizeof(char *) * 2);
	if (typ == 'c')
		_hist(NULL, env_n, 0);
	else if (typ == 'a')
	{
		ag[0] = maloc(sizeof(char) * (slen(t_cmd) + 1));
		mcpy(ag[0], t_cmd, slen(t_cmd) + 1);
		_hist(ag, env_n, 1);
	}
	else if (typ == 'w')
		_hist(ag, env_n, 2);
}
