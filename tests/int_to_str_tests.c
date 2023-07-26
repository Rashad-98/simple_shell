#include "main.h"

/**
 * main - tests for int_to_str
 *
 * Return: 0
 */
int main(void)
{
	int n = 333;
	int n2 = 0;
	int n3 = 122334;
	char *str;

	str = int_to_str(n);
	printf("should be 333 and it is %s\n", str);
	free(str);
	str = int_to_str(n2);
	printf("should be 0 and it is %s\n", str);
	free(str);
	str = int_to_str(n3);
	printf("should be 122334 and it is %s\n", str);
	free(str);

	return (0);
}
