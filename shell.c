#include "main.h"

/**
 * main - UNIX command line interpreter
 * @ac: arguments count
 * @av: argumnets vector
 * @env: environmnet vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	char *buff, **argv;
	size_t n;
	ssize_t count;
	pid_t pid;
	int wstatus;
	shell_info s_info;

	s_info.argc = ac;
	s_info.argv = av;
	s_info.env = env;

	while (1)
	{
		buff = NULL;
		n = 0;
		if (isatty(STDIN_FILENO))
			printf("$ ");
		count = getline(&buff, &n, stdin);
		buff = check_command(buff);
		if (buff == NULL)
			continue;
		handle_EOF(buff);
		buff[count - 1] = '\0';
		s_info.command = get_argv(buff, count);
		free(buff);
		argv = s_info.command->argv;
		if (handle_builtins(&s_info) == 0)
		{
			free_argv(s_info.command->argc, argv);
			continue;
		}
		argv[0] = handle_path(argv);
		if (argv[0] == NULL)
		{
			errno = 2;
			perror(av[0]);
		}
		else
		{
			pid = fork();
			ch_x(&s_info, pid);
			wait(&wstatus);
		}
		free_argv(s_info.command->argc, argv);
		if (!isatty(STDIN_FILENO))
			return (0);
	}
	return (0);
}
