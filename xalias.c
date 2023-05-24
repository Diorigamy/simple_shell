#include "shell.h"
/**
 * expalias - wrapper function for checking and replacing aliases
 * @b: buffer structure
 * @env_a: enviornment struct to pass along
 * Return: 1 on alias replacement, 0 if no replacement
 */
int expalias(ctrl_buf *b, env *env_a)
{
	static int mov = 2;
	int ch, len;
	char *args, *argcpy;

	len = 0, ch = 0;
	while (b->ptr[b->curr] == ' ' || b->ptr[b->curr] == '\t')
		b->curr++;
	while (!chesp(b->ptr[b->curr + len]))
		len++;

	args = maloc(sizeof(char) * (len + 1));
	argcpy = args;

	while (ch < len)
		args[ch] = b->ptr[b->curr + ch], ch++;
	args[ch] = '\0';

	halias(&args, env_a, 0);

	if (args != NULL)
	{
		berase(b, b->curr);
		bins(b, args, b->curr);
		fr(argcpy);
		if (mov++ == 10)
		{
			mov = 0;
			return (0);
		}
		return (1);
	}
	else
		fr(args);
	mov = 0;
	return (0);
}
