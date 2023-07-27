#include "main.h"

/**
 * main - UNIX command line interpreter
 * @ac: arguments count
 * @av: argumnets vector
 * @env: environmnet vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av, char **env)
{
	char *buff;
	size_t n;
	ssize_t count;
	shell_info s_info;

	s_info.argc = ac;
	s_info.argv = av;
	s_info.env = env;
	s_info.status = 0;
	while (1)
	{
		buff = NULL;
		n = 0;
		prompt();
		count = getline(&buff, &n, stdin);
		handle_EOF(count, buff, s_info.status);
		buff = check_command(buff);
		if (buff == NULL)
			continue;
		buff[count - 1] = '\0';
		s_info.command = get_argv(buff, count);
		if (handle_builtins(&s_info) == 0)
			continue;
		s_info.command->argv[0] = handle_path(&s_info);
		if (s_info.command->argv[0] == NULL)
		{
			errno = 2;
			perror(av[0]);
		}
		else
		{
			handle_fork(&s_info);
		}
		free_argv(s_info.command->argc, s_info.command->argv);
	}
	return (s_info.status);
}
