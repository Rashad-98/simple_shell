#include "main.h"

/**
 * handle_builtins - handles built-in commands
 * @s_info: structure holding infromation aboud current shell process
 *
 * Return: 0 if builtin is handled, 1 if command is not a builtin
 */
int handle_builtins(shell_info *s_info)
{
	int i;
	command commands[] = {
		{"exit", handle_exit},
		{NULL, NULL}
	};
	char **argv = s_info->command->argv;

	for (i = 0; commands[i].name != NULL; i++)
	{
		if (is_equal(argv[0], commands[i].name))
		{
			commands[i].handler(s_info);
			free_argv(s_info->argc, s_info->argv);
			return (0);
		}
	}
	return (1);
}
