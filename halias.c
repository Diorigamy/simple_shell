#include "shell.h"
/**
 * halias - builtin help printout for alias
 * Return: Always 0
 */
int halias(void)
{
	rw("alias usage: alias [KEY][=VALUE]\n    Allows aliases to be set for");
	rw(" quicker shell usage.\nAlias with no KEY VALUE prints a list of ");
	rw("aliases.\nAlias with KEY prints the alias match for that key.\n");
	rw("Alias with KEY VALUE sets or overwrites the KEY with new VALUE.\n");
	return (0);
}
