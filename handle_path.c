#include "main.h"

/**
 * handle_path - finds if a file exists in any of PATH directories
 * @argv: arguments vector
 *
 * Return: full path of file if found, NULL if not found or if an error occured
 */
char *handle_path(char **argv)
{
	char *dir, *path, *full_path, *path_cpy;
	int arg_len, dir_len;
	struct stat statbuff;

	if ((argv != NULL) && (argv[0] != NULL))
	{
		if (!(*argv[0] == '/' || *argv[0] == '.'))
		{
			arg_len = _strlen(*argv);
			path = getenv("PATH");
			path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
			_strcpy(path_cpy, path);
			dir = strtok(path_cpy, ":");
			if (dir == NULL)
				return (NULL);
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
					free(*argv);
					return (full_path);
				}
				dir = strtok(NULL, ":");
				free(full_path);
			}
			free(path_cpy);
			free(*argv);
			return (NULL);
		}
		else
			return (argv[0]);
	}
	else
		return (NULL);
}
