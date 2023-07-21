#include "main.h"

/**
 * main - test for _memcpy function
 *
 * Return: 0 always
 */
int main(void)
{
	char str1[] = "hello world!";
	char str2[13];
	char str3[] = "";
	char str4[1];

	_strcpy(str2, str1);
	printf("this is the source string: %s\n", str1);
	printf("this is the destination string: %s\n", str2);

	_strcpy(str4, str3);
	printf("this is the source string: %s\n", str3);
	printf("this is the destination string: %s\n", str4);

	return (0);
}
