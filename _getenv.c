#include "main.h"

/**
 * _getenv - get environment variable
 * @name: name of variable
 * @env: environment
 *
 * Return: environment variable
 */
char *_getenv(const char *name, char **env)
{
	size_t len, i, j;

	len = _strlen(name);

	if (len == 0)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] != env[i][j])
				break;
		}
		if (j == len)
			return (&(env[i][j + 1]));
	}

	return (NULL);
}
