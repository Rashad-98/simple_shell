#include "main.h"

/**
 * handle_EOF - handles ctrl+D input
 * @count: count of characters read
 * @buff: buffer containing input
 * @status: holds exit status
 */
void handle_EOF(ssize_t count, char *buff, int status)
{
	if (count == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			free(buff);
			exit(status);
		}
		write(1, "\n", 1);
		free(buff);
		exit(status);
	}
}
