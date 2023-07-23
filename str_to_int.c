#include "main.h"

/**
 * str_to_int - converts string (number) to a positive integer (number)
 * and ommits overflowing numbers
 * @str: string to be converted
 *
 * Return: integer number
 */
unsigned long int str_to_int(char *str)
{
	long int i, x, len, num;

	x = 1;
	num = 0;
	len = _strlen((const char *)str);
	for (i = len - 1; i >= 0; i--)
	{
		if ((num + (*(str + i) - 48) * x) <= INT_MAX)
			num = num + (*(str + i) - 48) * x;
		else
			break;
		if (i == 0)
			break;
		x *= 10;
	}
	return (num);
}
