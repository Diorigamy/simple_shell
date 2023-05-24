#include "shell.h"
/**
 * ccd - mimmics builtin cd
 * @list: list of arguments
 * @env_n: linked list
 * @length: size of path
 * Return: 0
 */
int ccd(char **list, env *env_n, int length)
{
	char *filepath, *buf, *pwd;
	int i;

	buf = maloc(sizeof(char) * length), mset(buf, '\0', length);
	pwd = maloc(sizeof(char) * length), mset(pwd, '\0', lngth);
	getcwd(pwd, length);
	filepath = pach(list, env_n, buf_size);
	if (filepath == NULL)
	       return (2);
	i = chdir(filepath);
	if (i < 0)
		return (2);
	else
	{
		getcwd(buf, length);
		renv(env_n, "OLDPWD=", pwd, length);
		renv(env_n, "PWD=", buf, length);
	}
	return (0);
}
/**
 * ccd_help - printount for ccd
 * Return: 0
 */
int ccd_help(void)
{
	wr(("cd usage: cd DIR\n    Change the current directory to DIR.\n");
	return (0);
}
