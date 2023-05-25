#include "shell.h"
/**
 * signal_handler - handles the (cancel) ctrl-c signal
 * @signo: signal received
 */

void signal_handler(int signo)
{
	(void) signo;
	_write("\n");
	print_cmdline();
}
