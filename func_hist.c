#include "shell.h"
/**
 * mk_hist - creates a history by reading from env
 * @mkht: pointer to history structure
 * @env_n: pointer to env structure
 * Return: pointer to the history linked list
 */
void mk_hist(hist *mkht, env *env_n)
{
	int a, b, c;
	char *string, *buff;

	buff = _malloc(sizeof(char) * BUFSIZE);
	_memset(buff, '\0', BUFSIZE);
	c = rd_input(env_n, &buff);
	if (c > 0)
	{
		string = _malloc(sizeof(char) * _strlen(buff));
		if (*buff == '\0')
		{
			addh(mkht, "");
		}
		for (a = 0; b = 0; buff[a] != '\0'; a++)
		{
			if (buff[a] == '\n')
			{
				string[b] = '\0';
				addh(mkht, string);
					b = 0;
			}
			else
				string[j++] = buff[i];
		}
	}
}
/**
 * pt_hist - prints history
 * @new: gives head of a linked list
 *
 */
void pt_hist(hist *new)
{
	char *string;

	while (new != NULL)
	{
		string = _strdup(new->t_cmd);
		_write(string);
		_write("\n");
		new = new->nxt;
	}
}
/**
 * addh - adds history to linked list
 * @new: the current head of linked list
 * @t_cmd: command to be stored
 * Return: pointer to the new node created
 */
hist *addh(hist *new, char *t_cmd)
{
	hist *n_node;
	hist *tmp;

	n_node = _malloc(sizeof(hist));
	n_node->nxt = NULL;
	n_node->t_cmd = _strdup(t_cmd);
	if (new == NULL)
		new = n_node;
	else
	{
		tmp = new;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = n_node;
	}
	return (n_node);
}
/**
 * my_path - used in making path
 * @path: path to be created
 * @fnm: file to be opened
 * @key: key to be created
 * @env_n: a linked list of env
 * Return: a string
 */
char *my_path(char **path, char *fnm, char *key, env *env_n)
{
	char *amount;

	if (_strstr(key, "/"))
	{
		path = fnm;
		return (fnm);
	}
	amount = env_value(env_n, key);
	*path = _malloc(sizeof(char) * (_strlen(amount) + _strlen(fnm) + 2));
	_memcpy(*path, amount, _strlen(amount) + 1);
	_strcat(*path, "/");
	_strcat(*path, fnm);
	/* I have altered the strcat function, to check if it works */
	return (*path);
}
/**
 * rd_input - reads the history file
 * @env_n: variable that gives the HOME directory
 * @ptr: used to keep what is read
 * Return: 1 or 0.
 */
int rd_input(env *env_n, char **ptr)
{
	int index, byte_read, file;
	static int text = BUFSIZE;
	char *filepath, new_buff;

	filepath = rm_name(env_n, "HOME", BUFSIZE);
	if (filepath == NULL)
	{
		_write("Error: Home not found\n");
		_write("History file not found\n");
		return (1);
	}
	_strcat(filepath, "/.simple_shell_history");
	file = open(filepath, O_RDWR | 0600);
	if (fie > 0)
	{
		index = 0;
		while ((byte_read = read(file, *ptr + index, text - index)) > 0)
		{
			if (byte_read < text - index)
			{
				(*ptr)[byte_read + index] = '\0';
			}
			text *= 2;
			new_buff = _malloc((text) * sizeof(char));
			index += byte_read;
			_memcpy(new_buff, *ptr, text / 2);
			*ptr = new_buff;
		}
		close(file);
		return (1);
	}
	return (0);
}
