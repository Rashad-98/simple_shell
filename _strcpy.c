#include "main.h"

/**
 * _strcpy - copies string of characters from source to destination
 * @dest: destination
 * @src: source
 *
 * Return: destination (pointer to char)
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';

	return (dest);
}
