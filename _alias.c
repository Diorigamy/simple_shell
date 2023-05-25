#include "shell.h"
/**
 * alias_expansion - function that checks and replaces aliases
 * @b: structure of buffer
 * @env_p: enviornment struct
 * Return: 1 or 0
 */
int alias_expansion(buffer *b, env_t *env_p)
{
	int a, size;
	static int stop = 2;
	char *argv, *argv_copy;

	size = 0, a = 0;
	while (b->buf[b->bp] == ' ' || b->buf[b->bp] == '\t')
		b->bp++;
	while (!_is_whitespace(b->buf[b->bp + size]))
		size++;

	argv = safe_malloc(sizeof(char) * (size + 1));
	argv_copy = argv;

	while (a < size)
		argv[a] = b->buf[b->bp + a], a++;
	argv[a] = '\0';

	hsh_alias(&argv, env_p, 0);

	if (argv != NULL)
	{
		buffer_word_erase(b, b->bp);
		buffer_insert(b, argv, b->bp);
		_free(argv_copy);
		if (stop++ == 10)
		{
			stop = 0;
			return (0);
		}
		return (1);
	}
	else
		_free(argv);
	stop = 0;
	return (0);
}

