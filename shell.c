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
	char *buff;
	size_t n;
	ssize_t count;
	pid_t pid;
	int wstatus;
	char **argv;

	while (1)
	{
		buff = NULL;
		n = 0;
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		count = getline(&buff, &n, stdin);
		if (*buff == '\0')
		{
			putchar('\n');
			return (0);
		}
		buff[count - 1] = '\0';
		argv = get_argv(buff, count);
		pid = fork();
		if (pid == 0)
		{
			execve((const char *)argv[0], (char *const *)argv, (char *const *)env);
			perror(av[0]);
			free(buff);
			free_argv(argv);
			exit(EXIT_FAILURE);
		}
		wait(&wstatus);
		free_argv(argv);
		if (!isatty(STDIN_FILENO))
			return (0);
		free(buff);
	}
	return (0);
}
