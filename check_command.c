#include "main.h"

/**
 * check_command - checks the validity of a command
 * @cmd: command to be checked
 *
 * Return: pointer to the command, or NULL for unvalid commands
 */
char *check_command(char *cmd)
{
	int i;

	if (cmd == NULL || *cmd == '\0')
		return (cmd);
	if (*cmd == '\n')
	{
		free(cmd);
		return (NULL);
	}
	else if (*cmd == ' ')
	{
		for (i = 1; *(cmd + i) != '\0'; i++)
		{
			if (*(cmd + i) != ' ' && *(cmd + i) != '\n')
				return (cmd);
		}
		free(cmd);
		return (NULL);
	}
	else
	{
		return (cmd);
	}
}
