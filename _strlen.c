#include "main.h"

/**
 * _strlen - get the length of a string
 * @str: string
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*(str + len) != '\0')
		len++;

	return (len);
}
