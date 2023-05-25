#include "shell.h"
/**
 * write_history - writes the history.
 * @envp: list for finding path
 * @history: linked list of what to write in
 * Return: 0 or 1
 */

int  write_history(env_t *envp, hist_t *history)
{
	hist_t *temp, *temp_c;
	char *path;
	int fd, count;

	count = 0;
	history = history->next;
	for (temp_c = history; temp_c != NULL; temp_c = temp_c->next)
		count++;
	if (count > 4096)
	{
		count = count - 4096;
		while (count > 0)
		{
			history = history->next;
			count--;
		}
	}
	path = safe_malloc(sizeof(char) * BUFSIZE);
	_memset(path, '\0', BUFSIZE);
	path = rm_vname(envp, "HOME=", BUFSIZE);
	if (path == NULL)
	{
		_write("Error: failed to find history file\n");
		_write("Cannot write history\n");
		return (1);
	}
	_strcat(path, "/.simple_shell_history");
	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	for (temp = history; temp != NULL; temp = temp->next)
	{
		write(fd, temp->cmd, _strlen(temp->cmd));
		write(fd, "\n", 1);
	}
	_free(history);
	close(fd);
	return (0);
}
/**
 * add_cmdhist - add new command to the linked list
 * @history: history linked list
 * @cmd: command to put into the history
 */

void add_cmdhist(hist_t *history, char *cmd)
{
	static int hist_index = 1;
	int i, len;
	hist_t *temp;
	char *new_cmd;

	new_cmd = safe_malloc(sizeof(char) * _strlen(cmd) + 1);
	temp = history;
	if (hist_index == 1)
		for (temp = history; temp != NULL; temp = temp->next)
			hist_index++;
	len = _strlen(cmd);
	for (i = 0; i < len - 1; i++)
		new_cmd[i] = cmd[i];
	new_cmd[i] = '\0';
	if (len > 1)
		add_history(history, new_cmd);
	hist_index++;
	_free(new_cmd);
}
