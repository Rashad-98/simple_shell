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
	struct args_info *args;

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
		args = get_argv(buff, count);
		argv = args->argv;
		argv[0] = handle_path(argv);
		if (argv[0] == NULL)
		{
			errno = 2;
			perror(av[0]);
		}
		else
		{
			pid = fork();
			ch_x(args, av, env, buff, pid);
			wait(&wstatus);
		}
		free_argv(args->argc, argv);
		if (!isatty(STDIN_FILENO))
			return (0);
		free(buff);
	}
	return (0);
}
