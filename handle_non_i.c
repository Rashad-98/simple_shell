#include "main.h"

/**
 * handle_non_i - handles non interactive mode
 */
void handle_non_i(void)
{
	if (!isatty(STDIN_FILENO))
		exit(EXIT_SUCCESS);
}
