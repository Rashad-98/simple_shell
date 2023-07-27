#include "main.h"

/**
 * find_in_path - searches PATH for a program to execute
 * @s_info: structure holding current shell process information
 *
 * Return: full path of program if found, and NULL otherwise
 */
char *find_in_path(shell_info *s_info)
{
	char *dir, *path, *full_path, *path_cpy;
	int arg_len, dir_len;
	struct stat statbuff;
	char **argv = s_info->command->argv;

	arg_len = _strlen(*argv);
	path = _getenv("PATH", s_info->env);
	if (path == NULL || *path == '\0')
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path_cpy, path);
	dir = strtok(path_cpy, ":");
	if (dir == NULL)
	{
		free(path_cpy);
		return (NULL);
	}
	while (dir != NULL)
	{
		dir_len = _strlen(dir);
		full_path = malloc(sizeof(*full_path) * (dir_len + arg_len + 2));
		_strcpy(full_path, dir);
		full_path[dir_len] = '/';
		_strcpy(full_path + dir_len + 1, *argv);
		if (stat(full_path, &statbuff) == 0)
		{
			free(path_cpy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
		free(full_path);
	}
	free(path_cpy);
	return (NULL);
}
