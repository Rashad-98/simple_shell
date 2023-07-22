#include "main.h"

/**
 * free_argv - function that frees argv
 * @argv: argument vector
 * @argc: arguments count
 */
void free_argv(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		free(*(argv + i));
	}
	free(argv);
}
