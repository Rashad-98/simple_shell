#include "main.h"

/**
 * handle_env - handles the builtin env
 * @s_info: structure holding shell information
 */
void handle_env(shell_info *s_info)
{
	int i;

	i = 0;
	while (s_info->env[i] != NULL)
	{
		write(1, s_info->env[i], _strlen(s_info->env[i]));
		write(1, "\n", 1);
		i++;
	}
}
