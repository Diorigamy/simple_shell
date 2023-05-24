#include "shell.h"
/**
 * signh - handles ctrl c
 * sig: signal received
 */
void signh (int sig)
{
	(void) sig;
	wr("\n");
	pinp();
}
