#include "main.h"

/**
 * free_argv - function that frees argv
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	int i;

	for (i = 0; *(argv + i) != NULL; i++)
	{
		free(*(argv + i));
	}
	free(argv);
}
