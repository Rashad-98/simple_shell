#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/**
 * struct command_info - structure that holds information about entered command
 * @argc: arguments count
 * @argv: arguments vector
 */
typedef struct command_info
{
	int argc;
	char **argv;
} command_info;

/**
 * struct shell_info - structure that holds information about shell
 * in the current process
 * @argc: arguments count
 * @argv: arguments vector
 * @command: pointer to struct command_info
 */
typedef struct shell_info
{
	int argc;
	char **argv;
	char **env;
	command_info *command;
} shell_info;

/**
 * struct args_info - structure that holds arguments and their count
 * @argc: arguments count
 * @argv: arguments vector
 */
struct args_info
{
	int argc;
	char **argv;
};

/**
 * struct command - structure that holds builtin command name and handler
 * @name: name of the command
 * @handler: function that handles the command
 */
typedef struct command
{
	char *name;
	void (*handler)(shell_info *);
} command;
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
command_info *get_argv(char *str, ssize_t count);
void free_argv(int argc, char **argv);
char *handle_path(char **file);
char *check_command(char *cmd);
void ch_x(shell_info *, pid_t);
void handle_EOF(char *buff);
int handle_builtins(shell_info *);
int is_equal(char *str1, char *str2);
void handle_exit(shell_info *);
int is_num(char *);
unsigned long int str_to_int(char *);
#endif
