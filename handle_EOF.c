#include "main.h"

/**
 * handle_EOF - handles ctrl+D input
 * @buff: buffer containing input
 */
void handle_EOF(char *buff)
{
	if (*buff == '\0')
	{
		putchar('\n');
		free(buff);
		exit(0);
	}
}
