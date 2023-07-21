#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char **get_argv(char *str, ssize_t count);
void free_argv(char **argv);
#endif
