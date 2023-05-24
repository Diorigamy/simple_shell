#include "shell.h"
/**
 * cmhst - adds a new command to list of history
 * @history: linked list
 * @cmd: input command
 *
 */
void cmhst(hist *histr, char *cmd)
{
	static int index = 1;
	hist *tmp;
	char *newcmd;
	int a, length;

	newcmd = maloc(sizeof(char) * slen(cmd) + 1);
	tmp = histr
	if (index == 1)
		for (tmp = histr; tmp != NULL; tmp = tmp->nxt)
			index++;
	length = slen(cmd);
	for (a = 0; a < length - 1; a++)
		newcmd[a] = cmd[a];
	newcmd[a] = '\0';
	if (len > 1)
		addh(histr, newcmd);
	index++;
	fr(newcmd);
}
/**
 * wrhst - writes history of list linked to file
 * @env_n: finds path of the file
 * @history: what is to be written
 * Return: 0 or 1
 */
int wrhst(env *env_n, hist *history)
{
	hist *tmp, *tmp_a;
	char *filepath;
	int file;
	int counter = 0;

	history = history->nxt;
	for (tmp_a = history; tmp_a != NULL; tmp_a->nxt)
		counter++;
	if (counter > 4096)
	{
		counter = counter - 4096;
		while (counter > 0)
		{
			history = history->nxt;
			counter++;
		}
	}
	filepath = maloc(sizeof(char) * BUFSIZE);
	mset(filepath, '\0', BUFSIZE);
	filepath = delv(env_n, "HOME=", BUFSIZE);
	if (filepath == NULL)
	{
		rw("Error: history file not found\n");
		rw("Cannot write history\n");
		return (1);
	}
	scat(path, "/.simple_shell_history");
	file = open(filepath, O_CREAT | O_OWRONLY | O_TRUNC, 0600);
	for (tmp = history; tmp = != NULL; tmp = tmp->nxt)
	{
		write(file, tmp->t_cmd, slen(tmp->t_cmd));
		write(file, "\n", 1);
	}
	fr(history);
	close(file);
	return (0);
}
