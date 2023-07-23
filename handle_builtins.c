#include "main.h"

/**
 * handle_builtins - handles built-in commands
 * @argv: argument vector
 *
 * Return: 0 if builtin is handled, 1 if command is not a builtin
 */
int handle_builtins(char **argv)
{
	int i;
	command commands[] = {
		{"exit", handle_exit},
		{NULL, NULL}
	};

	for (i = 0; commands[i].name != NULL; i++)
	{
		if (is_equal(argv[0], commands[i].name))
		{
			commands[i].handler(argv);
			return (0);
		}
	}
	return (1);
}
