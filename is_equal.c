#include "main.h"

/**
 * is_equal - checks if two strings are the same
 * @str1: first string
 * @str2: second string
 *
 * Return: 1 if they are the same, 0 otherwise
 */
int is_equal(char *str1, char *str2)
{
	unsigned long int i, len1, len2;

	len1 = 0;
	len2 = 0;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	if (len1 != len2)
		return (0);
	i = 0;
	while ((*(str1 + i) == *(str2 + i)) && (*(str1 + i) != '\0'))
		i++;
	if (i == len1)
		return (1);
	else
		return (0);
}
