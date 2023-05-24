#include "shell.h"
/**
 * _hist - builtin command _hist, mimics builtin history
 * @arg: argrument list of input
 * @envp: environemental variable list
 * @lenp: lenp to direct which function to execute
 * Return: Always 0
 */
int _hist(char **arg, env *envp, int lenp)
{
	static hist history = {NULL, NULL};

	if (lenp == 0)
		mk_hist(&history, envp);
	else if (lenp == 1)
		addh(&history, arg[0]);
	else if (lenp == 2)
		wrhst(envp, &history);
	else
	{
		if (arg[1] != NULL)
		{
			rw("Error: no such command\n");
			return (2);
		}
		pt_hist1(&history);
	}
	return (0);
}

/**
 * pt_hist1 - prints out the history with pos
 * @history: history linked list
 */

void pt_hist1(hist *history)
{
	int i, count;
	char *srn;
	hist *temp, *temp2;

	history = history->nxt;
	for (count = 0, temp = history; temp != NULL; temp = temp->nxt, count++)
		;
	history = history->nxt;
	for (i = 0, temp2 = history; temp2 != NULL; temp2 = temp2->nxt, i++)
	{
		srn = i2s(i, 2);
		rw(" ");
		rw(srn);
		rw(" ");
		rw(temp2->cmd);
		rw("\n");
	}
}
/**
 * hisht - builtin help printout for history
 * Return: Always 0
 */
int hisht(void)
{
	rw("history usage: history\n    ");
	rw("Display the history list with line numbers.\n");
	return (0);
}

/**
 * i2s - interger to string converter
 * @num: number to convert
 * @lenp: lenp to determine how to deal with 0
 * Return: a string for the number
 */

char *i2s(int num, int lenp)
{
	char *srn;
	int pos, exp, i, temx;

	srn = maloc(sizeof(char) * BUFSIZE);
	maloc(srn, '\0', BUFSIZE);
	exp = 1000000000;
	pos = 0;
	if (num != 0)
	{
		while ((num / exp) == 0)
			exp /= 10;
		temx = exp;
		while (temx < 1000 && lenp == 2)
		{
			srn[pos++] = 0 + '0';
			temx *= 10;
		}
		while (exp >= 1)
		{
			srn[pos++] = (num / exp) + '0';
			num %= exp;
			exp /= 10;
		}
	}
	else
	{
		if (lenp == 2)
		{
			for (i = 0; i < 4; i++)
				srn[i] = 0 + '0';
		}
		else
			srn[0] = 0 + '0';
	}
	return (srn);
}
