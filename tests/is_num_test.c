#include "main.h"

/**
 * main - tests for is_num function
 *
 * Return: 0 always
 */
int main(void)
{
	char str1[] = "hello";
	char str2[] = "12342";
	char str3[] = " ";
	char str4[] = "";
	char str5[] = "23423.242342";
	char str6[] = "243hello";
	char str7[] = "3";

	printf("it should be 0 and it is --> %d\n", is_num(str1));
	printf("it should be 1 and it is --> %d\n", is_num(str2));
	printf("it should be 0 and it is --> %d\n", is_num(str3));
	printf("it should be 0 and it is --> %d\n", is_num(str4));
	printf("it should be 0 and it is --> %d\n", is_num(str5));
	printf("it should be 0 and it is --> %d\n", is_num(str6));
	printf("it should be 1 and it is --> %d\n", is_num(str7));

	return (0);
}
