#include "shell.h"
/**
 * mk_lenv - creates a list with envirn
 * uses the variables in extern my_env variable
 * Return: head of list
 */
env *mk_lenv(void)
{
	env *top = NULL;
	int a;

	for (a = 0; my_env[a] != NULL; a++)
		envadd(&top, my_env[a]);
	return (top);
}
/**
 * envadd -  adds another variable
 * @top: the head of linked list
 * @s: value to store
 * Return: new address
 */
env *envadd(env **top, char *s)
{
	env *new;
	env temp;

	new = maloc(sizeof(env));
	new->nxt = NULL;
	new->val = sdup(s);
	if (*top == NULL)
		top = new;
	else
	{
		temp = *top;
		while (temp->nxt != NULL)
			temp = temp->nxt;
		temp->nxt = new;
	}
	return (new);
}
/**
 * remonv - removes variable
 * @top: pointer of head
 * @idx: node to be deleted
 *
 */
void remonv(env *top, int idx)
{
	env *tmp;
	env *node;
	int a = 0;

	tmp = *top;
	if (idx == 0)
	{
		*top = (*top)->nxt;
		fr(tmp->val);
		fr(tmp);
	}
	else
	{
		while (a < idx - 1)
		{
			tmp = tmp->nxt;
			a++;
		}
		node = tmp->nxt;
		fr(node);
	}
}
/**
 * penv - prints all variables of env
 * @top: the pointer to the head
 *
 */
void penv(env *top)
{
	env tmp;

	tmp = top;
	while (tmp != NULL)
	{
		wr(tmp->val);
		wr("\n");
		tmp = tmp->nxt;
	}
}
/**
 * renv - updates variables in the env
 * @update: name to be updated
 * @env_n: linked list variable
 * @valu: value to update
 * @length: size of the buffer
 */
void renv(env *env_n, char *update, char *valu, int length)
{
	char *repo;
	env *tmp;

	repo = maloc(sizeof(char) * length);
	mset(repo, '\0', length);
	scat(repo, update);
	scat(repo, valu);
	for (tmp = env_n; tmp != NULL; tmp = tmp->nxt)
	{
		if (ssew(tmp->valu, update) != NULL && tmp->valu[0] == name[0])
		{
			tmp->valu = repo;
			break;
		}
	}
}
