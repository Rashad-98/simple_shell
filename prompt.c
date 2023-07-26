#include "main.h"

/**
 * prompt - prints a prompt
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
}
