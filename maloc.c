#include "shell.h"
/**
 * fr - frees memory and removes address from defer'd free list
 * @add: address to free
 */
void fr(void *add)
{
	freed(add);
	fr(add);
}
/**
 * freed - sets an address to be free'd on exit,
 *removes from list if exists
 * @add: address to set
 */
void freed(void *add)
{
	static sv_add list = {NULL, NULL};
	sv_add *tmp;

	tmp = &list;
	/* If not given signal to free all, and address not already in list, add it */
	if (add != FREE_ADDRESSES && clead(tmp, add))
	{
		while (1)
		{
			if (tmp->add == NULL)
			{
				tmp->add = add;
				return;
			}
			else if (tmp->nxt == NULL)
			{
				addred(tmp, add);
				return;
			}
			tmp = tmp->nxt;
		}
	}
	else if (add == FREE_ADDRESSES)
	{
		fread(list.nxt);
		if (list.add != NULL)
			fr(list.add);
	}
}
/**
 * clead - clear an address from the list
 * @list: addr_list list
 * @add: address to search and clear
 *
 * Return: 0 if address is found and cleared, 1 if no match is found
 */
int clead(sv_add *list, void *add)
{
	while (list != NULL)
	{
		if (list->add == add)
		{
			list->add = NULL;
			return (0);
		}
		list = list->nxt;
	}
	return (1);
}
/**
 * addred - add a node to the sv_add list
 * @list: sv_add list
 * @add: address to add to node
 */
void addred(sv_add *list, void *add)
{
	sv_add *node;

	node = malloc(sizeof(sv_add));
	if (node == NULL)
	{
		rw("Out of Memory, Exiting (._.)\n");
		freed(FREE_ADDRESSES);
		_exit(4);
	}
	node->add = add;
	node->nxt = list->nxt;
	list->nxt = node;
}
/**
 * fread - free the sv_add and all addresses stored
 * @list: the sv_add to free
 */
void fread(sv_add *list)
{
	sv_add *tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->nxt;
		if (tmp->add != NULL)
			fr(tmp->add);
		fr(tmp);
	}
}
