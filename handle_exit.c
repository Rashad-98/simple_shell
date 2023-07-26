#include "main.h"
/**
 * handle_exit - exits the program
 * @s_info: structure holding inforamation about current shell process
 */
void handle_exit(shell_info *s_info)
{
	unsigned long int num;
	int argc = s_info->command->argc;
	char **argv = s_info->command->argv;

	if (argv == NULL)
		return;

	if (argv[1] != NULL && is_num(argv[1]))
	{
		num = str_to_int(argv[1]);
		free_argv(argc, argv);
		exit(num);
	}
	else if (argv[1] == NULL)
	{
		free_argv(argc, argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "Error\n", 6);
	}
}
