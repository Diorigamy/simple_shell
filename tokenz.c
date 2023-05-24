#include "shell.h"
/**
 * tokenize_buf - tokenize buffer by inputting NULLs and filling **av
 * @b: The buffer with the command string
 * @av: Pointer to the command argument vector
 * Description: This function accepts a string such as 'ls -l' and changes
 *              it to 'ls\0-l'. It puts pointers to 'ls' and '-l' into *av
 */
void tok_cmd(ctrl_buf *pt, char ***av)
{
	int i, ap, flag, spc;

	avint(ptr->ptr + ptr->curr, av);

	/* Build the argument vector from the given buffer */
	for (i = ptr->curr, ap = 0, flag = 1; !cmend(ptr->ptr[i]); i++)
	{
		spc = chesp(pt->buf[i]);
		if (flag && !spc)
		{
			(*av)[ap++] = ptr->ptr + i;
			flag = 0;
		}
		if (spc)
		{
			ptr->ptr[i] = '\0';
			flag = 1;
		}
	}
	(*av)[ap] = NULL;
	/* If we end because of comments */
	if (ptr->ptr[i] == '#')
		while (ptr->ptr[i] != '\n' && ptr->ptr[i] != '\0')
			i++;
	/* If we ended because of newline, we MAY have more content */
	if (ptr->ptr[i] == '\n' && ptr->ptr[i + 1] != '\0')
		ptr->ptr[i] = ';';
	else if (ptr->ptr[i] == '\n')
		ptr->ptr[i] = '\0';
	/* If we ended because of flow control commands, */
	/* increment the buffer point and add a null before the character */
	if (ptr->ptr[i] == ';' || ptr->ptr[i] == '|' || ptr->ptr[i] == '&')
	{
		ptr->curr += i - ptr->curr;
		nadd(ptr->ptr + ptr->curr);
		ptr->curr++;
	}
	else
		ptr->curr = 0;
}
/**
 * avint - resize av if needed
 * @buf: The buffer with the command string
 * @av: Command argument vector
 */
void avint(char *ptr, char ***av)
{
	int c, i, flag, spc;

	for (c = 0, flag = 1; !cmend(*buf); buf++)
	{
		spc = chesp(*buf);
		if (flag && !spc)
			flag = 0, c++;
		else if (spc)
			flag = 1;
	}

	if (*av != NULL)
	{
		for (i = 0; (*av)[i] != NULL; i++)
			;
		if (c > i)
		{
			fr(*av);
			*av = maloc(sizeof(char *) * (c + 1));
		}
		return;
	}
	else
		*av = maloc(sizeof(char *) * (c + 1));
}
/**
 * nadd - Add a null before the multi-command operator
 * @buf: buffer structure to add null into
 */
void nadd(char *ptr)
{
	int i;

	for (i = 0; ptr[i] != '\0'; i++)
		;
	i++;
	for ( ; i > 0; i--)
		ptr[i + 1] = ptr[i];
	ptr[i + 1] = ptr[i];
	ptr[i] = '\0';
}
/**
 * chesp - Boolean true for false for spc
 * @c: char to evalute.
 *
 * Return: 1 if spc, 0 if not
 */
int chesp(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}
/**
 * cmend - Boolean true or false if char signals end of command
 * @c: char to evaluate
 *
 * Return: 1 if end of command, 0 if not
 */
int cmend(char c)
{
	if (c == '\0' || c == '\n' || c == '|' || c == '&' || c == ';' || c == '#')
		return (1);
	return (0);
}
