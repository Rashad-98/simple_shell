#include "main.h"

/**
 * get_argv - take a space-separated string and converts it to arguments vector
 * @str: string
 * @count: number of characters in the string including
 * the null character at the end
 *
 * Return: argv (pointer to pointer to char)
 */
command_info *get_argv(char *str, ssize_t count)
{
	char *buff_cpy;
	size_t len;
	char *token;
	int ac, i;
	char **av;
	static command_info c_info;

	ac = 0;
	buff_cpy = malloc(sizeof(*buff_cpy) * (count));
	_strcpy(buff_cpy, str);
	token = strtok(str, "\n ");
	while (token != NULL)
	{
		ac++;
		token = strtok(NULL, "\n ");
	}
	av = malloc(sizeof(*av) * (ac + 1));
	av[ac] = NULL;
	i = 0;
	token = strtok(buff_cpy, "\n ");
	while (token != NULL)
	{
		len = _strlen(token);
		av[i] = malloc(sizeof(**av) * (len + 1));
		_strcpy(av[i], token);
		token = strtok(NULL, "\n ");
		i++;
	}
	free(buff_cpy);

	c_info.argc = ac;
	c_info.argv = av;
	return (&c_info);
}
