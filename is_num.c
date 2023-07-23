#include "main.h"

/**
 * is_num - check if a string is a valid number
 * @str: string to be checked
 *
 * Return: 1 str is valid number, 0 otherwise
 */
int is_num(char *str)
{
	unsigned long int i;

	if (*str == '\0')
		return (0);

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (!(*(str + i) >= 48 && *(str + i) <= 57))
			return (0);
	}
	return (1);
}
