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
	void (*handler)(char **);
} command;
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
struct args_info *get_argv(char *str, ssize_t count);
void free_argv(int argc, char **argv);
char *handle_path(char **file);
char *check_command(char *cmd);
void ch_x(struct args_info *, char **, char **, char *, pid_t);
void handle_EOF(char *buff);
int handle_builtins(char **argv);
int is_equal(char *str1, char *str2);
void handle_exit(char **);
int is_num(char *);
unsigned long int str_to_int(char *);
#endif
