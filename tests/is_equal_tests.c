#include "main.h"

/**
 * main - tests for is_equal function
 *
 * Return: 0 always
 */
int main(void)
{
	char str1[] = "hello world!";
	char str2[] = "hello world!";
	char str3[] = " ";
	char str4[] = " ";
	char str5[] = "hello";
	char str6[] = "\0";
	char str7[] = "\0";

	printf("should be 1 and it is --> %d\n", is_equal(str1, str2));
	printf("should be 1 and it is --> %d\n", is_equal(str3, str4));
	printf("should be 0 and it is --> %d\n", is_equal(str1, str5));
	printf("should be 1 and it is --> %d\n", is_equal(str6, str7));
	printf("should be 0 and it is --> %d\n", is_equal(str1, str7));

	return (0);
}
