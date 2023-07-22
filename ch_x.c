#include "main.h"
/**
 * ch_x - if inside a child process, executes a command
 * @args: structure holding arguments information
 * @av: arguments to main (entry point)
 * @env: environment
 * @buff: a buffer to free on error
 * @pid: process id -> to check if inside a child
 */
void ch_x(struct args_info *args, char **av, char **env, char *buff, pid_t pid)
{
	char **argv;

	argv = args->argv;
	if (pid == 0)
	{
		execve((const char *)argv[0], (char *const *)argv, (char *const *)env);
		perror(av[0]);
		free(buff);
		free_argv(args->argc, args->argv);
		exit(EXIT_FAILURE);
	}
}

