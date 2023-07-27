#include "main.h"

/**
 * handle_fork - handles the creation of child process
 * @s_info: structure holding shell information
 */
void handle_fork(shell_info *s_info)
{
	pid_t pid;
	int wstatus = s_info->status;

	pid = fork();
	ch_x(s_info, pid);
	wait(&wstatus);
	if (WIFEXITED(wstatus) > 0)
		s_info->status = WEXITSTATUS(wstatus);
}
