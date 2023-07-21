#include <stdio.h>
#include "main.h"

/**
 * main - tests for _strlen function
 *
 * Return: 0
 */
int main(void)
{
	size_t length;

	length = _strlen("hello");
	printf("length should be 5 and it is %lu\n", length);

	length = _strlen("\0");
	printf("length should be 0 and it is %lu\n", length);

	length = _strlen("hello world");
	printf("length should be 11 and it is %lu\n", length);

	return (0);
}
