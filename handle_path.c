#include "main.h"

/**
 * handle_path - finds if a file exists in any of PATH directories
 * @s_info: structure holding shell information
 *
 * Return: full path of file if found, NULL if not found or if an error occured
 */
char *handle_path(shell_info *s_info)
{
	char **argv = s_info->command->argv;

	if ((argv != NULL) && (argv[0] != NULL))
	{
		if (!(*argv[0] == '/' || *argv[0] == '.'))
			return (find_in_path(s_info));
		else
			return (argv[0]);
	}
	return (NULL);
}
