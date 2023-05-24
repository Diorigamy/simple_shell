#include "shell.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vectors
 * @envp: environmental variable list
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	char **list;
	env env_n;
	int val_return = 0;
	ctr_buf b = {NULL, BUFSIZE, 0};
	(void)argc, (void)argv, (void)envp;

	b.ptr = maloc(sizeof(char) * b.buff);
	list = NULL;
	env_n = mk_lenv();
	svd_hist("", env_n, 'c');
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signh);
	while (1)
	{
		if (!t_cmds(&b, val_return))
		{
			pinp();
			rd_cmd(&b, STDIN_FILENO, env_n);
			svd_hist(b.ptr, env_n, 'a');
		}
		while (expalias(&b, env_n))
			;
		vaxpan(&b, env_n, val_return);
		rd_file(&b, env_n);
		tok_cmd(&b, &list);
		if (list[0] == NULL)
			continue;
		val_return = blt_rin(list, env_n, b.buff);
		if (val_return != 0 && val_return != 2)
			val_return = _rexec(list, env_n, b.buff);
	}
	return (0);
}
/**
 * t_cmds - check for next command
 * @a: buffer structure
 * @val_return: returned value for last command
 * Return: 1 or 0
 *
 */
int t_cmds(ctrl_buf *b, int val_return)
{
	if (b->curr == 0)
		return (0);
	while (b->ptr[b->curr] != '\0')
	{
		if (b->ptr[b->curr] == ';')
		{
			trim_cmd(b);
			return (1);
		}
		if (b->ptr[b->curr] == '&' && val_return == 0)
		{
			trim_cmd(b);
			return (1);
		}
		if (b->ptr[b->curr] == '|' && val_return != 0)
		{
			trim_cmd(b);
			return (1);
		}
		b->curr++;
	}
	b->curr = 0;
	return (0);
}
/**
 * trim_cmd - move beyond flowcontrol of cmd
 * @a: buffer structure
 *
 */
void trim_cmd(ctrl_buf *b)
{
	int flag = 0;

	switch (b->ptr[b->curr])
	{
		case ';':
			while (b->ptr[b->curr] == ';')
			{
				b->curr++;
				flag = 1;
			}
			break;
		case '|':
			while (b->ptr[b->curr] == '|')
			{
				b->curr++;
				flag = 1;
			}
		case '&':
			while (b->ptr[a->curr] == '&')
				b->curr++;
			break;
	}
	if (flag)
		return;
}

