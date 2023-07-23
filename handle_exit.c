#include "main.h"
/**
 * handle_exit - exits the program
 * @argv: argument vector
 */
void handle_exit(char **argv)
{
	unsigned long int num;

	if (argv == NULL)
		return;

	if (argv[1] != NULL && is_num(argv[1]))
	{
		num = str_to_int(argv[1]);
		exit(num);
	}
	else if (argv[1] == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Error\n");
	}
}
