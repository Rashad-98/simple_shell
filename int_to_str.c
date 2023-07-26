#include "main.h"

/**
 * int_to_str - repersents integer as a string
 * @num: number
 * Return: string
 */
char *int_to_str(int num)
{
	int i, num_cpy, len = 0;
	char *str;

	if (num == 0)
	{
		str = malloc(sizeof(*str) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	num_cpy = num;
	for (i = 0; num_cpy != 0; i++)
	{
		num_cpy /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	for (i = len - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + 48;
		num /= 10;
	}
	str[len] = '\0';

	return (str);
}
