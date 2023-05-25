#include "shell.h"
/**
 * _free - frees memory
 * @address: address to be freed
 */
void _free(void *address)
{
	defer_free(address);
	free(address);
}
/**
 * defer_free - used to set address to be freed
 * @address: address to set
 */
void defer_free(void *address)
{
	addr_list *tmp;
	static addr_list list = {NULL, NULL};

	tmp = &list;
	if (address != FREE_ADDRESSES && clear_addr_list_node(tmp, address))
	{
		while (1)
		{
			if (tmp->address == NULL)
			{
				tmp->address = address;
				return;
			}
			else if (tmp->next == NULL)
			{
				add_addr_list_node(tmp, address);
				return;
			}
			tmp = tmp->next;
		}
	}
	else if (address == FREE_ADDRESSES)
	{
		free_addr_list(list.next);
		if (list.address != NULL)
			free(list.address);
	}
}
/**
 * add_addr_list_node - adds a node to the list
 * @list: addr_list list
 * @address: address to add to node
 */
void add_addr_list_node(addr_list *list, void *address)
{
	addr_list *node;

	node = malloc(sizeof(addr_list));
	if (node == NULL)
	{
		_write("Out of Memory, Exiting (._.)\n");
		defer_free(FREE_ADDRESSES);
		_exit(4);
	}
	node->address = address;
	node->next = list->next;
	list->next = node;
}
/**
 * free_addr_list - free the stored addresses
 * @list: the list to be freed
 */
void free_addr_list(addr_list *list)
{
	addr_list *tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		if (tmp->address != NULL)
			free(tmp->address);
		free(tmp);
	}
}
/**
 * clear_addr_list_node - clear an address
 * @list: addr_list list
 * @address: address to be cleared
 * Return: 0 or 1
 */
int clear_addr_list_node(addr_list *list, void *address)
{
	while (list != NULL)
	{
		if (list->address == address)
		{
			list->address = NULL;
			return (0);
		}
		list = list->next;
	}
	return (1);
}
