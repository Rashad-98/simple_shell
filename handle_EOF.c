#include "main.h"

/**
 * handle_EOF - handles ctrl+D input
 * @buff: buffer containing input
 */
void handle_EOF(char *buff)
{
	if (*buff == '\0')
	{
		write(1, "\n", 1);
		free(buff);
		exit(0);
	}
}
