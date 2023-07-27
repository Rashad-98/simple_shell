#include "main.h"
/**
 * ch_x - if inside a child process, executes a command
 * @s_info: structure hoding information aboud the current shell process
 * @pid: process id -> to check if inside a child
 */
void ch_x(shell_info *s_info, pid_t pid)
{
	char **argv, **env;
	int argc;

	argv = s_info->command->argv;
	argc = s_info->command->argc;
	env = s_info->env;
	if (pid == 0)
	{
		execve((const char *)argv[0], (char *const *)argv, (char *const *)env);
		errno = 2;
		perror(s_info->argv[0]);
		free_argv(argc, argv);
		s_info->status = errno;
		exit(errno);
	}
}

