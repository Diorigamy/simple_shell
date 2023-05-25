#include "shell.h"
/**
 * main - entry to Shell
 * @argc: argument count
 * @argv: all arguments
 * @envp: environmental variable list of main program
 * Return: 0 on success.
 */
int main(int argc, char **argv, char **envp)
{
	char **arg_list;
	env_t *env_p;
	int retrn_value;
	buffer b = {NULL, BUFSIZE, 0};
	(void)argc, (void)argv, (void)envp;

	b.buf = safe_malloc(sizeof(char) * b.size);
	arg_list = NULL;
	retrn_value = 0;

	env_p = create_envlist();
	history_wrapper("", env_p, 'c');
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signal_handler);
	while (1)
	{
		if (!more_cmds(&b, retrn_value))
		{
			print_cmdline();
			_getline(&b, STDIN_FILENO, env_p);
			history_wrapper(b.buf, env_p, 'a');
		}
		while (alias_expansion(&b, env_p))
			;
		variable_expansion(&b, env_p, retrn_value);
		_getline_fileread(&b, env_p);
		tokenize_buf(&b, &arg_list);
		if (arg_list[0] == NULL)
			continue;
		retrn_value = run_builtin(arg_list, env_p, b.size);
		if (retrn_value != 0 && retrn_value != 2)
			retrn_value = run_execute(arg_list, env_p, b.size);
	}
	return (0);
}
/**
 * more_cmds -reads the next command
 * @b: buffer structure
 * @retrn_value: Return value from last command
 * Description: Handles ; && and || in the case of multiple inputs
 * Return: 1 if there is another command, else 0
 */
int more_cmds(buffer *b, int retrn_value)
{
	if (b->bp == 0)
		return (0);

	while (b->buf[b->bp] != '\0')
	{
		if (b->buf[b->bp] == ';')
		{
			trim_cmd(b);
			return (1);
		}
		if (b->buf[b->bp] == '&' && retrn_value == 0)
		{
			trim_cmd(b);
			return (1);
		}
		if (b->buf[b->bp] == '|' && retrn_value != 0)
		{
			trim_cmd(b);
			return (1);
		}
		b->bp++;
	}
	b->bp = 0;
	return (0);
}
/**
 * trim_cmd - move past cmd flowcontrol point at given buffer position
 * @b: buffer structure
 * Description: helper function for more_cmds.
 */
void trim_cmd(buffer *b)
{
	int flag;

	flag = 0;
	while (b->buf[b->bp] == ';')
		b->bp++, flag = 1;
	if (flag)
		return;

	while (b->buf[b->bp] == '|')
		b->bp++, flag = 1;
	if (flag)
		return;

	while (b->buf[b->bp] == '&')
		b->bp++;
}
