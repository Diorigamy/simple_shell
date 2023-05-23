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

	ag = _malloc(sizeof(char *) * 2);
	if (typ == 'c')
		history_sh(NULL, env_n, 0);
	else if (typ == 'a')
	{
		ag[0] = _malloc(sizeof(char) * (_strlen(t_cmd) + 1));
		_memcpy(ag[0], t_cmd, _strlen(t_cmd) + 1);
		history_sh(ag, env_n, 1);
	}
	else if (typ == 'w')
		history_sh(ag, env_n, 2);
}
